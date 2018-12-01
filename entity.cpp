#include  "entity.hpp"

Entity::Entity() : forRemoval(false) {
    transform = AddComponent<Transform>();
}


void Entity::Awake() {
    for(int i = components.size() - 1; i >= 0; i--)
    {
        components[i]->Awake();
    }
}



void Entity::Start() {
    for(int i = components.size() - 1; i >= 0; i--)
    {
        components[i]->Start();
    }
}


void Entity::Update(float timeDelta) {
    for(int i = components.size() - 1; i >= 0; i--)
    {
        components[i]->Update(timeDelta);
    }
}

void Entity::LateUpdate(float timeDelta) {
    for(int i = components.size() - 1; i >= 0; i--)
    {
        components[i]->LateUpdate(timeDelta);
    }
}

void Entity::Draw(Window& window) {
    for(int i = components.size() - 1; i >= 0; i--)
    {
        components[i]->Draw(window);
    }
}

bool Entity::IsForRemoval() {
    return forRemoval;

}
void Entity::Remove() {
    forRemoval = true;
}
