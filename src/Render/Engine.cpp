#include "Engine.h"


//void framebuffer_size_callback(GLFWwindow* window, int width, int height);

Engine::Engine() {
	setHeight(800);
	setWidth(600);

	Init();
}

Engine::Engine(int height, int width) {
	setHeight(height);
	setWidth(width);

	Init();
}

void Engine::Init() {
	//initialie glfw and set the version and the render api being used
	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	//glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);

	//initialize the actual window and make the context of our window the main context on the current thread
	window = glfwCreateWindow(height, width, "LearnOpenGL", NULL, NULL);
	if (window == NULL)
	{
		std::cout << "Failed to create GLFW window" << std::endl;
		glfwTerminate();
	}
	glfwMakeContextCurrent(window);
	glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

	//initalize GLAD to be able to manage openGL function pointers
	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
		std::cout << "Failed to initialize GLAD" << std::endl;
	}

	glViewport(0, 0, height, width);
}



void Engine::setHeight(int height) {
	this->height = height;
}

void Engine::setWidth(int width) {
	this->width = width;
}

int Engine::getHeight() const {
	return height;
}

int Engine::getWidth() const {
	return width;
}

GLFWwindow* Engine::getWindow() {
	return glfwGetCurrentContext();
}

void Engine::framebuffer_size_callback(GLFWwindow* window, int width, int height) {
	glViewport(0, 0, width, height);
}

void Engine::processInput(GLFWwindow* window) {
	if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS) {
		glfwSetWindowShouldClose(window, true);
	}
}