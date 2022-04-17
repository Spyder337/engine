#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>

class ShapeComponent{
private:
    float* m_vertices;
    int* m_indices;
    int m_indexCount;
    int m_vertexCount;
public:
    ShapeComponent(float*,  int, int*, int);
    void GenAndBindBuffers(unsigned int* vbo, unsigned int* vao, unsigned int* ebo);
    ~ShapeComponent();
};