#include "gamestate.hpp"

GameState::GameState(ResourcePath& path, Resources<sf::Texture>& textureAllocator)
 : path(path), textureAllocator(textureAllocator) {}

void GameState::init() {
    player = std::make_shared<Entity>();

    // Añadir componentes al jugador (entidad)
    auto sprite = player->AddComponent<Sprite>();
    sprite->SetTextureAllocator(&textureAllocator);
    sprite->Load(path.Get() + "viking.png");
    auto movement = player->AddComponent<PlayerControl>();
    movement->SetInput(&input);//no olvidar la posicionalidad de la entrada, de otra manera el personaje no se movera

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
    player->Draw(window);//Esto dibujará nuestro nuevo componente de sprite
}
