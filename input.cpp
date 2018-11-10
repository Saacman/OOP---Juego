#include "input.hpp"

void Input::Update() {
    m_lastKeys = m_keys;

    m_keys.setBit((int)Key::Left, sf::Keyboard::isKeyPressed(sf::Keyboard::Left));
    m_keys.setBit((int)Key::Right, sf::Keyboard::isKeyPressed(sf::Keyboard::Right));
    m_keys.setBit((int)Key::Up, sf::Keyboard::isKeyPressed(sf::Keyboard::Up));
    m_keys.setBit((int)Key::Down, sf::Keyboard::isKeyPressed(sf::Keyboard::Down));
}

// Retorna true si la tecla esta siendo presionada
bool Input::isKPressed(Key code) {
    return m_keys.getBit((int)code);
}

// Retorna true si la tecla acaba de ser presionada
bool Input::isKDown(Key code) {
    bool before = m_lastKeys.getBit((int)code);
    bool now = m_keys.getBit((int)code);

    return now && !before;
}

// Retorna true si la tecla acaba de ser liberada
bool Input::isKUp(Key code) {
    bool before = m_lastKeys.getBit((int)code);
    bool now = m_keys.getBit((int)code);

    return !now && before;
}
