#ifndef Animation_hpp
#define Animation_hpp

#include <vector>

struct FrameData
{
    int id;                     // Texture id (retrieved from our texture allocator)
    int x;                      // x position of sprite in the texture
    int y;                      // y position of sprite in the texture
    int width;                  // Width of sprite
    int height;                 // height of sprite
    float displayTimeSeconds;   // How long to display the frame
};

enum class FaceDirection
{
    None,
    Left,
    Right
};

class Animation
{
    public:
        Animation(FaceDirection direction);

        void AddFrame(int textureID, int x, int y, int width, int height, float frameTime);
        bool UpdateFrame(float deltaTime);
        void Reset();
        void SetDirection(FaceDirection direction);
        FaceDirection GetDirection() const;
        FrameData* GetCurrentFrame();
    
    private:
        int currentFrameIndex;
        float currentFrameTime;
        void IncrementFrame();
        std::vector<FrameData> frames;
        FaceDirection faceDirection;
};

#endif /* Animation_hpp */