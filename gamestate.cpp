#include "gamestate.hpp"

GameState::GameState(ResourcePath& path, Resources<sf::Texture>& textureAllocator)
 : path(path), textureAllocator(textureAllocator) {}

void GameState::init() {
    std::shared_ptr<Entity> player = std::make_shared<Entity>();
    std::shared_ptr<Entity> background = std::make_shared<Entity>();

    //Añadir textura al jugador
    auto sprite = player->AddComponent<Sprite>();
    sprite->SetTextureAllocator(&textureAllocator);

    // Añadir control
    auto movement = player->AddComponent<PlayerControl>();
    movement->SetInput(&input);
    // Añadir Animacion
    auto animation = player->AddComponent<Animation>();
    int playerTextureID = textureAllocator.Add(path.Get() + "viking.png");

    const int frameWidth = 165;
    const int frameHeight = 145;
    std::shared_ptr<Frames>
    StillSet->

    auto backsprite = background->AddComponent<Sprite>();
    backsprite->SetTextureAllocator(&textureAllocator);
    backsprite->Load(path.Get() + "background.png");

    // El orden en el que se añaden las entidades es el orden en que se dibujan
    entities.Add(background);
    entities.Add(player);
}
void GameState::terminate() { }

void GameState::ProcessInput() {
    input.Update();
}

void GameState::Update(float dTime) {
    entities.ProcessRemovals();
    entities.ProcessNewEntities();
    entities.Update(dTime);
    //player->Update(dTime);
}

void GameState::LateUpdate(float dTime) {
    entities.LateUpdate(dTime);
}
void GameState::Draw(Window& window) {
    entities.Draw(window);
}
