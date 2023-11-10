





#include "company.h"
#include <cstring>

using namespace std;

//=================================================

//Default constructor
//  Works as described in the assignment

//=================================================

Car::Car() {
    car_type = None;
    id = -1;
    brand = new char[100];
    model = new char[100];
    plate_no = new char[100];

    strcpy(brand, "Undefined");
    strcpy(model, "Undefined");
    strcpy(plate_no, "Undefined");
}

//=================================================

//Constructor
//  This constructor uses Vehicle constructor (see line 22 in Vehicle.cpp)
//  and additionally sets the car type

//=================================================

Car::Car(int given_id, char *given_brand, char *given_model, char *given_plate_no, int given_car_type) : Vehicle(given_id,given_brand,given_model,given_plate_no){
    car_type = given_car_type;
}

//=================================================

//Destructor
//  Works as a destructor of Vehicle class (see line 94 in Vehicle.cpp)

//=================================================

Car::~Car(){
    delete [] plate_no;
    delete [] model;
    delete [] brand;
}

//=================================================

//printVehicle
//  Functionality
//    This is special function, because it has 2 declarations.
//    Without inputs
//      This one basically prints the details of the car
//    With input (type)
//      This one is used in order to print specifically the Car object

//=================================================

void Car::printVehicle() {
    cout<<"Vehicle ID: "<<id<<
          ", Brand: "<<brand<<
          ", Model: "<<model<<
          ", Plate Number: "<<plate_no;
    if(car_type == 1){
        cout<<", Car Type: Sedan";
    }
    else if(car_type == 2){
        cout<<", Car Type: Hatchback";
    }
    else if(car_type == 3){
        cout<<", Car Type: Limousine";
    }
    cout<<endl;
}

void Car::printVehicle(int type) {
    if(type==0){
        return;
    }
    else{
        printVehicle();
    }
}

//=================================================

//getSeats
//  Functionality
//    Returns a number of seats for each vehicle as specified
//    in the assignment.

//=================================================

int Car::getSeats() {
    if(car_type==Sedan || car_type==Hatchback){
        return 5;
    }
    else if(car_type==Limousine){
        return 6;
    }
    else{
        return 0;
    }
}

//=================================================

//checkSuitability()
//  Inputs
//    seats
//      this is number of seats entered by the user
//  Functionality
//    It checks whether the car has enough seats using
//    getSeats function, which returns a number of seats

//=================================================

int Car::checkSuitability(int seats){
    if(getSeats()>=seats){
        return 1;
    }
    return 0;
}

//=================================================

//annualCost()
//  Functionality
//    Returns the cost of the vehicle as specified in the assignment

//=================================================

float Car::annualCost(){
    float kms_driven;

    cout<<"Enter the kilometres driven: ";
    cin>>kms_driven;

    return kms_driven*10;
}

//=================================================

//get_vehicle_type()
//  Functionality
//    Returns 1 when the vehicle is car object

//=================================================

int Car::get_vehicle_type(){
    return 1;
}

//=================================================
