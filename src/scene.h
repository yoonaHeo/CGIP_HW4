#ifndef SCENE_H
#define SCENE_H

#define _USE_MATH_DEFINES

#include <stdio.h>
#include <math.h>
#include <glm/glm.hpp>

using namespace glm;

class Scene {
private:
    int     gNumVertices    = 0;    // Number of 3D vertices.
    int     gNumTriangles   = 0;    // Number of triangles.
    int*    gIndexBuffer    = nullptr; // Vertex indices for the triangles.
    vec3*    vertices = nullptr; // Vertices of the triangles.
    
public:
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

    void create_scene()
    {
        // divided into width and height segments
        int width   = 32;
        int height  = 16;
        
        float theta, phi;
        int t;  // t for indexing vertices
        
        // calculate the number of vertices and triangles
        gNumVertices    = (height - 2) * width + 2;
        gNumTriangles   = (height - 2) * (width - 1) * 2;
        
        // allocate memory for the vertices array
        vertices = new vec3[gNumVertices];

        // allocate memory for the gIndexBuffer, which represents vertices of the triangles
        gIndexBuffer    = new int[3*gNumTriangles];
        
        // integer t is for the vertices in gIndexBuffer
        t = 0;

        // create vertices of the sphere
        for (int j = 1; j < height-1; ++j)
        {
            // int j means the height of the sphere
            for (int i = 0; i < width; ++i)
            // int i means the width of the sphere
            {
                // calculate the theta and phi
                // theta means latitude
                // phi means longitude
                theta = (float) j / (height-1) * M_PI;
                phi   = (float) i / (width-1)  * M_PI * 2;
                
                // calculate the x, y, z
                // x means the x-coordinate of the sphere
                // y means the y-coordinate of the sphere
                // z means the z-coordinate of the sphere
                float   x   = sinf(theta) * cosf(phi);
                float   y   = cosf(theta);
                float   z   = -sinf(theta) * sinf(phi);
                
                // record vertices in array
                vertices[t] = vec3(x, y, z);

                t++;
            }
        }

        vertices[t++] = vec3(0, 1, 0);

        vertices[t++] = vec3(0, -1, 0);

        t = 0;

        for (int j = 0; j < height-3; ++j)
        {
            for (int i = 0; i < width-1; ++i)
            {
                gIndexBuffer[t++] = j*width + i;
                gIndexBuffer[t++] = (j+1)*width + (i+1);
                gIndexBuffer[t++] = j*width + (i+1);
                gIndexBuffer[t++] = j*width + i;
                gIndexBuffer[t++] = (j+1)*width + i;
                gIndexBuffer[t++] = (j+1)*width + (i+1);
            }
        }
        for (int i = 0; i < width-1; ++i)
        {
            gIndexBuffer[t++] = (height-2)*width;
            gIndexBuffer[t++] = i;
            gIndexBuffer[t++] = i + 1;
            gIndexBuffer[t++] = (height-2)*width + 1;
            gIndexBuffer[t++] = (height-3)*width + (i+1);
            gIndexBuffer[t++] = (height-3)*width + i;
        }
        
        // The index buffer has now been generated. Here's how to use to determine
        // the vertices of a triangle. Suppose you want to determine the vertices
        // of triangle i, with 0 <= i < gNumTriangles. Define:
        //
        // k0 = gIndexBuffer[3*i + 0]
        // k1 = gIndexBuffer[3*i + 1]
        // k2 = gIndexBuffer[3*i + 2]
        //
        // Now, the vertices of triangle i are at positions k0, k1, and k2 (in that
        // order) in the vertex array (which you should allocate yourself at line
        // 27).
        //
        // Note that this assumes 0-based indexing of arrays (as used in C/C++,
        // Java, etc.) If your language uses 1-based indexing, you will have to
        // add 1 to k0, k1, and k2.
    }
};

#endif // SCENE_H