#ifndef WINDOW_H
#define WINDOW_H

#include "glad/glad.h"
#include <GLFW/glfw3.h>
#include <iostream>
#include "shader.h"


class Window {
public:
	Window();
	Window(int height, int width);
	static void framebuffer_size_callback(GLFWwindow* window, int height, int width);

	void Init();

	void setHeight(int height);
	void setWidth(int width);
	void processInput(GLFWwindow* window);

	//getter functions
	GLFWwindow* getWindow();
	int getHeight() const;
	int getWidth() const;
private:
	int width;
	int height;
	GLFWwindow* window;
};

#endif