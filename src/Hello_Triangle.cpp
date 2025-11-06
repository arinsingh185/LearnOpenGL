#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>




void framebuffer_size_callback(GLFWwindow* window, int width, int height);

void processInput(GLFWwindow* window);

const char* vertexShaderSource1 = "#version 330 core\n"
"layout (location = 0) in  vec3 aPos;\n"
"void main()\n"
"{\n"
"    gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);\n"
"}\0";
const char* fragmentShaderSource1 = "#version 330 core\n"
"out vec4 FragColor;\n"
"void main()\n"
"{\n"
"FragColor = vec4(1.0f, 0.5f, 0.5f, 1.0f);\n"
"}\n\0";

const char* vertexShaderSource2 = "#version 330 core\n"
"layout (location = 1) in  vec3 aPos;\n"
"void main()\n"
"{\n"
"    gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);\n"
"}\0";
const char* fragmentShaderSource2 = "#version 330 core\n"
"out vec4 FragColor;\n"
"void main()\n"
"{\n"
"FragColor = vec4(0.9f, 0.9f, 0.5f, 1.0f);\n"
"}\n\0";

int main() {

	
	GLuint vertexShader[2];
	GLuint fragmentShader[2];
	GLuint shaderProgram[2];

	GLuint VBOs[2];
	GLuint VAOs[2];
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

	shaderProgram[0] = glCreateProgram();
	shaderProgram[1] = glCreateProgram();

	vertexShader[0] = glCreateShader(GL_VERTEX_SHADER);

	glShaderSource(vertexShader[0], 1, &vertexShaderSource1, NULL);
	glCompileShader(vertexShader[0]);

	fragmentShader[0] = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(fragmentShader[0], 1, &fragmentShaderSource1, NULL);
	glCompileShader(fragmentShader[0]);

	glAttachShader(shaderProgram[0], vertexShader[0]);
	glAttachShader(shaderProgram[0], fragmentShader[0]);
	glLinkProgram(shaderProgram[0]);

	vertexShader[1] = glCreateShader(GL_VERTEX_SHADER);
	glShaderSource(vertexShader[1], 1, &vertexShaderSource2, NULL);
	glCompileShader(vertexShader[1]);

	fragmentShader[1] = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(fragmentShader[1], 1, &fragmentShaderSource2, NULL);
	glCompileShader(fragmentShader[1]);

	

	glAttachShader(shaderProgram[1], vertexShader[1]);
	glAttachShader(shaderProgram[1], fragmentShader[1]);
	glLinkProgram(shaderProgram[1]);



	glDeleteShader(vertexShader[0]);
	glDeleteShader(fragmentShader[0]);

	glDeleteShader(vertexShader[1]);
	glDeleteShader(fragmentShader[1]);







	float first_Triangle[] = {
		0.0f, -0.2f, 0.0f,
		-0.2f, 0.2f, 0.0f,
		-0.4f, -0.2f, 0.0f,

	};

	float second_Triangle[]{
		0.6f, -0.5f, 0.0f,
		0.3f, 0.2f, 0.0f,
		0.0f, -0.5f, 0.0f,
	};

	

	glGenBuffers(2 ,VBOs);
	glGenVertexArrays(2, VAOs);

	glBindVertexArray(VAOs[0]);

	glBindBuffer(GL_ARRAY_BUFFER, VBOs[0]);
	glBufferData(GL_ARRAY_BUFFER, sizeof(first_Triangle), first_Triangle, GL_STATIC_DRAW);

	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);


	glBindVertexArray(VAOs[1]);

	glBindBuffer(GL_ARRAY_BUFFER, VBOs[1]);
	glBufferData(GL_ARRAY_BUFFER, sizeof(second_Triangle), second_Triangle, GL_STATIC_DRAW);

	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(1);

	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);





	//render loop
	while (!glfwWindowShouldClose(window)) {


		//input
		processInput(window);

		//render code...
		glClearColor(0.2f, 0.5f, 0.6f, 0.3f);
		glClear(GL_COLOR_BUFFER_BIT);

		glUseProgram(shaderProgram[0]);

		glBindVertexArray(VAOs[0]);
		glDrawArrays(GL_TRIANGLES, 0, 3);

		glUseProgram(shaderProgram[1]);

		glBindVertexArray(VAOs[1]);
		glDrawArrays(GL_TRIANGLES, 0, 3);

		glBindVertexArray(0);

		//check and call events and then swap the buffer
		glfwPollEvents();
		glfwSwapBuffers(window);

	}
	glfwTerminate();


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