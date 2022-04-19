#include <Components/ShapeComponent.hpp>

ShapeComponent::ShapeComponent(float* verts, int vertCount, int* indices, int indexCount){
    m_vertices = verts;
    m_vertexCount = vertCount;
    m_indices = indices;
    m_indexCount = indexCount;
}

ShapeComponent::~ShapeComponent(){
    delete m_vertices;
    delete m_indices;
}