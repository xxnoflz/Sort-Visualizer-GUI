#pragma once
#include <vector>
#include <random>

#include <glm/glm.hpp>

#include "../Render/quadRenderer.h"
#include "../Utilities/Shader.h"

class CollumnArrayObject {
	const float collumn_padding{ 0.0f };
public:
	CollumnArrayObject();

	void SetRender(quadRenderer* renderer);
	void SetShader(Shader* shader);
	void SetData(uint32_t min_value, uint32_t max_value);

	void DrawCollumns(quadRenderer* qRender, Shader* shader, const uint32_t window_width, const uint32_t window_height, const uint32_t current_object, const uint32_t next_object);
	void DrawCollumns(uint32_t window_width, uint32_t window_height, uint32_t current_object, uint32_t next_object);
	void DrawCompleteCollumns(quadRenderer* qRender, Shader* shader, const uint32_t window_width, const uint32_t window_height);
	void DrawCompleteCollumns(uint32_t window_width, uint32_t window_height);

	std::vector<int>& GetVector();
private:
	std::vector<int> numbers;

	uint32_t m_max;
	uint32_t width;

	quadRenderer* qRender;
	Shader* shader;

	void CreateNumbersArray(uint32_t min_value, uint32_t max_value);
};