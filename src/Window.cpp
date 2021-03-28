#include "Window.hpp"

Window::Window(const std::string& windowName)
    : window(sf::VideoMode(800, 600), windowName, sf::Style::Close)
{
    window.setVerticalSyncEnabled(true);
}

void Window::Update()
{
    sf::Event event;

    if (window.pollEvent(event))
    {
        if (event.type == sf::Event::Closed)
        {
            window.close();
        }
    }
}

void Window::BeginDraw()
{
    window.clear(sf::Color::White);
}

void Window::Draw(const sf::Drawable& drawable)
{
    window.draw(drawable);
}

void Window::EndDraw()
{
    window.display();
}

bool Window::IsOpen() const
{
    return window.isOpen();
}

sf::Vector2u Window::GetCenter() const
{
    return {
        window.getSize().x / 2,
        window.getSize().y / 2
    };
}