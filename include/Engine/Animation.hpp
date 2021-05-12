#ifndef Animation_hpp
#define Animation_hpp

#include <vector>
#include <string>

// TODO: Initialize all your values besides string ...
struct FrameData
{
    std::string key;            // Texture key
    int x;                      // x position of sprite in the texture
    int y;                      // y position of sprite in the texture
    int width;                  // Width of sprite
    int height;                 // height of sprite
    float displayTimeSeconds;   // How long to display the frame
};

class Animation
{
    public:
        Animation();

        void AddFrame(std::string key, int x, int y, int width, int height, float frameTime);
        bool UpdateFrame(float deltaTime);
        void Reset();
        FrameData* GetCurrentFrame();
    
    private:
        int currentFrameIndex;
        float currentFrameTime;
        void IncrementFrame();
        std::vector<FrameData> frames;
};

#endif /* Animation_hpp */