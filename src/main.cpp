#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>




void framebuffer_size_callback(GLFWwindow* window, int width, int height);

void processInput(GLFWwindow* window);

int main(){
		//initialie glfw and set the version and the render api being used
		glfwInit();
		glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
		glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
		glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
		//glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);

		//initialize the actual window and make the context of our window the main context on the current thread
		GLFWwindow* window = glfwCreateWindow(800, 600, "LearnOpenGL", NULL, NULL);
		if (window == NULL)
		{
			std::cout << "Failed to create GLFW window" << std::endl;
			glfwTerminate();
			return -1;
		}
		glfwMakeContextCurrent(window);

		//initalize GLAD to be able to manage openGL function pointers
		if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
			std::cout << "Failed to initialize GLAD" << std::endl;
			return -1;
		}
		
		glViewport(0, 0, 800, 600);

		

		glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

		//render loop
		while (!glfwWindowShouldClose(window)) {


			//input
			processInput(window);

			//render code...
			glClearColor(0.2f, 0.5f, 0.6f, 0.3f);
			glClear(GL_COLOR_BUFFER_BIT);


			//check and call events and then swap the buffer
			glfwPollEvents();
			glfwSwapBuffers(window);
			
		}
		glfwTerminate();
		return 0;

		return 0;
	}

	void framebuffer_size_callback(GLFWwindow* window, int width, int height) {
		glViewport(0, 0, width, height);
	}

	void processInput(GLFWwindow* window) {
		if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS) {
			glfwSetWindowShouldClose(window, true);
		}
	}