add_subdirectory(Components)
add_subdirectory(Systems)

target_sources(${CMAKE_PROJECT_NAME}
    PRIVATE
        Object.cpp
)