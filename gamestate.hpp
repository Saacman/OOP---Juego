#ifndef STATEAPP_HPP
#define STATEAPP_HPP

#include "window.hpp"
#include "r_path.hpp"
#include "input.hpp"
#include "state.hpp"

class GameState : public State {
public:
    GameState(ResourcePath& path);

    void init() override;
    void terminate() override;

    void ProcessInput() override;
    void Update(float dTime) override;
    void Draw(Window& window) override;

private:
    sf::Texture vikingTexture;
    sf::Sprite vikingSprite;

    ResourcePath& path;
    Input input;
};
#endif
