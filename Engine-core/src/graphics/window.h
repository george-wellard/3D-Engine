#pragma once
#include <GL/glew.h>
#include <GLFW/glfw3.h>

#define MAX_KEYS 1024
#define MAX_BUTTONS 32

namespace Engine {
	namespace graphics {

		class Window
		{
		public:

			Window* INSTANCE; 

			Window(const char *name, int width, int height);
			
			~Window();
			
			bool Closed() const;

			bool isKeyPressed(unsigned int keycode) const;

			bool isButtonPressed(unsigned int button) const;

			void getMousePosition(double &x, double &y) const;

			void Clear() const;

			void Update();

		private:

			const char* m_name;

			int m_width, m_height;

			bool m_closed;

		    bool m_keys[MAX_KEYS];
		    bool m_buttons[MAX_BUTTONS];
		    double mX, mY;

			GLFWwindow* m_window;

			bool init();

			friend static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods);
			friend static void button_callback(GLFWwindow* window, int button, int action, int mods);
			friend static void cursor_pos_callback(GLFWwindow* window, double xpos, double ypos);


		};


	}
}