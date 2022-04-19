#include <Common.hpp>
#include <Components/RenderComponent.hpp>

struct Entity{
    uint32_t id = 0;
    Transform transform;
    RenderComponent renderer;
};