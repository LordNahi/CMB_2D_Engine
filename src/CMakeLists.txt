add_subdirectory(Components)
add_subdirectory(Engine)

target_sources(${CMAKE_PROJECT_NAME}
    PRIVATE
        SceneGame.cpp
        SceneSplash.cpp
)