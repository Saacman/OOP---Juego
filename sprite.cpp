#include "sprite.hpp"
#include "entity.hpp"
// Usamos un puntero al dueño de este componente
Sprite::Sprite(Entity* owner) : Component(owner) {}
// A través del dueño obtenemos su posición
void Sprite::LateUpdate(float deltaTime)
{
    sprite.setPosition(owner->transform->GetPosition());
}

void Sprite::Load(const std::string& filePath)
{
    texture.loadFromFile(filePath);
    sprite.setTexture(texture);
}

void Sprite::Draw(Window& window)
{
    window.Draw(sprite);
}
