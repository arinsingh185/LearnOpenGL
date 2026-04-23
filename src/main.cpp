#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include <cmath>
#include <shader.h>
#include "Render/Window.h"
#include "STB_IMAGE/stb_image.h"
#include<glm/glm.hpp>
#include<glm/gtc/matrix_transform.hpp>
#include<glm/gtc/type_ptr.hpp>



int main() {

	     unsigned int VBO, VAO, EBO;

		
		int width, height, nrChannels;

		unsigned int texture1, texture2;
		
		Window window(1920, 1080);


		Shader ourShader("C:/Users/Mirik/source/repos/LearnOpenGL/src/Shader/Shader.vert", "C:/Users/Mirik/source/repos/LearnOpenGL/src/Shader/Shader.frag");

		//glm::vec3 cameraPos = glm::vec3(0.0f, 0.0f, 0.3f);
		//glm::vec3 cameraTarget = glm::vec3(0.0f, 0.0f, 0.0f);
		//glm::vec3 cameraDirection = glm::vec3(cameraPos - cameraTarget);
		//glm::vec3 up = glm::vec3(0.0f, 1.0f, 0.0f);
		//glm::vec3 cameraRight = glm::vec3(glm::cross(up, cameraDirection));
		//glm::vec3 cameraUp = glm::cross(cameraDirection, cameraRight);
		/*glm::mat4 view{};
		view = glm::lookAt(glm::vec3(0.0f, 0.0f, 3.0f),
			              glm::vec3(0.0f, 0.0f, 0.0f),
			              glm::vec3(0.0f, 1.0f, 3.0f));
					    */



		float vertices[] = {
		-0.5f, -0.5f, -0.5f,  0.0f, 0.0f,
		0.5f, -0.5f, -0.5f,  1.0f, 0.0f,
		0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
		0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
		-0.5f,  0.5f, -0.5f,  0.0f, 1.0f,
		-0.5f, -0.5f, -0.5f,  0.0f, 0.0f,

		-0.5f, -0.5f,  0.5f,  0.0f, 0.0f,
		0.5f, -0.5f,  0.5f,  1.0f, 0.0f,
		0.5f,  0.5f,  0.5f,  1.0f, 1.0f,
		0.5f,  0.5f,  0.5f,  1.0f, 1.0f,
		   -0.5f,  0.5f,  0.5f,  0.0f, 1.0f,
		   -0.5f, -0.5f,  0.5f,  0.0f, 0.0f,

		  -0.5f,  0.5f,  0.5f,  1.0f, 0.0f,
		  -0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
		  -0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
		  -0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
		 -0.5f, -0.5f,  0.5f,  0.0f, 0.0f,
		 -0.5f,  0.5f,  0.5f,  1.0f, 0.0f,

		0.5f,  0.5f,  0.5f,  1.0f, 0.0f,
		0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
		0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
		0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
		0.5f, -0.5f,  0.5f,  0.0f, 0.0f,
		0.5f,  0.5f,  0.5f,  1.0f, 0.0f,

		 -0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
		0.5f, -0.5f, -0.5f,  1.0f, 1.0f,
		0.5f, -0.5f,  0.5f,  1.0f, 0.0f,
		0.5f, -0.5f,  0.5f,  1.0f, 0.0f,
		 -0.5f, -0.5f,  0.5f,  0.0f, 0.0f,
		-0.5f, -0.5f, -0.5f,  0.0f, 1.0f,

		 -0.5f,  0.5f, -0.5f,  0.0f, 1.0f,
		0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
		0.5f,  0.5f,  0.5f,  1.0f, 0.0f,
		0.5f,  0.5f,  0.5f,  1.0f, 0.0f,
		 -0.5f,  0.5f,  0.5f,  0.0f, 0.0f,
		-0.5f,  0.5f, -0.5f,  0.0f, 1.0f
		};
		
		glm::vec3 cubePositions[] = {
			glm::vec3(0.0f,  0.0f,  0.0f),
			glm::vec3(-2.0f,  0.0f, -15.0f),
			glm::vec3(-1.5f, -2.2f, -2.5f),
			glm::vec3(-3.8f, -2.0f, -12.3f),
			glm::vec3(2.4f, -0.4f, -3.5f),
			glm::vec3(-1.7f,  3.0f, -7.5f),
			glm::vec3(1.3f, -2.0f, -2.5f),
			glm::vec3(1.5f,  2.0f, -2.5f),
			glm::vec3(1.5f,  0.2f, -1.5f),
			glm::vec3(-1.5f,  -0.75f, -1.5f),
			glm::vec3(-1.3f,  1.0f, -1.5f)
		};

		unsigned int indices[] = {
	     0, 1, 3, 
	     1, 2, 3  
		};


		glGenVertexArrays(1, &VAO);
		glGenBuffers(1, &VBO);
		glGenBuffers(1, &EBO);
		
	

		glBindVertexArray(VAO);
		


		glBindBuffer(GL_ARRAY_BUFFER, VBO);
		
		glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
		glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

	
		glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)0);
		glEnableVertexAttribArray(0);
	
		glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)(3 * sizeof(float)));
		glEnableVertexAttribArray(1);


		stbi_set_flip_vertically_on_load(true);

		glGenTextures(1, &texture1);
		

		glBindTexture(GL_TEXTURE_2D, texture1);
	
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_NEAREST);	
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_NEAREST);
	
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
		

	
		unsigned char* data = stbi_load("C:/Users/Mirik/source/repos/LearnOpenGL/Textures/container.jpg", &width, &height, &nrChannels, 0);
		if (data)
		{
			glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
			glGenerateMipmap(GL_TEXTURE_2D);
		}
		else
		{
			std::cout << "Failed to load texture" << std::endl;
		}

		stbi_image_free(data);

		glGenTextures(1, &texture2);
		glBindTexture(GL_TEXTURE_2D, texture2);


		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

		data = stbi_load("C:/Users/Mirik/source/repos/LearnOpenGL/Textures/breakfast.png", &width, &height, &nrChannels, 0);
		
		if (data) {
			glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, data);
			glGenerateMipmap(GL_TEXTURE_2D);
		}
		else {
			std::cout << "Failed to generate texture" << std::endl;
		}
		
		stbi_image_free(data);
		

		ourShader.use();
		glUniform1i(glGetUniformLocation(ourShader.ID, "texture1"), 0);
		ourShader.setInt("texture1", 0);
		ourShader.setInt("texture2", 1);



		glEnable(GL_DEPTH_TEST);

	

		//render loop
		while (!glfwWindowShouldClose(window.getWindow())){


			//input
			window.processInput(window.getWindow());
			
			//render code...
			
			glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
			glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

			glActiveTexture(GL_TEXTURE0);
			glBindTexture(GL_TEXTURE_2D, texture1);

			glActiveTexture(GL_TEXTURE1);
			glBindTexture(GL_TEXTURE_2D, texture2);


			ourShader.use();



			glm::mat4 view = glm::mat4(1.0f);
			float radius = 20;
			float camX = ((sin(glfwGetTime()) * radius));
			float camZ = (cos(glfwGetTime()) * radius);
			view = glm::lookAt(glm::vec3(camX, 0.0f, camZ), 
						    glm::vec3(0.0f, 0.0f, 0.0f), 
						    glm::vec3(0.0f, 1.0f, 0.0f));
			ourShader.setMat4("view", view);

			glm::mat4 projection{};
			projection = glm::perspective(glm::radians(45.0f), (float)window.getHeight() / (float)window.getWidth(), 0.1f, 1000.0f);
			//projection = glm::ortho(0.0f, (float)window.getWidth(), (float)window.getHeight(), 0.0f, -100.0f, 100.0f);


			ourShader.setMat4("projection", projection);
	
			glBindVertexArray(VAO);


			for (unsigned int i{ 0 }; i < 11; i++) {
				glm::mat4 model{ glm::mat4(1.0f) };
				model = glm::translate(model, cubePositions[i]);
				float angle = 20.0 * i;
				if (i % 3 == 0) {
					model = glm::rotate(model, (float)glfwGetTime() * glm::radians(angle + 20), glm::vec3(0.0f, 0.3f, 0.5f));
				}
				ourShader.setMat4("model", model);

				glDrawArrays(GL_TRIANGLES, 0, 36);
			}


			glDrawArrays(GL_TRIANGLES, 0, 36);


		
			//check and call events and then swap the buffer
			glfwPollEvents();
			glfwSwapBuffers(window.getWindow());
			
		}

		glDeleteVertexArrays(1, &VAO);
		glDeleteBuffers(1, &VBO);
		glDeleteBuffers(1, &EBO);

		glfwTerminate();


		return 0;

	}