#include "ObjectCollection.hpp"

void ObjectCollection::Add(std::shared_ptr<Object> object)
{
    newObjects.push_back(object);
}

void ObjectCollection::Add(std::vector<std::shared_ptr<Object>> objects)
{
    newObjects.insert(newObjects.end(), objects.begin(), objects.end());
}

void ObjectCollection::Update(float deltaTime)
{
    for (auto& object : objects)
    {
        object->Update(deltaTime);
    }
}

void ObjectCollection::LateUpdate(float deltaTime)
{
    for (auto& object : objects)
    {
        object->LateUpdate(deltaTime);
    }
}

void ObjectCollection::Draw(Window& window)
{
    drawables.Draw(window);
}

void ObjectCollection::ProcessNewObjects()
{
    if (newObjects.size() > 0)
    {
        for (auto& object : newObjects)
        {
            object->Awake();
        }

        for (auto& object : newObjects)
        {
            object->Start();
        }

        // Move all the new objects to our objects collection ...
        objects.insert(objects.end(), newObjects.begin(), newObjects.end());

        drawables.Add(newObjects);

        newObjects.clear();
    }
}

void ObjectCollection::ProcessRemovals()
{
    auto objectIterator = objects.begin();

    while (objectIterator != objects.end())
    {
        auto object = **objectIterator;

        if (object.GetIsRemoving())
        {
            objectIterator = objects.erase(objectIterator);
        }
        else
        {
            ++objectIterator;
        }
    }

    drawables.ProcessRemovals();
}