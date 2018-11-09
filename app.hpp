#ifndef APP_HPP
#define APP_HPP

#include "window.hpp"
#include "r_path.hpp"

class App {
public:
    App();
    void Update();
    void LateUpdate();
    void Draw();
    bool IsRunning() const;
    void getdTime();
private:
    Window window;
    sf::Clock clock;
    float dTime;
    //ResourcePath wdir;
    sf::Texture vikingTxt;
    sf::Sprite vikingSprite;
};

#endif
