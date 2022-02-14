#pragma once
#include <iostream>
#include <string>

class Transportation
{
protected:
    std::string Id;
    size_t MaxPassengers;
    std::string Name;
public:
    Transportation(std::string Id, size_t MaxPassengers, std::string Name);
    virtual const std::string& GetId() const;
    virtual const size_t& GetMaxPassengers() const;
    virtual const std::string& GetName() const;

    virtual void SetMaxPassengers(const int& MaxPassengers);
    virtual ~Transportation() = default;
};
