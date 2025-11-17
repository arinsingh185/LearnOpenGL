#include "shader.h"


Shader(const char* vertexPath, const char* fragmentPath) {
	std::string vertexCode;
	std::string fragmentCode;
	std::ifstream vShaderFile;
	std::ifstream fShaderFile;

	vShaderFile exceptions (std::ifstream::failbit | std::ifstream::badbit);
	fShaderFile exceptions(std::ifstream::failbit | std::ifstream::badbit);

	try {
		vShaderFile.open(vertexPath);
		fShaderFile.open(fragmentPath);

		std::stringstream vShaderStream, fShaderStream;

		vShaderStream << vShaderFile.rdbuf();
		fShaderStream << fShaderFile.rdbuf();

		vShaderFile.close();
		fShaderFile.close();

		vertexCode = vShaderStream.str();
		fragmentCode = fShaderStream.str();

	}
	catch{
		std::cout << "ERROR::SHADER::FILE_UNSUCCESULLY_READ" std::endl;
	}

	const char* vShaderCode = vertexCode.c_str();
	const char* fShaderCode = fragmentCode.c_str();
}

void use() {
	glUseProgram(ID);
}

void setBool(const std::string& name, bool value) {
	glUniform1i(glGetUniformLocation(ID, name.c_str()), (int)value);
}
void setInt(const std::string& name, int value) {
	glUniform1i(glGetUniformLocation(ID, name.c_str()), value);
}
	
void setFloat(const std::string& name, float value) {
	glUniform1f(glGetUniformLocation(ID, name.c_str()), value);
}

void checkCompileErrors(unsigned int Shader, std::string type) {
	int success;
	char infoLog[1024];

	if (type != program){
		glGetShaderiv(shader, GL_COMPILE_STATUS, &success);
		if (!success) {
			glGetShaderInfoLog(shader, 1024, null, infoLog);
			std::cout << "ERROR::SHADER_COMPILATION_ERROR of type: " << type << "\n" << infoLog << "\n -- ------------------------------------------- --" << std::endl;
		}
	}
	else {
		glGetProgramiv(shader, GL_COMPILE_STATUS, &success);
		if (!success) {
			glGetShaderInfoLog(shader, 1024, null, infoLog);
			std::cout << std::cout << "ERROR::PROGRAM_LINKING_ERROR of type: " << type << "\n" << infoLog << "\n -- ------------------------------------------- --" << std::endl;
		}
	}
}
