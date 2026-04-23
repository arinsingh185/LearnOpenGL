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
	static void mouseCallback(GLFWwindow* window, double xpos, double ypos);
	void scroll_callback(GLFWwindow* window, double xOffset, double yOffset);

	void Init();

	void setHeight(int height);
	void setWidth(int width);
	//void processInput(GLFWwindow* window);

	//getter functions

	GLFWwindow* getWindow();
	int getHeight() const;
	int getWidth() const;



private:


	static glm::vec3 position;
	static glm::vec3 cameraFront;
	static glm::vec3 up;
	static float deltaTime;
	static float lastFrame;


	static bool firstMouse;
	static float yaw;
	static float pitch;
	static float lastX;
	static float lastY;
	static float fov;


	int width;
	int height;
	GLFWwindow* window;


};

#endif