#include "Shader.h"

Shader::Shader(const std::string& vertexCode, const std::string& fragmentCode) : ID() {
	initializeOpenGLFunctions();
	this->CreateShader(vertexCode, fragmentCode);
}

Shader::~Shader() {
	glDeleteProgram(this->ID);
}

void Shader::CreateShader(const std::string& vertexCode, const std::string& fragmentCode) {
	const char* vertexCode_c_str{ vertexCode.c_str() };
	GLuint vertexShader{ glCreateShader(GL_VERTEX_SHADER) };
	glShaderSource(vertexShader, 1, &vertexCode_c_str, nullptr);
	glCompileShader(vertexShader);

	const char* fragmentCode_c_str{ fragmentCode.c_str() };
	GLuint fragmentShader{ glCreateShader(GL_FRAGMENT_SHADER) };
	glShaderSource(fragmentShader, 1, &fragmentCode_c_str, nullptr);
	glCompileShader(fragmentShader);

	this->ID = glCreateProgram();
	glAttachShader(this->ID, vertexShader);
	glAttachShader(this->ID, fragmentShader);
	glLinkProgram(this->ID);

	glDeleteShader(vertexShader);
	glDeleteShader(fragmentShader);
}

void Shader::use() {
	glUseProgram(this->ID);
}

void Shader::setMat4(const std::string& name, glm::mat4 value) {
	glUniformMatrix4fv(glGetUniformLocation(this->ID, name.c_str()), 1, GL_FALSE, &value[0][0]);
}

void Shader::setVec3(const std::string& name, glm::vec3 value) {
	glUniform3fv(glGetUniformLocation(this->ID, name.c_str()), 1, &value[0]);
}