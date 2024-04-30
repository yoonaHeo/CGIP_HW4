#include "transformation.h"
#include "scene.h"
#include "light.h"

#include <glm/glm.hpp>

using namespace glm;
using namespace std;

#define Nx 512
#define Ny 512

Transformation transformation;
Scene scene;
Point_light point_light;
Ambient_light ambient_light;
Camera camera;

int vertices_num = scene.get_num_vertices();
int triangles_num = scene.get_num_triangles();
int* index_buffer = scene.get_index_buffer();
vec3* vertices = scene.get_vertices();

class Shader {
public:
    vec3 sphere_center = vec3(0, 0, -7);

    vec3 ka = vec3(0, 1, 0);
    vec3 kd = vec3(0, 0.5, 0);
    vec3 ks = vec3(0.5, 0.5, 0.5);
    int p = 32;
    
    float gamma_val = 2.2f;

    vec3 calc_triangle_center(vec3 a, vec3 b, vec3 c) {
        float center_x = (a.x + b.x + c.x) / 3;
        float center_y = (a.y + b.y + c.y) / 3;
        float center_z = (a.z + b.z + c.z) / 3;

        return vec3(center_x, center_y, center_z);
    }

    vec3 calc_triangle_normal(vec3 a, vec3 b, vec3 c) {
        // vec3 normal = calc_triangle_center(a, b, c) - sphere_center;
        vec3 normal = cross(b - a, c - a);

        return normalize(normal);
    }

    vec3 calc_vertex_normal(vec3 point) {
        // normal of each vertex
        vec3 n = normalize(point - sphere_center);

        return n;
    }

    float gamma_correction(float color, float gamma_val) {
        return pow(color, 1 / gamma_val);
    }
};

Shader shader;

class Unshaded {
    unsigned char* image_buffer = NULL;
    unsigned char* depth_buffer = nullptr;
public:
    Unshaded() {}

    unsigned char* get_image() {
        return image_buffer;
    }

    void unshaded() {
        image_buffer = new unsigned char[Nx * Ny * 3] ();
        for(int y = 0; y < Ny; y++) {
            for (int x = 0; x < Nx; x++) {
                depth_buffer[y * Nx + x] = -FLT_MAX;
            }
        }

        scene.create_scene();

        vertices_num = scene.get_num_vertices();
        triangles_num = scene.get_num_triangles();
        index_buffer = scene.get_index_buffer();
        vertices = scene.get_vertices();

        // create identical mtx
        mat4 mtx = (mat4(1, 0, 0, 0,
                         0, 1, 0, 0,
                         0, 0, 1, 0,
                         0, 0, 0, 1));

        
        // transformation pipeline
        mtx = transformation.transformation_pipeline(mtx, camera);

        for (int i = 0; i < vertices_num; i++) {
            // get vertices from vertices array
            vec4 vertex = vec4(vertices[i].x, vertices[i].y, vertices[i].z, 1);
            
            // multiply the transformation matrix with the vertex
            vertex = transformation.multipl_mtx_vec(mtx, vertex);

            // normalize vertex values
            vertex.x = vertex.x / vertex.w;
            vertex.y = vertex.y / vertex.w;
            vertex.z = vertex.z / vertex.w;
            vertex.w = vertex.w / vertex.w;

            // put normalized values back to the vertices array
            vertices[i].x = vertex.x;
            vertices[i].y = vertex.y;
            vertices[i].z = vertex.z;
        }

        for (int i = 0; i < triangles_num; i++) {
            // index of the vertices of the triangle
            int k0 = index_buffer[3 * i];
            int k1 = index_buffer[3 * i + 1];
            int k2 = index_buffer[3 * i + 2];

            // get the vertices of the triangle
            vec3 a = vec3(vertices[k0]);
            vec3 b = vec3(vertices[k1]);
            vec3 c = vec3(vertices[k2]);

            // get bounding box of the triangle
            int xmin = std::min(std::min(a.x, b.x), c.x);
            int xmax = std::max(std::max(a.x, b.x), c.x);
            int ymin = std::min(std::min(a.y, b.y), c.y);
            int ymax = std::max(std::max(a.y, b.y), c.y);

            // starting point of each beta and gamma of barycentric coordinates
            float beta = ((a.y - c.y) * xmin + (c.x - a.x) * ymin + a.x * c.y - c.x * a.y) / ((a.y - c.y) * b.x + (c.x - a.x) * b.y + a.x * c.y - c.x * a.y);
            float gamma = ((a.y - b.y) * xmin + (b.x - a.x) * ymin + a.x * b.y - b.x * a.y) / ((a.y - b.y) * c.x + (b.x - a.x) * c.y + a.x * b.y - b.x * a.y);

            // increasing value of beta and gamma in each axis
            float beta_x = (a.y - c.y) / ((a.y - c.y) * b.x + (c.x - a.x) * b.y + a.x * c.y - c.x * a.y);
            float beta_y = (c.x - a.x) / ((a.y - c.y) * b.x + (c.x - a.x) * b.y + a.x * c.y - c.x * a.y);

            float gamma_x = (a.y - b.y) / ((a.y - b.y) * c.x + (b.x - a.x) * c.y + a.x * b.y - b.x * a.y);
            float gamma_y = (b.x - a.x) / ((a.y - b.y) * c.x + (b.x - a.x) * c.y + a.x * b.y - b.x * a.y);

            int n = (xmax - xmin) + 1;

            for (int y = ymin; y <= ymax; y++) {
                for (int x = xmin; x <= xmax; x++) {
                    if(beta > 0 && gamma > 0 && beta + gamma < 1) {
                        // if beta and gamma are positive and their sum is less than 1, then the pixel is inside the triangle
                        int idx = (y * Nx + x) * 3;
                        int depth_idx = y * Nx + x;

                        // if beta and gamma are positive and their sum is less than 1, then the pixel is inside the triangle
                        // calculate the depth of the pixel
                        float depth = (1 - beta - gamma) * a.z + beta * b.z + gamma * c.z;

                        // if (depth >= depth_buffer[depth_idx]) {
                            // if the depth of the pixel is less than the depth of the pixel in the depth buffer, then update the depth buffer
                            // if depth of the pixel is minimum value, then the pixel is visible
                            // get minimum depth
                            // depth_buffer[depth_idx] = depth;

                            // set each pixel of image buffer
                            image_buffer[idx] = 255;
                            image_buffer[idx + 1] = 255;
                            image_buffer[idx + 2] = 255;
                        // }
                    }
                    beta += beta_x;
                    gamma += gamma_x;
                }
                beta += beta_y - n * beta_x;
                gamma += gamma_y - n * gamma_x;
            }
        }
    }
};

class Flat_shading {
    vec3 color = vec3(0, 0, 0);
    vec3 centroid = vec3(0, 0, 0);

    unsigned char* image_buffer = NULL;
    float depth_buffer[Nx * Ny];

public:
    Flat_shading() {}

    unsigned char* get_image() {
        return image_buffer;
    }

    void flat_shading() {
        image_buffer = new unsigned char[Nx * Ny * 3] ();
        for(int y = 0; y < Ny; y++) {
            for (int x = 0; x < Nx; x++) {
                depth_buffer[y * Nx + x] = -FLT_MAX;
            }
        }

        scene.create_scene();

        vertices_num = scene.get_num_vertices();
        triangles_num = scene.get_num_triangles();
        index_buffer = scene.get_index_buffer();
        vertices = scene.get_vertices();

        // create identical mtx
        mat4 mtx = (mat4(1, 0, 0, 0,
                         0, 1, 0, 0,
                         0, 0, 1, 0,
                         0, 0, 0, 1));
    
        for (int i = 0; i < triangles_num; i++) {
            // index of the vertices of the triangle
            int k0 = index_buffer[3 * i];
            int k1 = index_buffer[3 * i + 1];
            int k2 = index_buffer[3 * i + 2];

            // get the vertices of the triangle
            vec3 a = vertices[k0];
            vec3 b = vertices[k1];
            vec3 c = vertices[k2];
            
            mat4 cam_mtx = transformation.until_cam_pipeline(mtx, camera);

            // get position of vertices in camera space
            a = transformation.normalize_to_vec3(transformation.multipl_mtx_vec(cam_mtx, vec4(a, 1)));
            b = transformation.normalize_to_vec3(transformation.multipl_mtx_vec(cam_mtx, vec4(b, 1)));
            c = transformation.normalize_to_vec3(transformation.multipl_mtx_vec(cam_mtx, vec4(c, 1)));

            // L = La + Ld + Ls = ka * Ia + kd * I * max(0, n dot l) + ks * I * max(0, n dot h)^p
            float ip = point_light.intensity;
            vec3 pos = point_light.position;

            vec3 origin = camera.eye_point;

            // calculate the centroid of the triangle
            centroid = shader.calc_triangle_center(a, b, c);

            // from light source to point
            vec3 l = normalize(pos - centroid);    // direction of light from light source
            vec3 normal = shader.calc_triangle_normal(a, b, c);     // calculate the normal of the triangle
            vec3 v = normalize(origin - centroid);
            // half vector of v and l
            vec3 h = normalize(v + l);

            // calculate the color of the triangle centroid
            color.x = shader.ka.x * ambient_light.ia + shader.kd.x * ip * std::max(0.0f, dot(normal, l)) + shader.ks.x * ip * pow(std::max(0.0f, dot(normal, h)), shader.p);
            color.y = shader.ka.y * ambient_light.ia + shader.kd.y * ip * std::max(0.0f, dot(normal, l)) + shader.ks.y * ip * pow(std::max(0.0f, dot(normal, h)), shader.p);
            color.z = shader.ka.z * ambient_light.ia + shader.kd.z * ip * std::max(0.0f, dot(normal, l)) + shader.ks.z * ip * pow(std::max(0.0f, dot(normal, h)), shader.p);
            
            color.x = (color.x) > 1 ? 1 : color.x;
            color.y = (color.y) > 1 ? 1 : color.y;
            color.z = (color.z) > 1 ? 1 : color.z;

            color.x = shader.gamma_correction(color.x, shader.gamma_val);
            color.y = shader.gamma_correction(color.y, shader.gamma_val);
            color.z = shader.gamma_correction(color.z, shader.gamma_val);

            // after camera = projection * viewport
            mat4 temp_mtx = transformation.after_cam_pipeline(mtx);

            // get position of vertices in viewport space
            a = transformation.normalize_to_vec3(transformation.multipl_mtx_vec(temp_mtx, vec4(a, 1)));
            b = transformation.normalize_to_vec3(transformation.multipl_mtx_vec(temp_mtx, vec4(b, 1)));
            c = transformation.normalize_to_vec3(transformation.multipl_mtx_vec(temp_mtx, vec4(c, 1)));

            // get bounding box of the triangle
            int xmin = std::min(std::min(a.x, b.x), c.x);
            int xmax = std::max(std::max(a.x, b.x), c.x);
            int ymin = std::min(std::min(a.y, b.y), c.y);
            int ymax = std::max(std::max(a.y, b.y), c.y);

            // starting point of each beta and gamma of barycentric coordinates
            float beta = ((a.y - c.y) * xmin + (c.x - a.x) * ymin + a.x * c.y - c.x * a.y) / ((a.y - c.y) * b.x + (c.x - a.x) * b.y + a.x * c.y - c.x * a.y);
            float gamma = ((a.y - b.y) * xmin + (b.x - a.x) * ymin + a.x * b.y - b.x * a.y) / ((a.y - b.y) * c.x + (b.x - a.x) * c.y + a.x * b.y - b.x * a.y);

            // increasing value of beta and gamma in each axis
            float beta_x = (a.y - c.y) / ((a.y - c.y) * b.x + (c.x - a.x) * b.y + a.x * c.y - c.x * a.y);
            float beta_y = (c.x - a.x) / ((a.y - c.y) * b.x + (c.x - a.x) * b.y + a.x * c.y - c.x * a.y);

            float gamma_x = (a.y - b.y) / ((a.y - b.y) * c.x + (b.x - a.x) * c.y + a.x * b.y - b.x * a.y);
            float gamma_y = (b.x - a.x) / ((a.y - b.y) * c.x + (b.x - a.x) * c.y + a.x * b.y - b.x * a.y);

            int n = (xmax - xmin) + 1;

            // set to color of pixels in triangle
            for (int y = ymin; y <= ymax; y++) {
                for (int x = xmin; x <= xmax; x++) {
                    if (beta > 0 && gamma > 0 && beta + gamma < 1) {
                        // if beta and gamma are positive and their sum is less than 1, then the pixel is inside the triangle
                        int idx = (y * Nx + x) * 3;
                        int depth_idx = y * Nx + x;

                        // if beta and gamma are positive and their sum is less than 1, then the pixel is inside the triangle
                        // calculate the depth of the pixel
                        float depth = (1 - beta - gamma) * a.z + beta * b.z + gamma * c.z;
                        if (depth >= depth_buffer[depth_idx]) {
                            // if the depth of the pixel is less than the depth of the pixel in the depth buffer, then update the depth buffer
                            // if depth of the pixel is minimum value, then the pixel is visible
                            // get minimum depth
                            depth_buffer[depth_idx] = depth;

                            // set each pixel of image buffer
                            image_buffer[idx] = color.x * 255;
                            image_buffer[idx + 1] = color.y * 255;
                            image_buffer[idx + 2] = color.z * 255;
                        }
                    }
                    beta += beta_x;
                    gamma += gamma_x;
                }
                beta += beta_y - n * beta_x;
                gamma += gamma_y - n * gamma_x;
            }
        }
    }
};

class Gouraud_shading {
private:
    vec3 color_a = vec3(0, 0, 0);
    vec3 color_b = vec3(0, 0, 0);
    vec3 color_c = vec3(0, 0, 0);
    
    vec3 color = vec3(0, 0, 0);
    unsigned char* image_buffer = NULL;
    float depth_buffer[Nx * Ny];

public:
    Gouraud_shading() {}

    unsigned char* get_image() {
        return image_buffer;
    }

    void gouraud_shading() {
        image_buffer = new unsigned char[Nx * Ny * 3] ();
        for(int y = 0; y < Ny; y++) {
            for (int x = 0; x < Nx; x++) {
                depth_buffer[y * Nx + x] = -FLT_MAX;
            }
        }

        scene.create_scene();

        vertices_num = scene.get_num_vertices();
        triangles_num = scene.get_num_triangles();
        index_buffer = scene.get_index_buffer();
        vertices = scene.get_vertices();

        // create identical mtx
        mat4 mtx = (mat4(1, 0, 0, 0,
                         0, 1, 0, 0,
                         0, 0, 1, 0,
                         0, 0, 0, 1));


        for (int i = 0; i < triangles_num; i++) {
            // index of the vertices of the triangle
            int k0 = index_buffer[3 * i];
            int k1 = index_buffer[3 * i + 1];
            int k2 = index_buffer[3 * i + 2];

            // get the vertices of the triangle
            vec3 a = vertices[k0];
            vec3 b = vertices[k1];
            vec3 c = vertices[k2];

            // transform until camera space
            mat4 cam_mtx = transformation.until_cam_pipeline(mtx, camera);

            // get position of vertices in camera space
            a = transformation.normalize_to_vec3(transformation.multipl_mtx_vec(cam_mtx, vec4(a, 1)));
            b = transformation.normalize_to_vec3(transformation.multipl_mtx_vec(cam_mtx, vec4(b, 1)));
            c = transformation.normalize_to_vec3(transformation.multipl_mtx_vec(cam_mtx, vec4(c, 1)));

            // L = La + Ld + Ls = ka * Ia + kd * I * max(0, n dot l) + ks * I * max(0, n dot h)^p
            float ip = point_light.intensity;
            vec3 pos = point_light.position;

            vec3 origin = camera.eye_point;

            // from light source to point
            vec3 la = normalize(pos - a);   // direction of light from light source
            vec3 lb = normalize(pos - b);
            vec3 lc = normalize(pos - c);

            vec3 na = shader.calc_vertex_normal(a);     // calculate the normal vertices
            vec3 nb = shader.calc_vertex_normal(b);
            vec3 nc = shader.calc_vertex_normal(c);

            vec3 va = normalize(origin - a);
            vec3 vb = normalize(origin - b);
            vec3 vc = normalize(origin - c);

            // half vector of v and l
            vec3 ha = normalize(va + la);
            vec3 hb = normalize(vb + lb);
            vec3 hc = normalize(vc + lc);

            // calculate the color each vertex in triangle
            color_a.x = shader.ka.x * ambient_light.ia + shader.kd.x * ip * std::max(0.0f, dot(na, la)) + shader.ks.x * ip * pow(std::max(0.0f, dot(na, ha)), shader.p);
            color_a.y = shader.ka.y * ambient_light.ia + shader.kd.y * ip * std::max(0.0f, dot(na, la)) + shader.ks.y * ip * pow(std::max(0.0f, dot(na, ha)), shader.p);
            color_a.z = shader.ka.z * ambient_light.ia + shader.kd.z * ip * std::max(0.0f, dot(na, la)) + shader.ks.z * ip * pow(std::max(0.0f, dot(na, ha)), shader.p);

            color_b.x = shader.ka.x * ambient_light.ia + shader.kd.x * ip * std::max(0.0f, dot(nb, lb)) + shader.ks.x * ip * pow(std::max(0.0f, dot(nb, hb)), shader.p);
            color_b.y = shader.ka.y * ambient_light.ia + shader.kd.y * ip * std::max(0.0f, dot(nb, lb)) + shader.ks.y * ip * pow(std::max(0.0f, dot(nb, hb)), shader.p);
            color_b.z = shader.ka.z * ambient_light.ia + shader.kd.z * ip * std::max(0.0f, dot(nb, lb)) + shader.ks.z * ip * pow(std::max(0.0f, dot(nb, hb)), shader.p);

            color_c.x = shader.ka.x * ambient_light.ia + shader.kd.x * ip * std::max(0.0f, dot(nc, lc)) + shader.ks.x * ip * pow(std::max(0.0f, (nc, hc)), shader.p);
            color_c.y = shader.ka.y * ambient_light.ia + shader.kd.y * ip * std::max(0.0f, dot(nc, lc)) + shader.ks.y * ip * pow(std::max(0.0f, (nc, hc)), shader.p);
            color_c.z = shader.ka.z * ambient_light.ia + shader.kd.z * ip * std::max(0.0f, dot(nc, lc)) + shader.ks.z * ip * pow(std::max(0.0f, (nc, hc)), shader.p);

            // after camera = projection * viewport
            mat4 temp_mtx = transformation.after_cam_pipeline(mtx);

            // get position of vertices in viewport space
            a = transformation.normalize_to_vec3(transformation.multipl_mtx_vec(temp_mtx, vec4(a, 1)));
            b = transformation.normalize_to_vec3(transformation.multipl_mtx_vec(temp_mtx, vec4(b, 1)));
            c = transformation.normalize_to_vec3(transformation.multipl_mtx_vec(temp_mtx, vec4(c, 1)));

            // get bounding box of the triangle
            int xmin = std::min(std::min(a.x, b.x), c.x);
            int xmax = std::max(std::max(a.x, b.x), c.x);
            int ymin = std::min(std::min(a.y, b.y), c.y);
            int ymax = std::max(std::max(a.y, b.y), c.y);

            // starting point of each beta and gamma of barycentric coordinates
            float beta = ((a.y - c.y) * xmin + (c.x - a.x) * ymin + a.x * c.y - c.x * a.y) / ((a.y - c.y) * b.x + (c.x - a.x) * b.y + a.x * c.y - c.x * a.y);
            float gamma = ((a.y - b.y) * xmin + (b.x - a.x) * ymin + a.x * b.y - b.x * a.y) / ((a.y - b.y) * c.x + (b.x - a.x) * c.y + a.x * b.y - b.x * a.y);

            // increasing value of beta and gamma in each axis
            float beta_x = (a.y - c.y) / ((a.y - c.y) * b.x + (c.x - a.x) * b.y + a.x * c.y - c.x * a.y);
            float beta_y = (c.x - a.x) / ((a.y - c.y) * b.x + (c.x - a.x) * b.y + a.x * c.y - c.x * a.y);

            float gamma_x = (a.y - b.y) / ((a.y - b.y) * c.x + (b.x - a.x) * c.y + a.x * b.y - b.x * a.y);
            float gamma_y = (b.x - a.x) / ((a.y - b.y) * c.x + (b.x - a.x) * c.y + a.x * b.y - b.x * a.y);

            int n = (xmax - xmin) + 1;
            
            // set to color of pixels in triangle
            for (int y = ymin; y <= ymax; y++) {
                for (int x = xmin; x <= xmax; x++) {
                    if (beta > 0 && gamma > 0 && beta + gamma < 1) {
                        // if beta and gamma are positive and their sum is less than 1, then the pixel is inside the triangle
                        int idx = (y * Nx + x) * 3;
                        int depth_idx = y * Nx + x;
                        
                        color = (1 - beta - gamma) * color_a + beta * color_b + gamma * color_c;
                        
                        color.x = (color.x) > 1 ? 1 : color.x;
                        color.y = (color.y) > 1 ? 1 : color.y;
                        color.z = (color.z) > 1 ? 1 : color.z;

                        color.x = shader.gamma_correction(color.x, shader.gamma_val);
                        color.y = shader.gamma_correction(color.y, shader.gamma_val);
                        color.z = shader.gamma_correction(color.z, shader.gamma_val);

                        // if beta and gamma are positive and their sum is less than 1, then the pixel is inside the triangle
                        // calculate the depth of the pixel
                        float depth = (1 - beta - gamma) * a.z + beta * b.z + gamma * c.z;

                        if (depth >= depth_buffer[depth_idx]) {
                            // if the depth of the pixel is less than the depth of the pixel in the depth buffer, then update the depth buffer
                            // if depth of the pixel is minimum value, then the pixel is visible
                            // get minimum depth
                            depth_buffer[depth_idx] = depth;

                            // set each pixel of image buffer
                            image_buffer[idx] = color.x * 255;
                            image_buffer[idx + 1] = color.y * 255;
                            image_buffer[idx + 2] = color.z * 255;
                        }
                    }
                    beta += beta_x;
                    gamma += gamma_x;
                }
                beta += beta_y - n * beta_x;
                gamma += gamma_y - n * gamma_x;
            }
        }
    }
};

class Phong_shading {
private:
    vec3 color = vec3(0, 0, 0);
    vec3 point = vec3(0, 0, 0);

    vec3 a_prev = vec3(0, 0, 0);
    vec3 b_prev = vec3(0, 0, 0);
    vec3 c_prev = vec3(0, 0, 0);

    unsigned char* image_buffer = NULL;
    float depth_buffer[Nx * Ny];

public:
    Phong_shading() {}

    unsigned char* get_image() {
        return image_buffer;
    }

    void phong_shading() {
        image_buffer = new unsigned char[Nx * Ny * 3] ();
        for(int y = 0; y < Ny; y++) {
            for (int x = 0; x < Nx; x++) {
                depth_buffer[y * Nx + x] = -FLT_MAX;
            }
        }

        scene.create_scene();

        vertices_num = scene.get_num_vertices();
        triangles_num = scene.get_num_triangles();
        index_buffer = scene.get_index_buffer();
        vertices = scene.get_vertices();

        // create identical mtx
        mat4 mtx = (mat4(1, 0, 0, 0,
                         0, 1, 0, 0,
                         0, 0, 1, 0,
                         0, 0, 0, 1));

        for (int i = 0; i < triangles_num; i++) {
            // index of the vertices of the triangle
            int k0 = index_buffer[3 * i];
            int k1 = index_buffer[3 * i + 1];
            int k2 = index_buffer[3 * i + 2];

            // get the vertices of the triangle
            vec3 a = vertices[k0];
            vec3 b = vertices[k1];
            vec3 c = vertices[k2];
            
            // transform until camera space
            mat4 cam_mtx = transformation.until_cam_pipeline(mtx, camera);

            // get position of vertices in camera space
            a_prev = transformation.normalize_to_vec3(transformation.multipl_mtx_vec(cam_mtx, vec4(a, 1)));
            b_prev = transformation.normalize_to_vec3(transformation.multipl_mtx_vec(cam_mtx, vec4(b, 1)));
            c_prev = transformation.normalize_to_vec3(transformation.multipl_mtx_vec(cam_mtx, vec4(c, 1)));

            // transform normal vector
            vec3 na = shader.calc_vertex_normal(a_prev);
            vec3 nb = shader.calc_vertex_normal(b_prev);
            vec3 nc = shader.calc_vertex_normal(c_prev);

            // after camera = projection * viewport
            mat4 temp_mtx = transformation.after_cam_pipeline(mtx);

            a = transformation.normalize_to_vec3(transformation.multipl_mtx_vec(temp_mtx, vec4(a_prev, 1)));
            b = transformation.normalize_to_vec3(transformation.multipl_mtx_vec(temp_mtx, vec4(b_prev, 1)));
            c = transformation.normalize_to_vec3(transformation.multipl_mtx_vec(temp_mtx, vec4(c_prev, 1)));

            // get bounding box of the triangle
            int xmin = std::min(std::min(a.x, b.x), c.x);
            int xmax = std::max(std::max(a.x, b.x), c.x);
            int ymin = std::min(std::min(a.y, b.y), c.y);
            int ymax = std::max(std::max(a.y, b.y), c.y);

            // starting point of each beta and gamma of barycentric coordinates
            float beta = ((a.y - c.y) * xmin + (c.x - a.x) * ymin + a.x * c.y - c.x * a.y) / ((a.y - c.y) * b.x + (c.x - a.x) * b.y + a.x * c.y - c.x * a.y);
            float gamma = ((a.y - b.y) * xmin + (b.x - a.x) * ymin + a.x * b.y - b.x * a.y) / ((a.y - b.y) * c.x + (b.x - a.x) * c.y + a.x * b.y - b.x * a.y);

            // increasing value of beta and gamma in each axis
            float beta_x = (a.y - c.y) / ((a.y - c.y) * b.x + (c.x - a.x) * b.y + a.x * c.y - c.x * a.y);
            float beta_y = (c.x - a.x) / ((a.y - c.y) * b.x + (c.x - a.x) * b.y + a.x * c.y - c.x * a.y);

            float gamma_x = (a.y - b.y) / ((a.y - b.y) * c.x + (b.x - a.x) * c.y + a.x * b.y - b.x * a.y);
            float gamma_y = (b.x - a.x) / ((a.y - b.y) * c.x + (b.x - a.x) * c.y + a.x * b.y - b.x * a.y);

            int n = (xmax - xmin) + 1;

            // set to color of pixels in triangle
            for (int y = ymin; y <= ymax; y++) {
                for (int x = xmin; x <= xmax; x++) {
                    if (beta > 0 && gamma > 0 && beta + gamma < 1) {
                        // if beta and gamma are positive and their sum is less than 1, then the pixel is inside the triangle
                        int idx = (y * Nx + x) * 3;
                        int depth_idx = y * Nx + x;

                        // if beta and gamma are positive and their sum is less than 1, then the pixel is inside the triangle
                        // calculate the depth of the pixel
                        float depth = (1 - beta - gamma) * a.z + beta * b.z + gamma * c.z;
                        vec3 point = (1 - beta - gamma) * a_prev + beta * b_prev + gamma * c_prev;
                        vec3 norm = (1 - beta - gamma) * na + beta * nb + gamma * nc;

                        // L = La + Ld + Ls = ka * Ia + kd * I * max(0, n dot l) + ks * I * max(0, n dot h)^p
                        float ip = point_light.intensity;
                        vec3 pos = point_light.position;

                        vec3 origin = camera.eye_point;

                        // from light source to point
                        vec3 l = normalize(pos - point);    // direction of light from light source
                        vec3 v = normalize(origin - point);
                        vec3 normal = normalize(norm);
                        // half vector of v and l
                        vec3 h = normalize(v + l);

                        // calculate the color of the triangle centroid
                        color.x = shader.ka.x * ambient_light.ia + shader.kd.x * ip * std::max(0.0f, dot(normal, l)) + shader.ks.x * ip * pow(std::max(0.0f, dot(normal, h)), shader.p);
                        color.y = shader.ka.y * ambient_light.ia + shader.kd.y * ip * std::max(0.0f, dot(normal, l)) + shader.ks.y * ip * pow(std::max(0.0f, dot(normal, h)), shader.p);
                        color.z = shader.ka.z * ambient_light.ia + shader.kd.z * ip * std::max(0.0f, dot(normal, l)) + shader.ks.z * ip * pow(std::max(0.0f, dot(normal, h)), shader.p);
                       
                        color.x = (color.x) > 1 ? 1 : color.x;
                        color.y = (color.y) > 1 ? 1 : color.y;
                        color.z = (color.z) > 1 ? 1 : color.z;

                        color.x = shader.gamma_correction(color.x, shader.gamma_val);
                        color.y = shader.gamma_correction(color.y, shader.gamma_val);
                        color.z = shader.gamma_correction(color.z, shader.gamma_val);

                        if (depth >= depth_buffer[depth_idx]) {
                            // if the depth of the pixel is less than the depth of the pixel in the depth buffer, then update the depth buffer
                            // if depth of the pixel is minimum value, then the pixel is visible
                            // get minimum depth
                            depth_buffer[depth_idx] = depth;

                            // set each pixel of image buffer
                            image_buffer[idx] = color.x * 255;
                            image_buffer[idx + 1] = color.y * 255;
                            image_buffer[idx + 2] = color.z * 255;
                        }
                    }
                    beta += beta_x;
                    gamma += gamma_x;
                }
                beta += beta_y - n * beta_x;
                gamma += gamma_y - n * gamma_x;
            }
        }
    }
};