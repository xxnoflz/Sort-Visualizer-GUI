#pragma once
#include <QtOpenGL/QOpenGLFunctions_3_3_Core>

#include <glm/glm.hpp>

#include <string>

class Shader : protected QOpenGLFunctions_3_3_Core{
public:
	Shader(const std::string& vertexCode = "NULL", const std::string& fragmentCode = "NULL");
	~Shader();

	void use();

	void setMat4(const std::string& name, glm::mat4 value);
	void setVec3(const std::string&, glm::vec3 value);
private:
	GLuint ID;

	void CreateShader(const std::string& vertexCode, const std::string& fragmentCode);
};