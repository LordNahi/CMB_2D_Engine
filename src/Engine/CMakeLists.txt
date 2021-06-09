add_subdirectory(ECS)
add_subdirectory(Utilities)

target_sources(${CMAKE_PROJECT_NAME}
    PRIVATE
        Animation.cpp
        Bitmask.cpp
        Input.cpp
        Main.cpp
        Window.cpp
        WorkingDirectory.cpp
        SceneStateMachine.cpp
        TileMapParser.cpp
        ObjectCollection.cpp
        ResourceManager.cpp
)