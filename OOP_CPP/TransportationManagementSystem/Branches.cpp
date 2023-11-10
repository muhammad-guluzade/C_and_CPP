





#include "company.h"
#include <cstring>

using namespace std;

//=================================================

//Default constructor
//  Works as described in the assignment

//=================================================

Branch::Branch() {
    id = -1;
    city = new char[100];
    strcpy(city, "Undefined");
    number_of_vehicles = 0;
}

//=================================================

//Constructor
//  Inputs
//    given_id
//      this is the ID of the branch
//    given_city
//      this is the city where the branch is located
//  Functionality
//    This function takes the ID and the city where branch is located
//    and creates a branch with these parameters. It also initializes
//    number of vehicles to zero.

//=================================================

Branch::Branch(int given_id, char *given_city) {
    id = given_id;
    city = new char[100];
    strcpy(city, given_city);
    number_of_vehicles = 0;
}

//=================================================

//Getters & Setters
//  The functions below do not need any extra explanation for each
//  because all they do it set or get the private/protected member
//  of Branch class

//=================================================

void Branch::set_id(int given_id) {
    id = given_id;
}

void Branch::set_city(char *given_city) {
    city = new char[100];
    strcpy(city, given_city);
}

void Branch::set_number_of_vehicles(int given_num_of_vehicles) {
    number_of_vehicles = given_num_of_vehicles;
}

int Branch::get_id() {
    return id;
}

char* Branch::get_city(){
    return city;
}

int Branch::get_number_of_vehicles() {
    return number_of_vehicles;
}

//=================================================

//Destructor
//  The destructor of the Branch class only destroys the "city" private
//  member of the class.

//=================================================

Branch::~Branch(){
    delete [] city;
}

//=================================================

//addVehicle
//  Functionality
//    It checks whether the user entered a correct vehicle type (0-3)
//    If the entered type is correct, it asks the user enter the brand,
//    model, and plate number of the vehicle.
//    After this, if the vehicle is Bus, it also asks for seat number.
//    Then it adds the vehicle to vehicles array using "new", because
//    it's the array of pointers

//=================================================

void Branch::addVehicle() {
    int vehicle_kind = -1, vehicle_id;
    char vehicle_brand[100], vehicle_model[100], vehicle_plate_no[100];

    while(vehicle_kind < 0 || vehicle_kind > 3){
        cout<<"What kind of vehicle would You like to add?\n"
              "Possible options: (0) Bus, (1) Sedan, (2) Hatchback, (3) Limousine\n"
              "Your choice:";
        cin>>vehicle_kind;
        if(vehicle_kind < 0 || vehicle_kind > 3){
            cout<<"Please enter a valid vehicle kind"<<endl;
        }
    }

    cout<<"Please enter the ID of the vehicle: ";
    cin>>vehicle_id;
    cout<<"Please enter the brand of the vehicle:";
    fflush(stdin);
    cin>>vehicle_brand;
    cout<<"Please enter the model of the vehicle:";
    fflush(stdin);
    cin>>vehicle_model;
    cout<<"Please enter the plate number of the vehicle:";
    fflush(stdin);
    cin>>vehicle_plate_no;

    if(vehicle_kind == 0) {
        int number_of_seats;
        cout << "Please enter the number of seats on the Bus: ";
        cin >> number_of_seats;
        vehicles_array[number_of_vehicles] = new Bus(vehicle_id, number_of_seats, vehicle_brand, vehicle_model, vehicle_plate_no);
    }
    else{
        vehicles_array[number_of_vehicles] = new Car(vehicle_id, vehicle_brand, vehicle_model, vehicle_plate_no, vehicle_kind);
    }
    number_of_vehicles++;
    cout<<"Vehicle is successfully added!"<<endl<<endl;
}

//=================================================

//printBranch
//  Functionality
//    This is the function that simply gives the city where the current branch
//    is located and also the current number of vehicles inside of that branch

//=================================================

void Branch::printBranch() {
    cout<<"City: "<<city<<", Number of vehicles: "<<number_of_vehicles<<endl;
}

//=================================================

//printVehicles
//  Functionality
//    This one first checks whether the branch contains any vehicles at all
//    to avoid printing the ID of the branch when it is empty
//    Then it runs the loop for each vehicle of the vehicles array using
//    printVehicle function (see line 117 in Vehicle.cpp, line 50 in Car.cpp,
//    line 38 in Bus.cpp) to print the details of each vehicle.

//=================================================

void Branch::printVehicles() {
    if(number_of_vehicles!=0){
        cout<<"Vehicles at Branch with ID "<<id<<":"<<endl;
    }
    for(int i=0; i<number_of_vehicles;i++){
        vehicles_array[i]->printVehicle();
    }
}

//=================================================

//printVehiclesByType
//  Inputs
//    type
//      this is the type given by the user
//  Functionality
//    This function has the helper function that helps to find out
//    whether there is a vehicle of the entered type. This is done to
//    avoid printing the ID of the Branch if it does not contain
//    vehicles of the type that the user entered.
//    Then, it calls printVehicle function (see line 117 in Vehicle.cpp, line 50 in Car.cpp,
//    line 38 in Bus.cpp) for each vehicle in order to print the details

//=================================================

void Branch::printVehiclesByType(int type) {
    if(is_there_bus_or_car_in_the_branch(type)){
        cout<<"Vehicles at Branch with ID "<<id<<":"<<endl;
    }
    for(int i=0; i<number_of_vehicles; i++){
        vehicles_array[i]->printVehicle(type);
    }
}

//=================================================

//printTypeStatistics
//  Functionality
//    This function contains helper function that helps to determine
//    the vehicle type for each vehicle in the array of vehicles, and
//    thereby count the number of Buses and Cars.
//    (consider line 135 in Vehicle.cpp, line 145 in Car.cpp, line 120 in Bus.cpp
//    for get_vehicle_type function)

//=================================================

void Branch::printTypeStatistics() {
    int num_of_buses = 0, num_of_cars = 0;
    for(int i=0; i<number_of_vehicles; i++){
        if(vehicles_array[i]->get_vehicle_type() == 1){
            num_of_cars++;
        }
        else{
            num_of_buses++;
        }
    }
    cout<<num_of_buses<<" bus(es)"<<endl;
    cout<<num_of_cars<<" car(s)"<<endl;
}

//=================================================

//printVehiclesBySeat()
//  Inputs
//    seats
//      this is the number of the seats entered by the user
//  Functionality
//    This function contains helper function that helps to
//    find out whether there is a vehicle that has enough number
//    of seats inside of vehicles array. This is done to avoid
//    printing Branch ID when the branch does not contain any
//    vehicle of the suitable number of seats
//    Then it calls checkSuitability function (see line 125 in Vehicle.cpp,
//    line 69 in Bus.cpp, line 109 in Car.cpp) for each vehicle to find out
//    and print which of the vehicles has enough seats

//=================================================

void Branch::printVehiclesBySeat(int seats) {
    if(is_there_vehicle_with_suitable_number_of_seats(seats)){
        cout<<"Vehicle at Branch with ID: "<<id<<endl;
    }
    for(int i=0; i<number_of_vehicles; i++){
        if(vehicles_array[i]->checkSuitability(seats)){
            vehicles_array[i]->printVehicle();
        }
    }
}

//=================================================

//printAnnualCost()
//  Functionality
//    This function checks whether there are vehicles at all
//    to avoid printing the ID of the branch when the branch is empty.
//    Then it calls annualCost function (see line 130 in Vehicles.cpp,
//    line 100 in Bus.cpp, line 128 in Car.cpp) for each vehicle in order
//    to calculate the total cost of the vehicles for this branch, and
//    return it. It returns it because we need to add up the costs
//    of all branches to get the total cost of Quick Transports

//=================================================

float Branch::printAnnualCost() {
    float cost=0;
    if(number_of_vehicles != 0){
        cout<<"Vehicles at Branch with ID "<<id<<":"<<endl;
    }
    for(int i=0; i<number_of_vehicles; i++){
        cout<<"Vehicle "<<i+1<<":"<<endl;
        cost += vehicles_array[i]->annualCost();
    }
    return cost;
}

//=================================================

//is_there_bus_or_car_in_the_branch
//  Inputs
//    type
//      the type of the vehicle entered by the user
//  Functionality
//    It runs a loop for each car until it finds the vehicle
//    of the given type, and returns 1. If it doesn't find anything, it returns 0.

//=================================================

int Branch::is_there_bus_or_car_in_the_branch(int type){
    for(int i=0; i<number_of_vehicles; i++){
        if(vehicles_array[i]->get_vehicle_type() == type){
            return 1;
        }
    }
    return 0;
}

//=================================================

//is_there_vehicle_with_suitable_number_of_seats
//  Inputs
//    seats
//      number of seats entered by the user
//  Functionality
//    It is very similar to is_there_bus_or_car_in_the_branch function.
//    It runs a loop and immediately returns 1 if it found a vehicle with
//    suitable number of seats. It returns zero if it didn't find such vehicle.

//=================================================

int Branch::is_there_vehicle_with_suitable_number_of_seats(int seats) {
    for(int i=0; i<number_of_vehicles; i++){
        if(vehicles_array[i]->checkSuitability(seats)){
            return 1;
        }
    }
    return 0;
}

//=================================================
