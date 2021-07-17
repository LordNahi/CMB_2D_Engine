#ifndef Debug_hpp
#define Debug_hpp

#include <array>
#include <iostream>
#include <functional>
#include <SFML/Graphics.hpp>

#include "Window.hpp"

class Debug
{
    public:
        static void Draw(Window& window);
        static void DrawRect(const sf::FloatRect& rect, sf::Color colour = sf::Color::Red, const int lineThickness = 1);
        static void DrawLine(const sf::Vector2f from, const sf::Vector2f to, sf::Color colour = sf::Color::Red, const int lineThickness = 1);
        
        static void Log(const std::string& message);
        static void LogWarning(const std::string& message);
        static void LogError(const std::string& message);
    
    private:
        static std::vector<std::array<sf::Vertex, 2>> lines;
        static std::vector<sf::RectangleShape> rects;
};

#endif /* Debug_hpp */