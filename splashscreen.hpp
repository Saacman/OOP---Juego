#ifndef SPLASH_HPP
#define SPLASH_HPP

#include<SFML/Graphics.hpp>
#include "state.hpp"
#include "fsm.hpp"
#include "WorkingDirectory.hpp"

class SplashScreen : public State
{
public:
    SplashScreen(ResourcePath& Path, FSM& fsm, Window& window);

    void init() override;
    void terminate() override;

    void activate() override;

    void SetSwitchToState(unsigned int id);

    void Update(float dTime) override;
    void Draw(Window& window) override;

private:
    sf::Texture splashTexture;
    sf::Sprite splashSprite;

    ResourcePath& Path;
    FSM& fsm;
    Window& window;

    float showForSeconds;

    float currentSeconds;

    unsigned int switchToState;
};

#endif
