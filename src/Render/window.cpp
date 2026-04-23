#include "window.h"


//void framebuffer_size_callback(GLFWwindow* window, int width, int height);

Window::Window() {
	setHeight(800);
	setWidth(600);

	Init();
}

Window::Window(int height, int width) {
	setHeight(height);
	setWidth(width);

	Init();
}

void Window::Init() {
	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	window = glfwCreateWindow(height, width, "LearnOpenGL", NULL, NULL);
	if (window == NULL)
	{
		std::cout << "Failed to create GLFW window" << std::endl;
		glfwTerminate();
	}
	glfwMakeContextCurrent(window);
	glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);


	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
		std::cout << "Failed to initialize GLAD" << std::endl;
	}

	glViewport(0, 0, height, width);
}



void Window::setHeight(int height) {
	this->height = height;
}

void Window::setWidth(int width) {
	this->width = width;
}

int Window::getHeight() const {
	return height;
}

int Window::getWidth() const {
	return width;
}

GLFWwindow* Window::getWindow() {
	return glfwGetCurrentContext();
}

void Window::framebuffer_size_callback(GLFWwindow* window, int width, int height) {
	glViewport(0, 0, width, height);
}

void Window::processInput(GLFWwindow* window) {
	if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS) {
		glfwSetWindowShouldClose(window, true);
	}
}