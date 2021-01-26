#include <iostream>
#include "src/graphics/window.h"

int main()
{
	using namespace Engine; 

	using namespace graphics;

	Window window("Engine", 960, 540);
	glClearColor(0.2f, 0.3f, 0.8f, 1.0f);

	GLuint vao;
	glGenVertexArrays(1, &vao);
	glBindVertexArray(vao);

	while (!window.Closed())
	{
		window.Clear(); 
		if (window.isKeyPressed(GLFW_KEY_A))
		{	
			std::cout << "PRESSED KEY" << std::endl;
		}

		if (window.isButtonPressed(GLFW_MOUSE_BUTTON_LEFT))
		{
			std::cout << "PRESSED BUTTON" << std::endl;
		}

		double x, y;
		window.getMousePosition(x, y);
		std::cout << x << ", " << y << std::endl;

		glBegin(GL_QUADS);
		glVertex2f(-0.5f, -0.5f);
		glVertex2d(-0.5f, 0.5f);
		glVertex2f(0.5f, 0.5f);
		glVertex2f(0.5f, -0.5f);
		glEnd();

		//glDrawArrays(GL_ARRAY_BUFFER, 0, 0);
		window.Update();
	}

	return 0; 
}