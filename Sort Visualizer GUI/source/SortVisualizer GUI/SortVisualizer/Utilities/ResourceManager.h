#pragma once
#include <string>
#include <sstream>
#include <fstream>
#include <map>

#include "Shader.h"

class ResourceManager {
public:
	static void LoadShader(std::string vertexPath, std::string fragmentPath, std::string name);
	static Shader* GetShader(std::string name);
private:
	static std::map<std::string, Shader*> Shaders;

	ResourceManager();
};