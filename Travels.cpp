
#include <ostream>
#include <iostream>
#include <sstream>
#include "Travel.h"
#include <map>
#include "time.h"
#include <random>
#include "Train.h"
#include "Plane.h"

const size_t GetUserInput(const size_t MaxChoice);
void DisplayMenu();
std::shared_ptr<Travel> CreateTravel();
const std::string GetUserInputString();
const size_t GetUserInputPositiveNumber();
int RandomNumber(const size_t& a, const size_t& b);
const size_t GetUserInputNumber();



int main(int argc, char* argv[])
{
    
    DisplayMenu();    
    return 0;
}
//Display main menu
void DisplayMenu()
{
    constexpr size_t EndInput = 4;
    size_t UserInput{};
    std::map<size_t, std::shared_ptr<Travel>> ListOfTravels;
    do
    {
        std::cout << "1. Add travel " << std::endl;
        std::cout << "2. Update travel " << std::endl;
        std::cout << "3. Display travels " << std::endl;
        std::cout << "4. Exit " << std::endl;
        std:: cout << "Enter your choice " << std::endl;
        
        UserInput = GetUserInput(EndInput);
        switch(UserInput)
        {
        case 1 :
            {
                std::shared_ptr<Travel> T = CreateTravel();
                //std::cout << "Adding travel !" <<std::endl;
                std::cout << std::endl;
                std::cout << *T << std::endl;
                ListOfTravels[T->GetID()] = T;//mapping Travel id with it's pointer
                break;
            
            }
        case 2 :
            {
                std::cout << " Enter the ID of the travel you wish to update :" << std::endl;
                size_t UserInputUpdate = GetUserInputNumber();
                auto it = ListOfTravels.find(UserInputUpdate);
                if (it != ListOfTravels.end()) {
                    std::cout << *(it->second) << std::endl;
                    std::cout << std::endl;
                    std::cout << "What do you want to update ? " << std::endl;
                    std::cout << "1. Price " << std::endl;
                    std::cout << "2. Travel status " << std::endl;
                    std::cout << "3. Nothing " << std::endl;
                    const size_t MaxUpdateChoice = 3;
                    UserInputUpdate = GetUserInput(MaxUpdateChoice);

                    switch (UserInputUpdate) {
                        case 1:
                            {
                                size_t PriceUpdated{ 0 };
                                std::cout << "Please enter a price." << std::endl;
                                std::cout << "New price : ";
                                PriceUpdated = GetUserInputPositiveNumber();
                                it->second->SetPrice(PriceUpdated);
                                break;
                            }
                        case 2 :
                            {
                                std::cout << "Please choose a new status" << std::endl;
                                std::cout << "1. Suspended" << std::endl;
                                std::cout << "2. Valid" << std::endl;
                                std::cout << "Your choice : ";
                                const size_t MaxStatusUpdateChoice = 2;
                                size_t UserInputStatusUpdate = GetUserInput(MaxStatusUpdateChoice);
                                it->second->SetIsValid(UserInputStatusUpdate-1);
                                break;
                            }
                        default:
                            break;
                            
                    }
                }
                else
                    std::cout << "Travel ID not found." << std::endl;
                break;
            }
        case 3:
        {
            for (const auto& elem : ListOfTravels) {
                std::cout << *(elem.second) << std::endl;
            }
            break;
        }
        default:
            break;
        }
        
    }while(UserInput != EndInput);


    
}
//returns a pointer to a Travel object
std::shared_ptr<Travel> CreateTravel() {
    std::cout << "Please choose a transportation type." << std::endl;
    std::cout << "1. Train" << std::endl;
    std::cout << "2. Plane" << std::endl;
    std::cout << "Your choice : ";

    int UserInput{1};
    size_t MaxChoice = 2;
    UserInput = GetUserInput(MaxChoice);

    std::string DepartureCity;
    std::cout << "Please choose a departure city." << std::endl;
    std::cout << "Your choice : ";
    DepartureCity = GetUserInputString();

    std::string ArrivalCity;
    std::cout << "Please choose an arrival city." << std::endl;
    std::cout << "Your choice : ";
    ArrivalCity = GetUserInputString();

    size_t Price{ 0 };
    std::cout << "Please enter a price." << std::endl;
    std::cout << "Your price : ";
    Price = GetUserInputPositiveNumber();

    //generating a random travel date, might be invalid date
    std::string TravelDate;
    int Day{};
    int Month{};
    int Year{};

    Day = RandomNumber(01, 31);
    Month = RandomNumber(01, 12);
    Year = RandomNumber(2022, 2025);

    std::string DayString = std::to_string(Day);
    std::string MonthString = std::to_string(Month);
    std::string YearString = std::to_string(Year);

    TravelDate = DayString + "/" + MonthString + "/" + YearString;
    //std::cout << TravelDate << std::endl;

    //generating random travel duration
    size_t Duration{ 0 };
    const int MinDuration = 1; //in minute
    const int MaxDuration = 1440;//in minute
    Duration = RandomNumber(MinDuration, MaxDuration);

    //generating random number of max passengers for the transport
    size_t MaxPassengers{};
    const int MinPassengers = 1; 
    const int MaxMaxPassengers = 250;
    MaxPassengers = RandomNumber(MinPassengers, MaxMaxPassengers);

    switch (UserInput) {

        case 1:
        {
            //generating random number of train cars
            size_t NumberOfCars{};
            const int MinCars = 2;
            const int MaxCars = 16;
            NumberOfCars = RandomNumber(MinCars, MaxCars);
            std::shared_ptr<Train> Tr = std::make_shared<Train>(MaxPassengers, NumberOfCars);
            Travel T = Travel(Tr, Duration, TravelDate, DepartureCity, ArrivalCity, Price, true);
            return std::make_shared<Travel>(T);
            break;
        }
        case 2: {
            //generating random cargo capacity
            size_t CargoCapacity{};
            const int MinCargoCapacity = 250;
            const int MaxCargoCapacity = 5000;
            CargoCapacity = RandomNumber(MinCargoCapacity, MaxCargoCapacity);
            std::shared_ptr<Plane> Tr = std::make_shared<Plane>(MaxPassengers,CargoCapacity);
            Travel T = Travel(Tr, Duration, TravelDate, DepartureCity, ArrivalCity, Price, true);
            return std::make_shared<Travel>(T);
            break;
        }
        default:
            break;
    }

    return nullptr;
}
//check if Input is between 0 and range (parameter)
const size_t GetUserInput(const size_t MaxChoice)
{
    size_t Input{};
    std::string entry{};
    bool done = false;

    do
    {
        std::cin >> entry;
        std::istringstream validator{entry};

        if(validator >> Input && (Input>0 && Input <=MaxChoice)) //checking if Input is of type Size_T and in the right range
            done = true;
        else
            std::cout << "Invalid value. Please try again." << std::endl;
    }while(!done);

    return Input;
}

//checking if value is a string
const std::string GetUserInputString()
{
    std::string Input{};
    std::string entry{};
    bool done = false;

    do
    {
        std::cin >> entry;
        std::istringstream validator{ entry };

        if (validator >> Input && Input.length() >0 ) 
            done = true;
        else
            std::cout << "Invalid value. Please try again." << std::endl;
    } while (!done);

    return Input;
}


//checking if value is both positive and valid
const size_t GetUserInputPositiveNumber()
{
    size_t Input{};
    std::string entry{};
    bool done = false;

    do
    {
        std::cin >> entry;
        std::istringstream validator{ entry };

        if (validator >> Input && (Input > 0)) //checking if Input is of type Size_T and positive 
            done = true;
        else
            std::cout << "Invalid value. Please try again." << std::endl;
    } while (!done);

    return Input;
}

//checking if value is >=0 and valid
const size_t GetUserInputNumber()
{
    size_t Input{};
    std::string entry{};
    bool done = false;

    do
    {
        std::cin >> entry;
        std::istringstream validator{ entry };

        if (validator >> Input && (Input >= 0)) //checking if Input is of type Size_T and positive 
            done = true;
        else
            std::cout << "Invalid value. Please try again." << std::endl;
    } while (!done);

    return Input;
}
//generating a randum number between 2 positive values
int RandomNumber(const size_t& a, const size_t& b)
{
    std::random_device rd;  //Will be used to obtain a seed for the random number engine
    std::mt19937 gen(rd()); //Standard mersenne_twister_engine seeded with rd()
    std::uniform_int_distribution<int> distribution(a, b);
    return distribution(gen);
}