#include "window.h"
#include <iostream>

namespace Engine {
	namespace graphics {

		void windowResize(GLFWwindow* window, int width, int height);

		Window::Window(const char* name, int width, int height)
		{
			m_name = name;
			m_width = width;
			m_height = height;
			if (!init())
			{
				glfwTerminate();
			}
		}

		Window::~Window()
		{
		}

		bool Window::Closed() const
		{
			return glfwWindowShouldClose(m_window);
		}

		void Window::Clear() const
		{
			glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		}


		bool Window::init()
		{
			if (!glfwInit())
			{
				std::cout << "GLFW Falied" << std::endl;
				return false;
			}

			m_window = glfwCreateWindow(m_width, m_height, m_name, NULL, NULL);
			if (!m_window)
			{
				glfwTerminate();
				std::cout << "GLFW Window failed" << std::endl;
				return false;
			}

			glfwMakeContextCurrent(m_window);
			glfwSetWindowSizeCallback(m_window, windowResize);

			if (glewInit() != GLEW_OK)
			{
				std::cout << "GLEW intilization failed" << std::endl;
				return false;
			}

			std::cout << glGetString(GL_VERSION) << std::endl;

			return true;

		}

		void windowResize(GLFWwindow* window, int width, int height)
		{
			glViewport(0, 0, width, height);
		}

		void Window::Update()
		{
			glfwPollEvents();
	//		glfwGetFramebufferSize(m_window, &m_width, &m_height);
			glfwSwapBuffers(m_window);
		}

	}
}