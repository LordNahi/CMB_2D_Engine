#include "Debug.hpp"

std::vector<std::array<sf::Vertex, 2>> Debug::lines = {};
std::vector<sf::RectangleShape> Debug::rects = {};

void Debug::Draw(Window& window)
{
    for (auto& rect : rects)
    {
        window.Draw(rect);
    }
    rects.clear();

    for (auto& line : lines)
    {
        sf::Vertex displayLine[2] = { line.at(0), line.at(1) };

        window.Draw(displayLine, 2, sf::Lines);
    }
    lines.clear();
}

void Debug::DrawRect(const sf::FloatRect& rect, sf::Color colour, int lineThickness)
{
    sf::Vector2f size(rect.width, rect.height);
    sf::Vector2f pos(rect.left, rect.top);
    sf::RectangleShape shape(size);

    shape.setPosition(pos);
    shape.setOutlineColor(colour);
    shape.setOutlineThickness(lineThickness);
    shape.setFillColor(sf::Color::Transparent);

    rects.push_back(shape);
}

void Debug::DrawLine(sf::Vector2f from, sf::Vector2f to, sf::Color colour, int lineThickness)
{
    lines.push_back({ sf::Vertex(from, colour), sf::Vertex(to, colour) });
}

void Debug::Log(const std::string& message)
{
    std::cout << message << std::endl;
}

void Debug::LogWarning(const std::string& message)
{
    std::cout << "WARNING: " << message << std::endl;
}

void Debug::LogError(const std::string& message)
{
    std::cout << "ERROR: " << message << std::endl;
}