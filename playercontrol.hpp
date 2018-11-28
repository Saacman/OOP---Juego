#ifndef PLAYERCONTROL_HPP
#define PLAYERCONTROL_HPP

#include "component.hpp"
#include "input.hpp"

class PlayerControl : public Component
{
public:
    PlayerControl(Object* owner);

    void SetInput(Input* input);
    void SetSpeed(int speed);

    void Update(float deltaTime) override;

private:
    int speed;
    Input* input;
};

#endif
