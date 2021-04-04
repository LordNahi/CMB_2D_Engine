#ifndef Transform_hpp
#define Transform_hpp

#include "Component.hpp"

class Transform : public Component
{
    public:
        Transform(Object* owner);

        void SetPosition(float x, float y);
        void SetPosition(const sf::Vector2f pos);

        void AddPosition(float x, float y);
        void AddPosition(const sf::Vector2f pos);

        void SetX(float x);
        void SetY(float y);

        void AddX(float x);
        void AddY(float y);

        const sf::Vector2f& GetPosition() const;

    private:
        sf::Vector2f position;
};

#endif /* Transform.hpp */