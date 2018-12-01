#ifndef SPRITE_HPP
#define SPRITE_HPP

#include "component.hpp"
#include "transform.hpp"
#include "resources.hpp"

class Sprite : public Component
{
public:
    Sprite(Entity* owner);

    //Carga un sprite desde el archivo
    void Load(const std::string& filePath);

    //Con este metodo sobrecargamos para aceptar la textura de nuevo id
    void Load(int id);

    void Draw(Window& window) override;//sobrecargamos el metodo draw para poder dibujar nuestro sprite

    void LateUpdate(float deltaTime) override;//Usamos este metodo para obtener sprites en base de nuestra posición 

    void SetTextureAllocator(Resources<sf::Texture>* allocator);

    void setTextureRect(intx, int y, int width, int height);
    void setTextureRect(const sf::IntRect& rect);

private:
    //sf::Texture texture;
    Resources<sf::Texture>* allocator;
    sf::Sprite sprite;
    int currentTextureID;
};

#endif
