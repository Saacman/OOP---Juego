#include "gamestate.hpp"

GameState::GameState(ResourcePath& path) : path(path) {}

void GameState::init() {
    player = std::make_shared<Object>();

    // Añadir componentes al jugador (objeto)
    auto sprite = player->AddComponent<Sprite>();
    sprite->Load(path.Get() + "viking.png");
}
void GameState::terminate() { }

void GameState::ProcessInput() {
    input.Update();
}
void GameState::Update(float dTime) {
    // const int speed = 150;
    // float frameMove = speed * dTime;
    // int xMove = 0;
    // int yMove = 0;
    // if (input.isKPressed(Input::Key::Up))  yMove = -frameMove;
    // if (input.isKPressed(Input::Key::Down)) yMove = frameMove;
    // if (input.isKPressed(Input::Key::Right)) xMove = frameMove;
    // if (input.isKPressed(Input::Key::Left)) xMove = -frameMove;
    // vikingSprite.move(xMove, yMove);
}
void GameState::Draw(Window& window) {
    player->Draw(window);
}
