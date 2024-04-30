
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>

#include <iostream>
#include <algorithm>

#include "shader.cpp"

using namespace glm;
using namespace std;

    unsigned char* image_buffer;
    unsigned char* depth_buffer;

int main() {
    string shading_type;

    while (true) {
        cout << "To see results, please enter: " << endl;
        cout << "1. Unshaded" << endl;
        cout << "2. Flat shading" << endl;
        cout << "3. Gouraud shading" << endl;
        cout << "4. Phong shading" << endl;
        cout << "0. Exit" << endl;

        cin >> shading_type;
        
        glfwInit();
        GLFWwindow* window;

        if (shading_type[0] == '1') {
            Unshaded unshade;
            unshade.unshaded();
            
            image_buffer = unshade.get_image();
            window = glfwCreateWindow(WINDOW_WIDTH, WINDOW_HEIGHT, "CGIP HW4 Result (a)", nullptr, nullptr);
        } else if (shading_type[0] == '2') {
            Flat_shading flatshading;
            flatshading.flat_shading();

            image_buffer = flatshading.get_image();
            window = glfwCreateWindow(WINDOW_WIDTH, WINDOW_HEIGHT, "CGIP HW4 Result (b)", nullptr, nullptr);
        } else if (shading_type[0] == '3') {            
            Gouraud_shading gouraudshading;
            gouraudshading.gouraud_shading();

            image_buffer = gouraudshading.get_image();
            window = glfwCreateWindow(WINDOW_WIDTH, WINDOW_HEIGHT, "CGIP HW4 Result (c)", nullptr, nullptr);
        } else if (shading_type[0] == '4') {
            Phong_shading phongshading;
            phongshading.phong_shading();

            image_buffer = phongshading.get_image();
            window = glfwCreateWindow(WINDOW_WIDTH, WINDOW_HEIGHT, "CGIP HW4 Result (d)", nullptr, nullptr);
        } else if (shading_type[0] == '0') {
            break;
        } else {
            cout << "Please enter a valid option" << endl;
            continue;
        }
        
        
        if (window == nullptr) {
            cout << "Failed to create GLFW window" << endl;
            glfwTerminate();
            return -1;
        }

        glfwMakeContextCurrent(window);

        if(!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
            cout << "Failed to initialize GLAD" << endl;
            return -1;
        }

        while(!glfwWindowShouldClose(window)) {
            // input
            glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
            glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

            // Draw the sphere pixel by pixel
            glDrawPixels(Nx, Ny, GL_RGB, GL_UNSIGNED_BYTE, image_buffer);
            
            // check and call events and swap the buffers
            glfwSwapBuffers(window);
            glfwPollEvents();
        }
        
        glfwTerminate();
    }
    return 0;
}