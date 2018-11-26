#include "splashscreen.hpp"
 SplashScreen(ResourcePath& Path, FSM& fsm, Window& window) : FSM(sceneStateMachine), ResourcePath(Path),
window(window), switchToState(0), currentSeconds(0.f),showForSeconds(3.f)
{ }
//La duracion de la splash screen es 3 segundos

void SplashScreen::init() {
	// Inicializando los recursos de la splash screen

    splashTexture.loadFromFile(workingDir.Get() + "mylog.png");
    splashSprite.setTexture(splashTexture);
    sf::FloatRect spriteSize = splashSprite.getLocalBounds();

	// El origen del sprite es el centro de la imagen
    splashSprite.setOrigin(spriteSize.width * 0.5f,spriteSize.height * 0.5f);

    splashSprite.setScale(0.5f, 0.5f);

    sf::Vector2u wCenter = window.GetCentre();

	// Positions sprite in centre of screen:
    splashSprite.setPosition(wCenter.x, wCenter.y);
}

void SplashScreen::activate() {
	// Resets the currentSeconds count whenever the scene is activated.
	currentSeconds = 0.f;
}

void SplashScreen::terminate() { }

void SplashScreen::SetSwitchToScene(unsigned int id) {
	// Stores the id of the scene that we will transition to.
    switchToState = id;
}

void SplashScreen::Update(float dTime)
{
    currentSeconds += dTime;

    if(currentSeconds >= showForSeconds)
    {
		// Switches states.
        fsm.SwitchTo(switchToState);
    }
}

void SplashScreen::Draw(Window& window)
{
    window.Draw(splashSprite);
}
