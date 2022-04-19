#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>

class ShapeComponent{
public:
    float* m_vertices;
    int* m_indices;
    int m_indexCount;
    int m_vertexCount;
    ShapeComponent(){}
    ShapeComponent(float*,  int, int*, int);
    ~ShapeComponent();
};