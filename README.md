# ��ǻ�ͱ׷��Ƚ��׿���ó�� ���� 4

- �� ������ ���� ȯ�����δ� vscode�� cmake�� ����Ͽ����ϴ�.
- �ʱ� ȯ�� ���� �� openGL�� �ٷ�� ���� �ʿ��� ��ų�� ��ũ�� ���󰡸� Ȯ���Ͻ� �� �ִ� [��Ʃ�� ���� ������](https://www.youtube.com/playlist?list=PLvNHCGtd4kh_cYLKMP_E-jwF3YKpDP4hf)�� �����Ͽ� �����Ͽ����ϴ�.
- ��ҿ� �п��� ������ �޾� �����Ͽ����ϴ�.

---

### ���� ����
- [ȯ�� ����](#ȯ��-����)

- [���� ���](#����-���)

- [��� ȭ��](#���-ȭ��)

- [Code ����](#code-����)

---

### ȯ�� ����

- vscode version 1.87�� ����Ͽ����ϴ�.
- cmake�� �ּ��� version 3.23�� ����ؾ� �մϴ�.
- �� repository�� �ִ� CMakeLists.txt�� Dependency.cmake ������ ���� �ʿ��� library�� �ʱ� ���� �� �� ���� �ٿ�ε� ���� �� �ֽ��ϴ�.

---

### ���� ���

1. vscode�� ���� ��, �ش� project�� �ִ� directory�� ���� project folder�� load���ݴϴ�.
2. CMake�� ���� vscode extension�� �ʿ��ϹǷ�, extension�� �������� �ʴ´ٸ� vscode ������ Extensions �ǿ��� cmake�� �˻��Ͽ� CMake�� CMake Tools�� install ���ݴϴ�.
3. Windows ȯ�濡���� ctrl + shift + p, Mac ȯ�濡���� cmd + p Ű�� �Է��Ͽ� command�� �Է��� �� �ִ� â���� cmake�� �˻� �� CMake:Configure�� �����ϰ�, �ü���� �°� �����Ϸ� ŰƮ�� �����մϴ�.

    (Ȥ�� �ش� ������Ʈ�� �ִ� �������� cmd â�� ���� code .�� �Է��ϸ� �ڵ����� CMake project���� �ν��ϰ� configure�� ���� �˾��� ��ϴ�.)

    Configure�� �����ϸ� vscode �ϴ��� OUTPUT �ǿ� "Configuring project: CGIP_hw1"�̶�� ��µǴ� ���� Ȯ���Ͻ� �� �ֽ��ϴ�.

4. CMake ������Ʈ�� �ν��� �Ǿ�����, �ٽ� command�� �Է��� �� �ִ� â�� ���� CMake�� �˻��Ͽ� CMake:Build�� �����մϴ� (Ȥ�� ����Ű�� F7�� �Է��մϴ�).

    �ʱ� build���, �̶� �ʿ��� library�� ���� build ������ �ٿ�ε� �˴ϴ�.

5. �ʱ� build�� ��ģ ��, ctrl + F5�� �Է��ϸ� Debug ���� project�� ����˴ϴ�.
Debug ����̹Ƿ� �ϴ��� DEBUG CONSOLE���� ��� �� ������ Ȯ���� �� �ֽ��ϴ�.

    ���� ���� ��µǴ� �͹̳� â�� ���ڸ� �Է��ϸ� ���ڿ� �´� ����� ��µ˴ϴ�.
    0: exit, 1: result a, 2: result b, 3: result c, 4: result d

---

### ��� ȭ��

- (a)�� ���� ��� ȭ���� ������ �����ϴ�.
    - triangle mesh�� ������ sphere�� ���Ͽ� �� ǥ�� ���� unshaded�� ���� ����� ������� ��Ÿ�� ȭ���Դϴ�.
<p align="center">
    <img src = "screenshot/Screenshot_a.png">
</p>

- (b)�� ���� ��� ȭ���� ������ �����ϴ�.
    - triangle mesh�� ������ sphere�� ���ؼ� flat shading�� �� ����Դϴ�.
<p align="center">
    <img src = "screenshot/Screenshot_b.png">
</p>

- (c)�� ���� ��� ȭ���� ������ �����ϴ�.
    - triangle mesh�� ������ sphere�� ���ؼ� gouraud shading�� �� ����Դϴ�.
<p align="center">
    <img src = "screenshot/Screenshot_c.png">
</p>

- (d)�� ���� ��� ȭ���� ������ �����ϴ�.
    - triangle mesh�� ������ sphere�� ���ؼ� phong shading�� �� ����Դϴ�.
<p align="center">
    <img src = "screenshot/Screenshot_d.png">
</p>

---

### Code ����

- ��� �ҽ��ڵ� ������ src ������ �ֽ��ϴ�.
    - scene.h ������ �⺻���� ������ ������ ������ �����Դϴ�.
    
        �Ʒ��� �⺻������ �����Ǿ��� sphere_scene.cpp ���Ͽ��� ������ ���뿡 ���� �����Դϴ�.

- glm::vec3* vertices ����

    �� ������ ���� vertex���� ���� �����ϱ� ���� vec3 array�Դϴ�.

    �ش� ������ ���� create_scene() �Լ� ������ ������ ���� �ʱ�ȭ�˴ϴ�.
    ```
    vertices = new vec3[gNumVertices];
    ```
    for loop ������, vertices �������� ������ ���� ���� ������ �˴ϴ�.
    ```
    vertices[t] = vec3(x, y, z);
    ```
    ���� t ���� �ϳ��� �������� for loop�� ���鼭 �Ź� ���ο� vertex ���� array�� �����ϵ��� �մϴ�.

    ���������� for loop�� �������� ���� ������ ������ �����մϴ�.
    ```
    vertices[t++] = vec3(0, 1, 0);

    vertices[t++] = vec3(0, -1, 0);
    ```
    ������ t++;�� �ۼ��Ǿ� �ִ� �κ��� ���� ���� ��ü�Ͽ����ϴ�.
    
- getter �Լ�

    �� �Լ��� private���� ������ �������� ���� �޾ƿ��� ���� �Լ��Դϴ�.
    ```
    int get_num_vertices()
    {
        return gNumVertices;
    }

    int get_num_triangles()
    {
        return gNumTriangles;
    }

    int* get_index_buffer()
    {
        return gIndexBuffer;
    }

    vec3* get_vertices()
    {
        return vertices;
    }
    ```

    - transformation.h ������ ��ǥ�� transformation�� ������ �Լ����� �����ϴ� �����Դϴ�.
    Transformation class�� Camera class�� �����Ǿ� �ֽ��ϴ�.
    
- mat4 multipl_mtx_mtx(mat4 mtx_a, mat4 mtx_b) �Լ�

    �� �Լ��� 4���� ��� ���� ���� ���Ͽ� ������ �Լ��Դϴ�.

    ��� a�� b�� �� ���Ұ��� �� �� ���� ���Ͽ� ���ο� 4���� ����� result�� �����ϰ� �̸� ��ȯ�մϴ�.

    transformation pipeline�� �����ϱ� ���Ͽ� �ʿ��� �Լ��Դϴ�.

    ```
    mat4 multipl_mtx_mtx(mat4 mtx_a, mat4 mtx_b) {
        vec4 a_row1(mtx_a[0][0], mtx_a[0][1], mtx_a[0][2], mtx_a[0][3]);
        vec4 a_row2(mtx_a[1][0], mtx_a[1][1], mtx_a[1][2], mtx_a[1][3]);
        vec4 a_row3(mtx_a[2][0], mtx_a[2][1], mtx_a[2][2], mtx_a[2][3]);
        vec4 a_row4(mtx_a[3][0], mtx_a[3][1], mtx_a[3][2], mtx_a[3][3]);

        vec4 b_row1(mtx_b[0][0], mtx_b[0][1], mtx_b[0][2], mtx_b[0][3]);
        vec4 b_row2(mtx_b[1][0], mtx_b[1][1], mtx_b[1][2], mtx_b[1][3]);
        vec4 b_row3(mtx_b[2][0], mtx_b[2][1], mtx_b[2][2], mtx_b[2][3]);
        vec4 b_row4(mtx_b[3][0], mtx_b[3][1], mtx_b[3][2], mtx_b[3][3]);

        float x11 = a_row1.x * b_row1.x + a_row1.y * b_row2.x + a_row1.z * b_row3.x + a_row1.w * b_row4.x;  //a11*b11 + a12*b21 + a13*b31 + a14*b41
        float x12 = a_row1.x * b_row1.y + a_row1.y * b_row2.y + a_row1.z * b_row3.y + a_row1.w * b_row4.y;  //a11*b12 + a12*b22 + a13*b32 + a14*b42
        float x13 = a_row1.x * b_row1.z + a_row1.y * b_row2.z + a_row1.z * b_row3.z + a_row1.w * b_row4.z;  //a11*b13 + a12*b23 + a13*b33 + a14*b43
        float x14 = a_row1.x * b_row1.w + a_row1.y * b_row2.w + a_row1.z * b_row3.w + a_row1.w * b_row4.w;  //a11*b14 + a12*b24 + a13*b34 + a14*b44

        float x21 = a_row2.x * b_row1.x + a_row2.y * b_row2.x + a_row2.z * b_row3.x + a_row2.w * b_row4.x;  //a21*b11 + a22*b21 + a23*b31 + a24*b41
        float x22 = a_row2.x * b_row1.y + a_row2.y * b_row2.y + a_row2.z * b_row3.y + a_row2.w * b_row4.y;  //a21*b12 + a22*b22 + a23*b32 + a24*b42
        float x23 = a_row2.x * b_row1.z + a_row2.y * b_row2.z + a_row2.z * b_row3.z + a_row2.w * b_row4.z;  //a21*b13 + a22*b23 + a23*b33 + a24*b43
        float x24 = a_row2.x * b_row1.w + a_row2.y * b_row2.w + a_row2.z * b_row3.w + a_row2.w * b_row4.w;  //a21*b14 + a22*b24 + a23*b34 + a24*b44

        float x31 = a_row3.x * b_row1.x + a_row3.y * b_row2.x + a_row3.z * b_row3.x + a_row3.w * b_row4.x;  //a31*b11 + a32*b21 + a33*b31 + a34*b41
        float x32 = a_row3.x * b_row1.y + a_row3.y * b_row2.y + a_row3.z * b_row3.y + a_row3.w * b_row4.y;  //a31*b12 + a32*b22 + a33*b32 + a34*b42
        float x33 = a_row3.x * b_row1.z + a_row3.y * b_row2.z + a_row3.z * b_row3.z + a_row3.w * b_row4.z;  //a31*b13 + a32*b23 + a33*b33 + a34*b43
        float x34 = a_row3.x * b_row1.w + a_row3.y * b_row2.w + a_row3.z * b_row3.w + a_row3.w * b_row4.w;  //a31*b14 + a32*b24 + a33*b34 + a34*b44

        float x41 = a_row4.x * b_row1.x + a_row4.y * b_row2.x + a_row4.z * b_row3.x + a_row4.w * b_row4.x;  //a41*b11 + a42*b21 + a43*b31 + a44*b41
        float x42 = a_row4.x * b_row1.y + a_row4.y * b_row2.y + a_row4.z * b_row3.y + a_row4.w * b_row4.y;  //a41*b12 + a42*b22 + a43*b32 + a44*b42
        float x43 = a_row4.x * b_row1.z + a_row4.y * b_row2.z + a_row4.z * b_row3.z + a_row4.w * b_row4.z;  //a41*b13 + a42*b23 + a43*b33 + a44*b43
        float x44 = a_row4.x * b_row1.w + a_row4.y * b_row2.w + a_row4.z * b_row3.w + a_row4.w * b_row4.w;  //a41*b14 + a42*b24 + a43*b34 + a44*b44

        mat4 result(vec4(x11, x12, x13, x14),
                    vec4(x21, x22, x23, x24),
                    vec4(x31, x32, x33, x34),
                    vec4(x41, x42, x43, x44));

        return result;
    }
    ```

- vec4 multipl_mtx_vec(mat4 mtx, vec4 vec) �Լ�

    �� �Լ��� 4���� ��İ� 4���� ���� ������ ���� ���� �Լ��Դϴ�.

    ��İ� ������ ���� ���� �� �� ���� ���Ͽ� ���ο� 4���� ������ result�� �����ϰ� �̸� ��ȯ�մϴ�.

    transformation pipeline�� ���� ����Ǵ� ������� ����ϱ� ���� �Լ��Դϴ�.
    ```
    vec4 multipl_mtx_vec(mat4 mtx, vec4 vec) {
        vec4 row1(mtx[0][0], mtx[0][1], mtx[0][2], mtx[0][3]);
        vec4 row2(mtx[1][0], mtx[1][1], mtx[1][2], mtx[1][3]);
        vec4 row3(mtx[2][0], mtx[2][1], mtx[2][2], mtx[2][3]);
        vec4 row4(mtx[3][0], mtx[3][1], mtx[3][2], mtx[3][3]);

        float x = row1.x * vec.x + row1.y * vec.y + row1.z * vec.z + row1.w * vec.w;    //a11*x + a12*y + a13*z + a14*w
        float y = row2.x * vec.x + row2.y * vec.y + row2.z * vec.z + row2.w * vec.w;    //a21*x + a22*y + a23*z + a24*w
        float z = row3.x * vec.x + row3.y * vec.y + row3.z * vec.z + row3.w * vec.w;    //a31*x + a32*y + a33*z + a34*w
        float w = row4.x * vec.x + row4.y * vec.y + row4.z * vec.z + row4.w * vec.w;    //a41*x + a42*y + a43*z + a44*w

        vec4 result = vec4(x, y, z, w);

        return result;
    }
    ```

- pipeline�� ���ԵǴ� transformation �Լ���

    ������� scaling, translation, camera transformation, perspective projection, viewport transformation�� �����մϴ�.

    ```
    mat4 scale_mtx(mat4 mtx) {
        float sx = 2.0f;
        float sy = 2.0f;
        float sz = 2.0f;
        
        // scaling mtx
        mat4 scale_mtx(vec4(sx, 0, 0, 0),
                    vec4(0, sy, 0, 0),
                    vec4(0, 0, sz, 0),
                    vec4(0, 0, 0, 1));

        mtx = multipl_mtx_mtx(scale_mtx, mtx);

        return mtx;
    }

    mat4 trans_mtx(mat4 mtx) {    
        float tx = 0.0f;
        float ty = 0.0f;
        float tz = -7.0f;

        // translation mtx
        mat4 trans(vec4(1, 0, 0, tx),
                vec4(0, 1, 0, ty),
                vec4(0, 0, 1, tz),
                vec4(0, 0, 0, 1));

        mtx = multipl_mtx_mtx(trans, mtx);

        return mtx;
    }

    mat4 cam_mtx(Camera camera, mat4 mtx) {
        // camera transformation mtx
        mat4 camera_mtx(vec4(camera.u.x, camera.v.x, camera.w.x, camera.eye_point.x),
                        vec4(camera.u.y, camera.v.y, camera.w.y, camera.eye_point.y),
                        vec4(camera.u.z, camera.v.z, camera.w.z, camera.eye_point.z),
                        vec4(0, 0, 0, 1));

        mat4 inverse_camera_mtx = inverse(camera_mtx);
        //since camera_mtx is identity matrix, inverse_camera_mtx is also identity matrix

        mtx = multipl_mtx_mtx(inverse_camera_mtx, mtx);

        return mtx;
    }

    mat4 projection_mtx(mat4 mtx) {
        float l = -0.1f;
        float r = 0.1f;
        float b = -0.1f;
        float t = 0.1f;
        float n = -0.1f;
        float f = -1000.0f;    

        // perspective projection mtx
        mat4 perspective_projection_mtx(vec4(2 * n / (r - l), 0, (l + r) / (l - r), 0),
                                        vec4(0, 2 * n / (t - b), (b + t) / (b - t), 0),
                                        vec4(0, 0, (n + f) / (n - f), 2 * f * n/ (f - n)),
                                        vec4(0, 0, 1, 0));

        mtx = multipl_mtx_mtx(perspective_projection_mtx, mtx);

        return mtx;
    }

    mat4 viewport_mtx(mat4 mtx) {
        // viewport transformation mtx
        mat4 viewport_trans_mtx(vec4(Nx / 2, 0, 0, (float)(Nx - 1) / 2),
                                vec4(0, Ny / 2, 0, (float)(Ny - 1) / 2),
                                vec4(0, 0, 1, 0),
                                vec4(0, 0, 0, 1));

        mtx = multipl_mtx_mtx(viewport_trans_mtx, mtx);

        return mtx;
    }
    ```

- mat4 until_cam_pipeline(mat4 mtx, Camera camera) �Լ�

    camera space���� transformation���� �����ϴ� �Լ��Դϴ�.
    ```
    mat4 until_cam_pipeline(mat4 mtx, Camera camera) {
        mtx = scale_mtx(mtx);
        mtx = trans_mtx(mtx);
        mtx = cam_mtx(camera, mtx);

        return mtx;
    }
    ```

- mat4 after_cam_pipeline(mat4 mtx) �Լ�

    camera space���� transformation ���ĺ����� �Լ��Դϴ�.
    ```
    mat4 after_cam_pipeline(mat4 mtx) {
        mtx = projection_mtx(mtx);
        mtx = viewport_mtx(mtx);

        return mtx;
    }
    ```

- mat4 transformation_pipeline(mat4 mtx, Camera camera) �Լ�

    ��ü transformation pipeline�� ��Ÿ���� ����ϴ� �Լ��Դϴ�.
    ```
    mat4 transformation_pipeline(mat4 mtx, Camera camera) {
        mtx = scale_mtx(mtx);
        mtx = trans_mtx(mtx);
        mtx = cam_mtx(camera, mtx);
        mtx = projection_mtx(mtx);
        mtx = viewport_mtx(mtx);
        
        return mtx;
    }
    ```

- vec3 normalize_to_vec3(vec4 vec) �Լ�

    4���� ���͸� 3���� ���ͷ� ��ȯ�ϱ� ���� �Լ��Դϴ�.
    ```
    vec3 normalize_to_vec3(vec4 vec) {
        vec3 result = vec / vec.w;

        return result;
    }
    ```

- Camera class

    camera�� �����ϱ� ���� class�Դϴ�.

    ```
    class Camera {
    public:
        vec3 eye_point = vec3(0.0f, 0.0f, 0.0f);

        vec3 u = vec3(1, 0, 0);
        vec3 v = vec3(0, 1, 0);
        vec3 w = vec3(0, 0, 1);
    };
    ```

    - light.h ������ ���� ���� ���� �����ϰ� �ҷ����� ���� class�� �����ϴ� �����Դϴ�.


- Point_light class

    point light�� �����ϱ� ���� �Լ��Դϴ�.
    ```
    class Point_light {
    public:
        vec3 position = vec3(-4, 4, -3);
        float intensity = 1.0f;
        vec3 color = vec3(1, 1, 1);
    };
    ```

- Ambient_light class

    ambient light�� �����ϱ� ���� �Լ��Դϴ�.
    ```
    class Ambient_light {
    public:
        float ia = 0.2f;
        vec3 color = vec3(1, 1, 1);
    };
    ```

    - shader.cpp ������ shading�� ���õ� �Լ��� �����ϴ� �����Դϴ�.

        shader.cpp���� Shader, Unshaded, Flat_shading, Gouraud_shading, Phong_shading class�� ���ԵǾ� �ֽ��ϴ�.

- Shader class

    �ʿ��� �������� ������ triangle�� ����, triangle�� normal, vertex�� normal, gamma correction�� ����մϴ�.
    ```
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
    ```

- Unshaded class

    �ʿ��� �������� �ʱ�ȭ�ϰ�, unshaded image�� ǥ���ϱ� ���ؼ� �����ڿ� get image �Լ�, unshaded �Լ��� �����մϴ�.
    ```
    class Unshaded {
        unsigned char* image_buffer = NULL;
        float depth_buffer[Nx * Ny];

    public:
        Unshaded() {}

        unsigned char* get_image() {
            return image_buffer;
        }

        void unshaded() {
            // it goes on ...
        }
    };
    ```

    unshaded �Լ������� ���� image buffer�� depth buffer�� �ʱ�ȭ�մϴ�.
    ```
    image_buffer = new unsigned char[Nx * Ny * 3] ();
    for(int y = 0; y < Ny; y++) {
        for (int x = 0; x < Nx; x++) {
            depth_buffer[y * Nx + x] = -FLT_MAX;
        }
    }
    ```

    ���� scene�� �����ϰ� �� ������ ���� �����ɴϴ�.
    ```
    scene.create_scene();

    vertices_num = scene.get_num_vertices();
    triangles_num = scene.get_num_triangles();
    index_buffer = scene.get_index_buffer();
    vertices = scene.get_vertices();
    ```

    transformation pipeline�� ��ġ�� �� �ﰢ���� viewport space���� ��ȯ�մϴ�.
    
    �� �ﰢ���� vertex ���� ����� �� vertices �迭�� �ٽ� �����մϴ�.
    ```
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
    ```

    ���� �� �ﰢ���� ���ؼ� vertex�� ��ǥ�� ���ϰ�, �ﰢ���� �����ϴ� ���� ���� ũ���� �簢���� ����� �� ���� ������ barycentric coordinate���� ��ȯ�Ͽ� depth�� ����� ��� ���� image_buffer ���� �����մϴ�.
    ```
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
    ```

- Flat_shading class

    �ʿ��� �������� �ʱ�ȭ�ϰ�, Flat shading class�� ���� �����ڿ� image�� �������� ���� get image �Լ�, flat_shading�� ���� �Լ��� �����մϴ�.
    ```
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
                // it goes on...
            }
        }
    };
    ```

    flat_shading �Լ������� image buffer�� depth buffer�� ���� �ʱ�ȭ�մϴ�.
    ```
    image_buffer = new unsigned char[Nx * Ny * 3] ();
    for(int y = 0; y < Ny; y++) {
        for (int x = 0; x < Nx; x++) {
            depth_buffer[y * Nx + x] = -FLT_MAX;
        }
    }
    ```
    
    ���� scene�� �����ϰ�, ������ ���� ���� �����ɴϴ�.
    
    ```
    scene.create_scene();

    vertices_num = scene.get_num_vertices();
    triangles_num = scene.get_num_triangles();
    index_buffer = scene.get_index_buffer();
    vertices = scene.get_vertices();
    ```

    �� �ﰢ������ vertex�� ���� ��, camera space���� ��ȯ�մϴ�.
    ```    
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
    ```

    ���� camera space������ �� �ﰢ���� �߾ӿ����� l, n, v, h ���� ���� ���ϰ� �̿� ���� �ﰢ���� color�� ���ϰ�, �����մϴ�.
    ```
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
    ```

    �������� perspective projection space�� viewport space������ ��ȯ�� ���� viewport�� ��µǴ� �ﰢ���� ��ǥ�� �����մϴ�.

    ���� �ﰢ���� �ѷ��δ� ���� ���� ũ���� �簢�� ���ο��� barycentric coordinate���� ��ȯ, depth ���� ����Ͽ� image_buffer�� �� pixel�� �ռ� ������ color ���� ����ֽ��ϴ�.
    ```
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
    ```

- Gouraud shading class

    �ʿ��� �������� �ʱ�ȭ�ϰ�, Gouraud shading class�� ���� �����ڿ� image�� �������� ���� get image �Լ�, flat_shading�� ���� �Լ��� �����մϴ�.
    ```
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
            // it goes on ...
        }
    };
    ```
    
    image buffer�� depth buffer�� ���� �ʱ�ȭ�մϴ�.
    ```
    image_buffer = new unsigned char[Nx * Ny * 3] ();
    for(int y = 0; y < Ny; y++) {
        for (int x = 0; x < Nx; x++) {
            depth_buffer[y * Nx + x] = -FLT_MAX;
        }
    }
    ```
    
    ���� scene�� �����ϰ�, ������ ���� ���� �����ɴϴ�.
    
    ```
    scene.create_scene();

    vertices_num = scene.get_num_vertices();
    triangles_num = scene.get_num_triangles();
    index_buffer = scene.get_index_buffer();
    vertices = scene.get_vertices();
    ```

    �� �ﰢ���� ���� �������� ��ǥ���� ���ϰ�, camera space���� ��ȯ�� ����, �� ���� ������ ��ǥ�� �ٽ� ����ֽ��ϴ�.
    ```
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
    ```

    ���� �� �������� ���Ͽ� color�� ���ϱ� ���� �������� �����ϰ�, color�� ����մϴ�.
    ```
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

        color_c.x = shader.ka.x * ambient_light.ia + shader.kd.x * ip * std::max(0.0f, dot(nc, lc)) + shader.ks.x * ip * pow(std::max(0.0f, dot(nc, hc)), shader.p);
        color_c.y = shader.ka.y * ambient_light.ia + shader.kd.y * ip * std::max(0.0f, dot(nc, lc)) + shader.ks.y * ip * pow(std::max(0.0f, dot(nc, hc)), shader.p);
        color_c.z = shader.ka.z * ambient_light.ia + shader.kd.z * ip * std::max(0.0f, dot(nc, lc)) + shader.ks.z * ip * pow(std::max(0.0f, dot(nc, hc)), shader.p);
    ```

    �� �������� color�� ���� ���Ŀ��� ��ǥ�� viewport space���� ��ȯ�ϰ�, �� ���� �ٽ� ��ǥ ������ �����մϴ�.
    
    ���� �ռ� �ٸ� class��� ���������� �ﰢ���� �ѷ��δ� ���� ���� �簢���� ã��, �� �簢���� ���ؼ� barycentric coordinate���� ��ȯ�ϴ� ������ �����մϴ�.

    ���������� depth ���� ����ϰ� color interpolation�� ���� shading�� �������ϰ�, �̸� image_buffer�� pixel ������ �����մϴ�.
    ```
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
    ```

- Phong shading class

    �ʿ��� �������� �ʱ�ȭ�ϰ�, Phong shading class�� ���� �����ڿ� image�� �������� ���� get image �Լ�, flat_shading�� ���� �Լ��� �����մϴ�.
    ```
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
            // it goes on ...
        }
    };
    ```

    ���� ���� �����ϰ� image buffer�� depth buffer�� �ʱ�ȭ�ϰ�, scene�� �����ϸ�, ������ ������ �ҷ��ɴϴ�.
    ```
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
    ```

    �������� �� �ﰢ���� ���Ͽ� �������� ��ǥ�� ���ϰ�, camera space ���������� ��ǥ ���� ��������, �����Ͽ�, �ش� ��ǥ������ normal vector�� ���մϴ�.
    ```
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
    ```

    ���� viewport space������ ��ȯ�� ���� �������� ��ǥ�� �ٽ� �����ϰ�, �ռ� �Լ���� �����ϰ� �ﰢ���� �ѷ��δ� �簢���� ����, �� ���ο��� barycentric coordinate������ ��ȯ�� ��Ĩ�ϴ�.

    depth�� ����Ͽ� ��� �������� ��ǥ���� normal vector ���� �ݿ��� color ���� ����Ͽ� image buffer�� �� pixel�� �����մϴ�.
    ```
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
    ```

    - main.cpp ������ �� ����� ���� â�� ���� ���� �����Դϴ�.

        main.cpp������ shader.cpp ������ �� �Լ����� �ҷ��� ȭ���� ����ϴ� ���� Ȱ���մϴ�.

        ���� �ݺ����� ���� ����ڷκ��� �Է��� �޾� �� �Է¿� �˸��� ������� �̹����� ����մϴ�.
    
---

## �����մϴ�.

##### ������: �Ǳ����б� ���п� ��ǻ�Ͱ��а� 202371451 ������