#include "sprite.hpp"
#include "object.hpp"

Sprite::Sprite(Object* owner) : Component(owner) {}

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
