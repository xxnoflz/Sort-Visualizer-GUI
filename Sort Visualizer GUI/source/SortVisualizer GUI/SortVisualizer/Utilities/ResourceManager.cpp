#include "ResourceManager.h"

std::map<std::string, Shader*> ResourceManager::Shaders;

void ResourceManager::LoadShader(std::string vertexPath, std::string fragmentPath, std::string name) {
	std::fstream vertexFile{ vertexPath };
	std::stringstream vertexStream;
	vertexStream << vertexFile.rdbuf();
	const std::string vertexCode{ vertexStream.str() };

	std::fstream fragmentFile{ fragmentPath };
	std::stringstream fragmentStream;
	fragmentStream << fragmentFile.rdbuf();
	const std::string fragmentCode{ fragmentStream.str() };

	static Shader shader{ vertexCode, fragmentCode };
	Shaders[name] = &shader;
}

Shader* ResourceManager::GetShader(const std::string name) {
	return Shaders[name];
}