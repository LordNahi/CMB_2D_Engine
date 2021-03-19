#ifndef Game_hpp
#define Game_hpp

#include "Window.hpp"

class Game
{
    public:
        Game();

        void Update();
        void LateUpdate();
        void Draw();
        bool IsRunning() const;

    private:
        Window window;
};

#endif /* Game_hpp */