#pragma once
#include <GL/glew.h>
#include <GLFW/glfw3.h>

namespace Engine {
	namespace graphics {

		class Window
		{
		public:

			Window(const char *name, int width, int height);
			
			~Window();
			
			bool Closed() const;

			void Clear() const;

			void Update();

		private:

			bool init();

			const char* m_name;

			int m_width, m_height;

			bool m_closed;

			GLFWwindow* m_window;



		};


	}
}