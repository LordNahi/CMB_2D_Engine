#ifndef S_Drawable_hpp
#define S_Drawable_hpp

#include <map>

#include "Object.hpp"

class S_Drawable
{
    public:
        void Add(std::vector<std::shared_ptr<Object>>& objects);
        void Add(std::shared_ptr<Object>& object);
        void ProcessRemovals();
        void Draw(Window& window);

    private:
        void AddNewObject(std::shared_ptr<Object>& object);
        void Sort();

        std::vector<std::shared_ptr<Object>> drawables;
};

#endif /* S_Drawable_hpp */