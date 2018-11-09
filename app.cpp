#include "app.hpp"

App::App() : window(" DEMO ") {
    //vikingTxt.loadFromFile(wdir.Get() + "viking.png");
    vikingTxt.loadFromFile("Resources/Textures/viking.png");
	vikingSprite.setTexture(vikingTxt);
    //vikingSprite.setTextureRect(sf::IntRect(1,1,30,30));
    dTime = clock.restart().asSeconds();
}

void App::Update() {
    window.Update(); // Linea importante, sin ella la ventana no responde

    const int MovePerSec = 100; //Pixeles por moverse por segundo
    const float frameMove = MovePerSec * dTime; //Pixeles que se moverá por fraccion de segundo
    //const sf::Vector2f& spritePos = vikingSprite.getPosition();
    //vikingSprite.setPosition(spritePos.x + frameMove, spritePos.y);
    // move(x,y) evita tener que llamar a get position 3 veces
    vikingSprite.move(frameMove,0);
}
void App::LateUpdate() { }

void App::Draw() {
    window.BeginDraw();

    window.Draw(vikingSprite);

    window.EndDraw();
}

bool App::IsRunning() const {
    return window.IsOpen();
}

void App::getdTime() {
    dTime = clock.restart().asSeconds();
}
