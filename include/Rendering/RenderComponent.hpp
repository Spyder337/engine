#include <Common.hpp>
#include <Shader.hpp>
#include <ShapeComponent.hpp>

class RenderComponent{
    bool isDirty;
    ShaderComponent shader;
    ShapeComponent shape;
};