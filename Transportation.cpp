#include "Transportation.h"

Transportation::Transportation(std::string Id, size_t MaxPassengers, std::string Name)
    :   Id{Id}, MaxPassengers(MaxPassengers), Name{Name}
{
}

const std::string& Transportation::GetId() const
{
    return this->Id;
}

const size_t& Transportation::GetMaxPassengers() const
{
    return this->MaxPassengers;
}

const std::string& Transportation::GetName() const {
    return this->Name;
}

void Transportation::SetMaxPassengers(const int& MaxPassengers)
{
    if (MaxPassengers >= 0) {
        this->MaxPassengers = MaxPassengers;
    }
}
