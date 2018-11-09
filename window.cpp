#include "window.hpp"

Window::Window(const std::string& Name) : m_target( sf::VideoMode(800,600), Name, sf::Style::Default ) {
    // Window es un objeto no copiable
    //m_target = sf::RenderWindow( sf::VideoMode(800,600), Name, sf::Style::Titlebar );
    m_target.setVerticalSyncEnabled(true);
}

void Window::Update() {
    sf::Event event;
    if( m_target.pollEvent(event)){
        if (event.type == sf::Event::Closed) m_target.close();
    }
    // Salir al presionar esc
    if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape) m_target.close();
    
}

void Window::BeginDraw() {
    m_target.clear(sf::Color::White);
}

void Window::Draw(const sf::Drawable& drawable) {
    m_target.draw(drawable);
}

void Window::EndDraw() {
    m_target.display();
}

bool Window::IsOpen() const {
    return m_target.isOpen();
}
