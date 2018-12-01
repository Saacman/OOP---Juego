#ifndef SPRITE_HPP
#define SPRITE_HPP

#include "component.hpp"
#include "transform.hpp"
#include "resources.hpp"

class Sprite : public Component
{
public:
    Sprite(Entity* owner);

    void Load(const std::string& filePath);

    void Load(int id);

    void Draw(Window& window) override;

    void LateUpdate(float deltaTime) override;

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
