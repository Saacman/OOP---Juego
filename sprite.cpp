#include "sprite.hpp"
#include "entity.hpp"
// Usamos un puntero al dueño de este componente
Sprite::Sprite(Entity* owner) : Component(owner) {}
// A través del dueño obtenemos su posición y la actualizamos
void Sprite::LateUpdate(float deltaTime)
{
    sprite.setPosition(owner->transform->GetPosition());
}
// Cargar una textura nueva en el localizador y asignarlo al sprite
void Sprite::Load(const std::string& filePath)
{
    if(allocator) {
        int textureID = allocator->add(filePath);
        if( textureID >= 0) {
            std::shared_ptr<sf>::Texture> texture = allocator->get(textureID);
            sprite.setTexture(*texture);
        }
    }
}

void Sprite::Draw(Window& window)
{
    window.Draw(sprite);
}
// Asigna el asset dado el ID
void Load(int id) {
    if(id <= 0) {
        std::shared_ptr<sf::Texture> texture = allocator->get(id);
        sprite.setTexture(*texture);
    }
}
void SetTextureAllocator(Resources<sf::Texture>* allocator) {
    this->allocator = allocator;
}
