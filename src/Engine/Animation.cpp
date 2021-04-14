#include "Animation.hpp"

Animation::Animation()
{
    currentFrameIndex = 0;
    currentFrameTime = 0.f;
}

void Animation::AddFrame(int textureID, int x, int y, int width, int height, float frameTime)
{
    FrameData data;

    data.id = textureID;
    data.x = x;
    data.y = y;
    data.width = width;
    data.height = height;
    data.displayTimeSeconds = frameTime;

    frames.push_back(data);
}

FrameData* Animation::GetCurrentFrame()
{
    if (frames.size() > 0)
    {
        return &frames[currentFrameIndex];
    }

    return nullptr;
}

bool Animation::UpdateFrame(float deltaTime)
{
    if (frames.size() > 0)
    {
        currentFrameTime += deltaTime;

        if (currentFrameTime >= frames[currentFrameIndex].displayTimeSeconds)
        {
            currentFrameTime = 0.f;
            IncrementFrame();
            return true;
        }
    }

    return false;
}

void Animation::IncrementFrame()
{
    currentFrameIndex = (currentFrameIndex + 1) % frames.size();
}

void Animation::Reset()
{
    currentFrameIndex = 0;
    currentFrameTime = 0.f;
}