#include "C_InstanceID.hpp"

int C_InstanceID::count = 0;

C_InstanceID::C_InstanceID(Object* Owner)
:
Component(owner),
id(count++)
{}

C_InstanceID::~C_InstanceID() {}

const int C_InstanceID::Get()
{
    return id;
}