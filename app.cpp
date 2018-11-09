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

    const int Speed = 100; //Pixeles por moverse por segundo
    float frameMove = Speed * dTime; //Pixeles que se moverá por fraccion de segundo

    //const sf::Vector2f& spritePos = vikingSprite.getPosition();
    //vikingSprite.setPosition(spritePos.x + frameMove, spritePos.y);

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
        vikingSprite.move(0, -frameMove);
        //player.setTextureRect(sf::IntRect(counter * 32,    0, 32, 48));
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
        vikingSprite.move(0, frameMove);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
        vikingSprite.move(frameMove, 0);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
        vikingSprite.move(-frameMove, 0);
    }

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
