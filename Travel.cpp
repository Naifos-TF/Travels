#include "Travel.h"

int Travel::TravelCounter = 0;

Travel::Travel(std::shared_ptr<Transportation> Transport, size_t Duration, std::string Date, std::string Departure, std::string Arrival, size_t Price, bool IsValid)
    : ID{ TravelCounter }, Transport{ Transport }, Date{ Date }, Duration{ Duration }, Departure{ Departure }, Arrival{ Arrival }, Price{ Price }, IsValid{ IsValid }
{
    TravelCounter++;
}
//// Move constructor not usefull since using shared pointers
//Travel::Travel(Travel&& source)
//    : ID{ source.TravelCounter }, Date{ source.Date }, Duration{ source.Duration }, Departure{ source.Departure }, Arrival{ source.Arrival }, Price{ source.Price }, IsValid{ source.IsValid }, Transport(source.Transport) {
//    source.Transport = nullptr;
//}

 std::ostream& operator<<(std::ostream& Os, const Travel& T){

    Os << "ID : " << T.GetID() << std::endl;
    Os << "Transport : " << T.GetTransport()->GetName() << std::endl;
    Os << "Transport ID : " << T.GetTransport()->GetId() << std::endl;
    Os << "Date : " << T.GetDate() << std::endl;
    Os << "Price : " << T.GetPrice() << std::endl;
    Os << "Duration : " << T.GetDuration() << " minutes" << std::endl;
    Os << "Departure : " << T.GetDeparture() << std::endl;
    Os << "Arrival : " << T.GetArrival() << std::endl;
    T.GetIsValid() == 1 ? (Os << "Status : Valid") : (Os << "Status : Suspended");
    Os << std::endl;
    //Os << "Passenger list : " << T.GetPassengerList() << std::endl;
    return Os;
}

const int& Travel::GetID() const
{
    return this->ID;
}

const std::string& Travel::GetDate() const
{
    return this->Date;
}

const size_t& Travel::GetPrice() const
{
    return this->Price;
}

const size_t& Travel::GetDuration() const
{
    return this->Duration;
}

const std::string& Travel::GetDeparture() const
{
    return this->Departure;
}

const std::string& Travel::GetArrival() const
{
    return this->Arrival;
}

const std::shared_ptr<Transportation> Travel::GetTransport() const
{
    return this->Transport;
}

const bool& Travel::GetIsValid() const
{
    return this->IsValid;
}

void Travel::SetPrice(const int& NewPrice)
{
    if (NewPrice >= 0) {
        this->Price = NewPrice;
    }
}

void Travel::SetIsValid(const bool& IsValid)
{
    this->IsValid = IsValid;
}

