#pragma once
#include <vector>

#include "Transportation.h"

class Travel
{

friend std::ostream& operator<<(std::ostream& Os, const Travel& T);
    
private:
    std::shared_ptr<Transportation> Transport;
    size_t Duration;//in minutes
    std::string Date;//format dd/mm/yyyy
    size_t Price; //in €
    std::string Departure;//departure city
    std::string Arrival;//arrival city
    //std::shared_ptr<std::vector<std::string>> PassengerList;
    bool IsValid;
    const int ID;
    
    static constexpr const size_t DEFAULT_DURATION = 0;
    static constexpr const char* DEFAULT_DATE = "01/01/2022";
    static constexpr const char* DEFAULT_DEPARTURE = "Unknown";
    static constexpr const char* DEFAULT_ARRIVAL = DEFAULT_DEPARTURE;
    static constexpr const size_t DEFAULT_PRICE = 0;
    static int TravelCounter;

public:
    Travel(
        std::shared_ptr<Transportation> Transport = {},
        size_t Duration = DEFAULT_DURATION,
        std::string Date = DEFAULT_DATE,
        std::string Departure = DEFAULT_DEPARTURE,
        std::string Arrival = DEFAULT_ARRIVAL,
        //std::shared_ptr<std::vector<std::string>> PassengerList = std::make_shared<std::vector<std::string>>(),
        size_t Price = DEFAULT_PRICE,
        bool IsValid = true
        );
    //Travel::Travel(Travel&& source);

    //getters
    const int& GetID() const;
    const size_t& GetDuration() const;
    const std::string& GetDate() const;
    const size_t& GetPrice() const;
    const std::string& GetDeparture() const;
    const std::string& GetArrival() const;
    const std::shared_ptr<std::vector<std::string>> GetPassengerList() const;
    const std::shared_ptr<Transportation> GetTransport() const;
    const bool& GetIsValid() const;

    //setters
    void SetPrice(const int& NewPrice);
    void SetIsValid(const bool& IsValid);

    ~Travel() = default;


};

