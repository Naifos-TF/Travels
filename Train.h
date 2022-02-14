#pragma once
#include "Transportation.h"
class Train :
    public Transportation
{
private:
    const size_t NumberOfCars;
    static constexpr const int DEFAULT_MAXPASSENGERS = 24;
    static constexpr const int DEFAULT_NUMBEROFCARS = 6;
protected:
    static constexpr const char* Name = "TRAIN";
    static int IdCounter;

public:
    Train(
        size_t MaxPassengers = DEFAULT_MAXPASSENGERS,
        size_t NumberOfCars = DEFAULT_NUMBEROFCARS
    );
    virtual const std::string& GetId() const override;
    virtual const size_t& GetMaxPassengers() const override;
    virtual const std::string& GetName() const override;
    const size_t& GetNumberOfCars() const;

    virtual void SetMaxPassengers(const int& MaxPassengers) override;
    virtual ~Train() = default;
};

