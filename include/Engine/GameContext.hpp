#ifndef GameContext_hpp
#define GameContext_hpp

#include "Window.hpp"
#include "WorkingDirectory.hpp"
#include "ResourceManager.hpp"
#include "SceneStateMachine.hpp"
#include "Input.hpp"

/**
 * NOTE: Tutorial uses pointers instead, when the
 * scene create event is called it assigns these
 * values ...
 * 
 * NOTE: Passing 'mcflurry' here isn't ideal, the
 * concept of a global context is good but need to
 * improve how it's setup ...
 */

struct GameContext
{
    Window window{"mcflurry"};
    WorkingDirectory workingDir;
    ResourceManager resourceManager;
    SceneStateMachine sceneStateMachine;
    Input input;
};

#endif /* GameContext_hpp */