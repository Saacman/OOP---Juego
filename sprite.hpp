#ifndef SPRITE_HPP
#define SPRITE_HPP

#include "component.hpp"
#include "C_Transform.hpp"

class Sprite : public Component
{
public:
    C_Sprite(Object* owner);

    void Load(const std::string& filePath);

    void Draw(Window& window) override;

    void LateUpdate(float deltaTime) override;

private:
    sf::Texture texture;
    sf::Sprite sprite;
};

#endif
