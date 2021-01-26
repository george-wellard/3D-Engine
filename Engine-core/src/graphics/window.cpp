#include "window.h"
#include <iostream>

namespace Engine {
	namespace graphics {

		void windowResize(GLFWwindow* window, int width, int height);
		void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods);
		void button_callback(GLFWwindow* window, int button, int action, int mods);
		void cursor_pos_callback(GLFWwindow* window, double xpos, double ypos);

		Window::Window(const char* name, int width, int height)
		{
			m_name = name;
			m_width = width;
			m_height = height;
			if (!init())
			{
				glfwTerminate();

				for (int i = 0; i < MAX_KEYS; i++)
				{
					m_keys[i] = false;
				}

				for (int i = 0; i < MAX_BUTTONS; i++)
				{
					m_buttons[i] = false;
				}
			}

		}

		Window::~Window()
		{
		}

		bool Window::Closed() const
		{
			return glfwWindowShouldClose(m_window);
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
			glfwSetWindowUserPointer(m_window, this);
			glfwSetWindowSizeCallback(m_window, windowResize);
			glfwSetKeyCallback(m_window, key_callback);
			glfwSetMouseButtonCallback(m_window, button_callback);
			glfwSetCursorPosCallback(m_window, cursor_pos_callback);

			if (glewInit() != GLEW_OK)
			{
				std::cout << "GLEW intilization failed" << std::endl;
				return false;
			}

			std::cout << glGetString(GL_VERSION) << std::endl;

			return true;

		}

		bool Window::isKeyPressed(unsigned int keycode) const
		{
			if (keycode >= MAX_KEYS)
			{
				return false;
			}

			return m_keys[keycode];
		}

		bool Window::isButtonPressed(unsigned int button) const
		{
			if (button >= MAX_BUTTONS)
			{
				return false;
			}

			return m_buttons[button];
		}

		void Window::getMousePosition(double &x, double &y) const
		{
			x = mX;
			y = mY;
		}

		void Window::Clear() const
		{
			glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		}

		void windowResize(GLFWwindow* window, int width, int height)
		{
			glViewport(0, 0, width, height);
		}

		void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
		{
			Window * win = (Window*) glfwGetWindowUserPointer(window);
			win->m_keys[key] = action != GLFW_RELEASE;
		}

		void button_callback(GLFWwindow* window, int button, int action, int mods)
		{
			Window* win = (Window*)glfwGetWindowUserPointer(window);
			win->m_buttons[button] = action != GLFW_RELEASE;
		}

		void cursor_pos_callback(GLFWwindow* window, double xpos, double ypos)
		{
			Window* win = (Window*)glfwGetWindowUserPointer(window);
			win->mX = xpos;
			win->mY = ypos;
		}

		void Window::Update()
		{
			glfwPollEvents();
			glfwSwapBuffers(m_window);
		}

	}
}