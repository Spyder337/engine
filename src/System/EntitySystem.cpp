#include <System/EntitySystem.hpp>

using namespace std;
using namespace glm;

EntitySystem::EntitySystem(){
    size = 1000;
    entities = new Entity[size];
    count = 0;
}

uint32_t EntitySystem::AddEntity(Transform trans, RenderComponent rend){
    uint32_t id = currId++;
    if(count < size){
        entities[count].id = id;
        entities[count].transform = trans;
        entities[count].renderer = rend;
        entityMap.emplace(id, &entities[count]);
        count++;
    }
    return id;
}

bool EntitySystem::RemoveEntity(uint32_t id){
    return false;
}

void EntitySystem::Update(){
    for(int i = 0; i < count; i++){
        entities[i].renderer.Render();
    }
}