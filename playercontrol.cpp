#include "playercontrol.hpp"
#include "object.hpp"


PlayerControl::PlayerControl(Object* owner)	: Component(owner), speed(150) {}

void PlayerControl::SetInput(Input* input) {
    this->input = input;
}

void PlayerControl::SetSpeed(int speed)
{
    this->speed = speed;
}

void PlayerControl::Update(float deltaTime)
{
    if(input == nullptr) return;

    int xMove = 0;
    int yMove = 0;

    if(input->isKPressed(Input::Key::Left)) xMove = -speed;
    if(input->isKPressed(Input::Key::Right))xMove = speed;
    if(input->isKPressed(Input::Key::Up)) yMove = -speed;
    if(input->isKPressed(Input::Key::Down)) yMove = speed;

    float xFrameMove = xMove * deltaTime;
    float yFrameMove = yMove * deltaTime;
    owner->transform->AddPosition(xFrameMove, yFrameMove);
}

// float frameMove = speed * deltaTime;
// if(input->isKPressed(Input::Key::Left)) xMove = -frameMove;
// if(input->isKPressed(Input::Key::Right))xMove = frameMove;
// if(input->isKPressed(Input::Key::Up)) yMove = -frameMove;
// if(input->isKPressed(Input::Key::Down)) yMove = frameMove;
//
// owner->transform->AddPosition(xMove, yMove);
