#ifndef WINDOW_H
#define WINDOW_H

#include "glad/glad.h"
#include <GLFW/glfw3.h>
#include <iostream>
#include "shader.h"
#include "camera.h"


class Window {
public:
	Window();
	Window(int height, int width);
	static void framebuffer_size_callback(GLFWwindow* window, int height, int width);

	void Init();

	void setHeight(int height);
	void setWidth(int width);
	//void processInput(GLFWwindow* window);

	//getter functions

	GLFWwindow* getWindow();
	int getHeight() const;
	int getWidth() const;

	static void mouse_callback(GLFWwindow* window, double xpos, double ypos);
	static void scroll_callback(GLFWwindow* window, double xOffset, double yOffset);

private:




	int width;
	int height;
	GLFWwindow* window;

};

#endif