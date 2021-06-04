#ifndef Transform_hpp
#define Transform_hpp

#include "Component.hpp"

class C_Transform : public Component
{
    public:
        C_Transform(Object* owner);

        void SetPosition(float x, float y);
        void SetPosition(const sf::Vector2f pos);

        void AddPosition(float x, float y);
        void AddPosition(const sf::Vector2f pos);

        void SetX(float x);
        void SetY(float y);

        void AddX(float x);
        void AddY(float y);

        void SetStatic(bool isStatic);

        const sf::Vector2f& GetPosition();
        const bool GetIsStatic();

    private:
        sf::Vector2f position;
        bool isStaticTransform;
};

#endif /* C_Transform_hpp */