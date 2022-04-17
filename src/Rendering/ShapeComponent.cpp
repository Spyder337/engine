#include <Rendering/ShapeComponent.hpp>

ShapeComponent::ShapeComponent(float* verts, int vertCount, int* indices, int indexCount){
    m_vertices = verts;
    m_vertexCount = vertCount;
    m_indices = indices;
    m_indexCount = indexCount;
}

void ShapeComponent::GenAndBindBuffers(unsigned int* vbo, unsigned int* vao, unsigned int* ebo){

}

ShapeComponent::~ShapeComponent(){

}