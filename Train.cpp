#include "Train.h"
int Train::IdCounter = 0;

Train::Train(size_t MaxPassengers,size_t NumberOfCars)
    : Transportation{"TR-"+std::to_string(IdCounter), MaxPassengers, Train::Name}, NumberOfCars{NumberOfCars}
{
    Train::IdCounter++;
}

const std::string& Train::GetId() const
{
    return Transportation::GetId();
}

const size_t& Train::GetMaxPassengers() const
{
    return Transportation::GetMaxPassengers();
}

const std::string& Train::GetName() const
{
    return Transportation::GetName();
}

const size_t& Train::GetNumberOfCars() const
{
    return this->NumberOfCars;
}

void Train::SetMaxPassengers(const int& MaxPassengers)
{
    return Transportation::SetMaxPassengers(MaxPassengers);
}
