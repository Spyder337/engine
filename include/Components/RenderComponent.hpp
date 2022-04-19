#include <Components/ShapeComponent.hpp>
#include <Components/ShaderComponent.hpp>

class RenderComponent{
private:
    bool m_isDirty = true;
    ShaderComponent* m_shader;
    ShapeComponent* m_shape;
    unsigned int VBO;
    unsigned int VAO;
    unsigned int EBO;
    
    void GenAndBindBuffers(unsigned int* vbo, unsigned int* vao, unsigned int* ebo);
public:
    RenderComponent();
    RenderComponent(ShapeComponent* shape, ShaderComponent* shader);
    void Render();
    ~RenderComponent();
};