#include "S_Drawable.hpp"

void S_Drawable::Add(std::vector<std::shared_ptr<Object>>& objects)
{
    for (auto object : objects)
    {
        AddNewObject(object);
    }

    Sort();
}

void S_Drawable::Add(std::shared_ptr<Object>& object)
{
    AddNewObject(object);
    Sort();
}

void S_Drawable::AddNewObject(std::shared_ptr<Object>& object)
{
    std::shared_ptr<C_Drawable> drawable = object->GetDrawable();

    if (drawable)
    {
        drawables.emplace_back(object);
    }
}

void S_Drawable::Sort()
{
    std::sort(drawables.begin(), drawables.end(),
    [](std::shared_ptr<Object> a, std::shared_ptr<Object> b) -> bool
    {
        return a->GetDrawable()->GetSortOrder() < b->GetDrawable()->GetSortOrder();
    }
    );
}

void S_Drawable::Draw(Window& window)
{
    for (auto& drawable : drawables)
    {
        drawable->Draw(window);
    }
}

void S_Drawable::ProcessRemovals()
{
    auto objIterator = drawables.begin();
    while (objIterator != drawables.end())
    {
        auto obj = *objIterator;
        
        if (obj->GetIsRemoving())
        {
            objIterator = drawables.erase(objIterator);
        }
        else
        {
            ++objIterator;
        }
    }
}