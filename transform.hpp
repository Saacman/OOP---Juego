#ifndef TRANSFORM_HPP
#define TRANSFORM_HPP

#include "component.hpp"

class Transform : public Component
{
public:
    Transform(Entity* owner);

    void SetPosition(float x, float y);
    void SetPosition(const sf::Vector2f& pos);

    void AddPosition(float x, float y);
    void AddPosition(sf::Vector2f pos);

    //Estos metodos de acceso nos permiten conseguir x/y valores por separado
    void SetX(float x);
    void SetY(float y);

    void AddX(float x);
    void AddY(float y);



    const sf::Vector2f& GetPosition() const;

private:
    sf::Vector2f position;
};

#endif
