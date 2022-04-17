#pragma once

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <string>
#include <glm/glm.hpp>

struct Transform{
    Transform* parent;
    glm::mat3 parentToWorld;
    glm::mat3 localToWorld;
    glm::vec3 localPos;
    glm::vec3 worldPos;
    glm::vec4 orientation;
};


std::string* ReadShaderFile(std::string, std::string);