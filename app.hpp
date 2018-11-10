#ifndef APP_HPP
#define APP_HPP

#include "window.hpp"
#include "r_path.hpp"
#include "input.hpp"

class App {
public:
    App();
    void Update();
    void LateUpdate();
    void Draw();
    bool IsRunning() const;
    void getdTime();
    void captureInput();
private:
    Window window;
    sf::Clock clock;
    float dTime;
    Input input;

    //ResourcePath wdir;
    sf::Texture vikingTxt;
    sf::Sprite vikingSprite;
};

#endif
