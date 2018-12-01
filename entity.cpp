#include  "entity.hpp"

Entity::Entity()
{
    transform = AddComponent<Transform>();//Cambia la posición del sprite por intervalos
}


void Entity::Awake()
{
    for(int i = components.size() - 1; i >= 0; i--)
    {
        components[i]->Awake();
    }
}



void Entity::Start()
{
    for(int i = components.size() - 1; i >= 0; i--)
    {
        components[i]->Start();
    }
}


void Entity::Update(float timeDelta)
{
    for(int i = components.size() - 1; i >= 0; i--)
    {
        components[i]->Update(timeDelta);
    }
}

void Entity::LateUpdate(float timeDelta)
{
    for(int i = components.size() - 1; i >= 0; i--)
    {
        components[i]->LateUpdate(timeDelta);
    }
}

void Entity::Draw(Window& window)
{
    for(int i = components.size() - 1; i >= 0; i--)
    {
        components[i]->Draw(window);
    }
}
