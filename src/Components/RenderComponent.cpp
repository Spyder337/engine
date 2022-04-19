#include <iostream>
#include <Components/RenderComponent.hpp>


void RenderComponent::GenAndBindBuffers(unsigned int* vbo, unsigned int* vao, unsigned int* ebo) {
    // TODO: Generate buffers
    glGenBuffers(1, &VBO);
    glGenVertexArrays(1, &VAO);

    // TODO: Handle bindings
    glBindVertexArray(VAO);
    // Place the vertices in the vertex buffer object
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    std::cout << m_shape->m_vertexCount * sizeof(float) << std::endl;
    glBufferData(GL_ARRAY_BUFFER, m_shape->m_vertexCount * sizeof(float), m_shape->m_vertices, GL_STATIC_DRAW);
    // Set the pointers for the vertex attributes
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);

    // TODO: Unbind buffers
    glBindBuffer(GL_ARRAY_BUFFER, 0); 
    glBindVertexArray(0);
}

RenderComponent::RenderComponent(){
    m_shape = new ShapeComponent();
    m_shader = new ShaderComponent();
}

RenderComponent::RenderComponent(ShapeComponent* shape, ShaderComponent* shader) {
    m_shape = shape;
    m_shader = shader;
    GenAndBindBuffers(&VBO, &VAO, &EBO);
}

void RenderComponent::Render() {
    m_shader->Use();
    glBindVertexArray(VAO);
    glDrawArrays(GL_TRIANGLES, 0, 3);
}

RenderComponent::~RenderComponent() {
    delete m_shape;
    delete m_shader;
}
