add_subdirectory(Engine)

target_sources(${CMAKE_PROJECT_NAME}
    PRIVATE
        Game.cpp
        SceneGame.cpp
        SceneSplash.cpp
)