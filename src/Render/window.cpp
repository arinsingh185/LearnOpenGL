#include "window.h"


//void framebuffer_size_callback(GLFWwindow* window, int width, int height);

Window::Window() {
	setHeight(800);
	setWidth(600);
	position = glm::vec3(0.0f, 0.0f, 3.0f);
	cameraFront = glm::vec3(0.0f, 0.0f, -1.0f);
	up = glm::vec3(0.0f, 1.0f, 0.0f);
	deltaTime = 0.0f;
	lastFrame = 0.0f;

	firstMouse = true;
	yaw = 90.f;
	pitch = 0.0f;
	lastX = (float)(width) / 2.0f;
	lastY = (float)(height) / 2.0f;
	fov = 45.0f;
	Init();
}

Window::Window(int height, int width) {
	setHeight(height);
	setWidth(width);
	position = glm::vec3(0.0f, 0.0f, 3.0f);
	cameraFront = glm::vec3(0.0f, 0.0f, -1.0f);
	up = glm::vec3(0.0f, 1.0f, 0.0f);
	deltaTime = 0.0f;
	lastFrame = 0.0f;



	firstMouse = true;
	yaw = 90.f;
	pitch = 0.0f;
	lastX = (float)(width) / 2.0f;
	lastY = (float)(height) / 2.0f;
	fov = 45.0f;
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
	glfwSetCursorPosCallback(window, mouseCallback);
	//glfwSetScrollCallback(window, scroll_callback);

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

void Window::mouseCallback(GLFWwindow* window, double xpos, double ypos) {
	if (firstMouse) {
		lastX = xpos;
		lastY = ypos;
		firstMouse = false;
	}

	float xOffset = xpos - lastX;
	float yOffset = lastY - ypos;
	lastX = xpos;
	lastY = ypos;
	float sensitivity = 0.1f;
	xOffset *= sensitivity;
	yOffset *= sensitivity;

	yaw += xOffset;
	pitch += yOffset;

	if (pitch > 89.0) {
		pitch = 89.0;
	}
	if (pitch > -89.0) {
		pitch = -89.0;
	}

	glm::vec3 front;
	front.x = glm::cos(yaw) * glm::cos(pitch);
	front.y = glm::sin(pitch);
	front.z = glm::sin(yaw) * glm::cos(pitch);
	cameraFront = glm::normalize(front);

}

void Window::scroll_callback(GLFWwindow* window, double xOffset, double yOffset) {
	fov -= (float)yOffset;
	if (fov < 1.0) {
		fov = 1.0;
	}
	if (fov > 45.0) {
		fov = 45.0;
	}

}