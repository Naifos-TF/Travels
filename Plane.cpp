#include "Plane.h"

int Plane::IdCounter = 0;

Plane::Plane(size_t MaxPassengers, size_t CargoCapacity)
    : Transportation{ "PL-" + std::to_string(IdCounter), MaxPassengers, Plane::Name }, CargoCapacity{ CargoCapacity }
{
    Plane::IdCounter++;
}

const std::string& Plane::GetId() const
{
    return Transportation::GetId();
}

const size_t& Plane::GetMaxPassengers() const
{
    return Transportation::GetMaxPassengers();
}

const std::string& Plane::GetName() const
{
    return Transportation::GetName();
}

const size_t& Plane::GetCargoCapacity() const
{
    return this->CargoCapacity;
}



void Plane::SetMaxPassengers(const int& MaxPassengers)
{
    return Transportation::SetMaxPassengers(MaxPassengers);
}
