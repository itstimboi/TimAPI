#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>

#include "Window.h"

namespace TAPI
{
	struct Window
	{
		void* Handle;
	};

	bool Init()
	{
		if (!glfwInit())
		{
			std::cout << "Error initializing GLFW" << std::endl << "Closing..." << std::endl;
			return false;
		}

		return true;
	}
	
	void DeInit()
	{
		glfwTerminate();
	}

	Window* InitWindow(int windowWidth, int windowHeight, const std::string& Title)
	{
		Window* window = new Window;

		GLFWwindow* window1 = glfwCreateWindow(windowWidth, windowHeight, Title.c_str(), nullptr, nullptr);

		if (window1 == nullptr)
		{
			std::cout << "Error initializing Window" << std::endl << "Closing..." << std::endl;
			delete window;
			return nullptr;
		}

		window->Handle = window1;

		glfwMakeContextCurrent(window1);

		return window;
	}
	
	void DestroyWindow(Window* window)
	{
		if (window == nullptr)
			return;

		GLFWwindow* glfwWindow = static_cast<GLFWwindow*>(window->Handle);

		glfwDestroyWindow(glfwWindow);

		delete window;
	}
}