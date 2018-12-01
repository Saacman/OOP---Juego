#include "sprite.hpp"
#include "entity.hpp"
// Usamos un puntero al dueño de este componente
Sprite::Sprite(Entity* owner) : Component(owner), currentTextureID(-1) {}

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
        // Verificar que no sea la textura actual
        if( textureID >= 0 && textureID != currentTextureID) {
            currentTextureID = textureID;
            std::shared_ptr<sf::Texture> texture = allocator->get(textureID);
            sprite.setTexture(*texture);
        }
    }
}

// Dibuja el sprite en la ventana
void Sprite::Draw(Window& window)
{
    window.Draw(sprite);
}

// Asigna el asset dado el ID
void Sprite::Load(int id) {
    if(id >= 0 && id!= currentTextureID) {
        currentTextureID = id;
        std::shared_ptr<sf::Texture> texture = allocator->get(id);
        sprite.setTexture(*texture);
    }
}
void Sprite::SetTextureAllocator(Resources<sf::Texture>* allocator) {
    this->allocator = allocator;
}

void Sprite::setTextureRect(int x, int y, int width, int height) {
    sprite.setTextureRect(sf::IntRect(x, y, width, height));
}
void Sprite::setTextureRect(const sf::IntRect& rect) {
    sprite.setTextureRect(rect);
}
