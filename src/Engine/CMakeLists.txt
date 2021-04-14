add_subdirectory(ECS)

target_sources(${CMAKE_PROJECT_NAME}
    PRIVATE
        Animation.cpp
        Bitmask.cpp
        Game.cpp
        Input.cpp
        Main.cpp
        Window.cpp
        WorkingDirectory.cpp
        SceneStateMachine.cpp
        ObjectCollection.cpp
)