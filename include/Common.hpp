#pragma once

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <string>
#include <glm/glm.hpp>

struct Transform{
    bool hasParent = false;
    Transform* parent = nullptr;
    glm::mat3 parentToWorld = glm::mat3(1, 0, 0, 0, 1, 0, 0, 0, 1);
    glm::mat3 localToWorld = glm::mat3(1, 0, 0, 0, 1, 0, 0, 0, 1);
    glm::vec3 localPos = glm::vec3(1, 0, 0);;
    glm::vec3 worldPos = localPos * localToWorld;
    glm::vec4 orientation = glm::vec4(1, 0, 0, 0);
};


std::string* ReadShaderFile(std::string, std::string);

glm::mat3 CalculateLocalToWorld(Transform* transform);