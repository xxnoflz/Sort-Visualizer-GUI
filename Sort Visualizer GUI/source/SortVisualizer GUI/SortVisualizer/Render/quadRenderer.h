#pragma once
#include <QtOpenGL/QOpenGLFunctions_3_3_Core>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

#include <vector>

#include "../Utilities/Shader.h"

class quadRenderer : protected QOpenGLFunctions_3_3_Core{
public:
	quadRenderer();
	~quadRenderer();

	void Draw(const glm::vec2 position, const glm::vec2 size, Shader* shader, const glm::vec3 color = glm::vec3(1.0));
private:
	GLuint VAO;

	void Init();
};