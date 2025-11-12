#pragma 
#define ENGINE_H
#ifndef ENGINE_H

#include <glad/glad.h>

class Engine {
public:
	void render();

	void draw();


private:
	unsigned int VBO;
	unsigned int VAO;
	unsigned int EBO;


	unsigned int vertexShader;
	unsigned int fragmentShader;
	unsigned int shaderProgram;

	float vertices[];
};



#endif
