#pragma once
#include "Transportation.h"
class Plane :
    public Transportation
{
private:
    const size_t CargoCapacity;

protected:
    static constexpr const char* Name = "PLANE";
    static constexpr const float DEFAULT_CARGOCAPACITY = 2000;//in kg
    static constexpr const int DEFAULT_MAXPASSENGERS = 100;
    static int IdCounter;
public:
    Plane(
        size_t MaxPassengers = DEFAULT_MAXPASSENGERS,
        size_t CargoCapacity = DEFAULT_CARGOCAPACITY
    );
    virtual const std::string& GetId() const override;
    virtual const size_t& GetMaxPassengers() const override;
    virtual const std::string& GetName() const override;
    const size_t& GetCargoCapacity() const;

    virtual void SetMaxPassengers(const int& MaxPassengers) override;
    virtual ~Plane() = default;
};

