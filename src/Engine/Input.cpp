#include "Input.hpp"

void Input::Update()
{
    lastFrameKeys.SetMask(thisFrameKeys);

    // This method of setting bits and controlling input will make
    // adding new input methods much easier, ie joystick, gamepad ...

    thisFrameKeys.SetBit((int)Key::Left,
        (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) ||
        (sf::Keyboard::isKeyPressed(sf::Keyboard::A)));

    thisFrameKeys.SetBit((int)Key::Right,
        (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) ||
        (sf::Keyboard::isKeyPressed(sf::Keyboard::D)));

    thisFrameKeys.SetBit((int)Key::Up,
        (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) ||
        (sf::Keyboard::isKeyPressed(sf::Keyboard::W)));

    thisFrameKeys.SetBit((int)Key::Down,
        (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) ||
        (sf::Keyboard::isKeyPressed(sf::Keyboard::S)));

    thisFrameKeys.SetBit((int)Key::Esc),
        sf::Keyboard::isKeyPressed(sf::Keyboard::Escape);
};

bool Input::IsKeyPressed(Key keycode)
{
    return thisFrameKeys.GetBit((int)keycode);
}

bool Input::IsKeyDown(Key keycode)
{
    bool lastFrame = lastFrameKeys.GetBit((int)keycode);
    bool thisFrame = thisFrameKeys.GetBit((int)keycode);

    return thisFrame && !lastFrame;
}

bool Input::IsKeyUp(Key keycode)
{
    bool lastFrame = lastFrameKeys.GetBit((int)keycode);
    bool thisFrame = thisFrameKeys.GetBit((int)keycode);

    return !thisFrame && lastFrame;
}