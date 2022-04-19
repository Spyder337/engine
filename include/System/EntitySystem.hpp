#include <vector>
#include <map>
#include <glm/glm.hpp>
#include <Entity.hpp>

class EntitySystem{
private:
    uint32_t size;
    uint32_t currId;
    uint32_t count;

public:
    Entity* entities;
    std::map<uint32_t, Entity*> entityMap;
    EntitySystem();

    /*
    * Take components and creates an entity.
    */
    uint32_t AddEntity(Transform trans, RenderComponent rend);

    /*
    * Remove an entity.
    */
   bool RemoveEntity(uint32_t id);

   void Update();
};