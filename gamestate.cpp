#include "gamestate.hpp"

GameState::GameState(ResourcePath& path) : path(path) {}

void GameState::init() {
    player = std::make_shared<Entity>();

    // Añadir componentes al jugador (entidad)
    auto sprite = player->AddComponent<Sprite>();
    sprite->Load(path.Get() + "viking.png");

    auto movement = player->AddComponent<PlayerControl>();
    movement->SetInput(&input);

}
void GameState::terminate() { }

void GameState::ProcessInput() {
    input.Update();
}

void GameState::Update(float dTime) {
    player->Update(dTime);
}

void GameState::LateUpdate(float dTime) {
    player->LateUpdate(dTime);
}
void GameState::Draw(Window& window) {
    player->Draw(window);
}
