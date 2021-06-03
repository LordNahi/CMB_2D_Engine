#include "C_Drawable.hpp"

C_Drawable::C_Drawable() : sortOrder(0) {}

C_Drawable::~C_Drawable() {}

void C_Drawable::SetSortOrder(int order)
{
    sortOrder = order;
}

const int C_Drawable::GetSortOrder()
{
    return sortOrder;
}