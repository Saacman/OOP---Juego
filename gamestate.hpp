#ifndef STATEAPP_HPP
#define STATEAPP_HPP

#include "window.hpp"
#include "r_path.hpp"
#include "input.hpp"
#include "state.hpp"
#include "object.hpp"
#include "sprite.hpp"

class GameState : public State {
public:
    GameState(ResourcePath& path);

    void init() override;
    void terminate() override;

    void ProcessInput() override;
    void Update(float dTime) override;
    void Draw(Window& window) override;

private:
    std::shared_ptr<Object> player;

    ResourcePath& path;
    Input input;
};
#endif
