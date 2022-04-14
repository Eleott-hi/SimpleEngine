#ifdef __gl_h_
#else
#include <glad/glad.h>
#endif // __gl_h_
#include <GLFW/glfw3.h>
#include "SimpleEngineCore/Log.hpp"
#include "SimpleEngineCore/Application.hpp"
#include <iostream>




namespace SimpleEngine {

    Application::Application() {
        LOG_INFO("Welcome to spdlog!");
        LOG_WARN("Some error message with arg: {}", 1);

        LOG_ERROR("Easy padding in numbers like {:08d}", 12);
        LOG_CRITICAL("Support for int: {0:d};  hex: {0:x};  oct: {0:o}; bin: {0:b}", 42);
       }
    Application::~Application() {}

	int Application::start(unsigned int widow_width, unsigned int window_height, const char* title) {
        GLFWwindow* window;

        /* Initialize the library */
        if (!glfwInit())
            return -1;

        /* Create a windowed mode window and its OpenGL context */
        window = glfwCreateWindow(widow_width, window_height, title, NULL, NULL);
        if (!window)
        {
            glfwTerminate();
            return -1;
        }

        /* Make the window's context current */
        glfwMakeContextCurrent(window);


        if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
        {
            LOG_CRITICAL("Faild to initialize GLAD");
            return -1;
        } 

        glClearColor(1, 0, 0, 0);

        /* Loop until the user closes the window */
        while (!glfwWindowShouldClose(window))
        {
            /* Render here */
            glClear(GL_COLOR_BUFFER_BIT);

            /* Swap front and back buffers */
            glfwSwapBuffers(window);

            /* Poll for and process events */
            glfwPollEvents();

           //on_update();
        }

        glfwTerminate();

        return 0;

	}

}