#ifndef Game_hpp
#define Game_hpp
#include <SFML/Graphics.hpp>
#include "Window.hpp"
#include "WorkingDirectory.hpp"
#include "Input.hpp"

#include "SceneStateMachine.hpp" // New
#include "SceneSplashScreen.hpp" // New
#include "SceneGame.hpp" // New


class Game
{
public:
    Game();

    void CaptureInput();
    void Update();
    void LateUpdate();
    void Draw();
    bool IsRunning() const;
    void CalculateDeltaTime();

    //


private:
    Window window;
    WorkingDirectory workingDir;
    /*sf::Texture vikingTexture;
    sf::Sprite vikingSprite;*/
    sf::Clock clock;
    float deltaTime;
    SceneStateMachine sceneStateMachine;
    ResourceAllocator<sf::Texture> textureAllocator;
};

#endif
