





#include "company.h"
#include <cstring>

//=================================================

//Default constructor
//  Works as described in the assignment

//=================================================

Vehicle::Vehicle() {
    id = -1;
    brand = new char[100];
    plate_no = new char[100];
    model = new char[100];

    strcpy(brand, "Undefined");
    strcpy(plate_no, "Undefined");
    strcpy(model, "Undefined");
}

//=================================================

//Constructor
//  Inputs
//    given_id
//      the ID of the vehicle
//    given_brand
//      the brand of the vehicle
//    given_model
//      the model of the vehicle
//    given_plate_no
//      the plate number of the vehicle
//  Functionality
//    Sets the parameters to "given" parameters

//=================================================

Vehicle::Vehicle(int given_id, char given_brand[], char given_model[], char given_plate_no[]) {
    id = given_id;
    brand = new char[100];
    plate_no = new char[100];
    model = new char[100];

    strcpy(brand, given_brand);
    strcpy(plate_no, given_plate_no);
    strcpy(model, given_model);
}

//=================================================

//Getters & Setters
//  The functions below do not need any extra explanation for each
//  because all they do it set or get the private/protected member
//  of Branch class

//=================================================

void Vehicle::set_id(int given_id) {
    id = given_id;
}

void Vehicle::set_brand(char given_brand[]) {
    brand = new char[100];
    strcpy(brand, given_brand);
}

void Vehicle::set_model(char given_model[]) {
    model = new char[100];
    strcpy(model, given_model);
}

void Vehicle::set_plate_no(char given_plate_no[]) {
    plate_no = new char[100];
    strcpy(plate_no, given_plate_no);
}

int Vehicle::get_id() {
    return id;
}

char* Vehicle::get_brand() {
    return brand;
}

char* Vehicle::get_model() {
    return model;
}

char* Vehicle::get_plate_no() {
    return plate_no;
}

//=================================================

//Destructors
//  The destructor of Vehicle class, destroys the brand, model,
//  and plate number of the vehicle

//=================================================

Vehicle::~Vehicle() {
    delete [] brand;
    delete [] model;
    delete [] plate_no;
}

//=================================================

//Virtual functions
//  The functions defined below are declared both in Car and Bus
//  classes. This is to have access to both Car and Bus functions
//  from the Vehicle class.

//=================================================

void Vehicle::printVehicle() {
    //a function to print vehicle, overloaded by Bus and Car classes
}

void Vehicle::printVehicle(int) {
    //a function to print vehicle selectively, based on vehicle type (Bus or Car)
}

int Vehicle::checkSuitability(int) {
    //a function to check whether a Car/Bus is suitable to carry number of people
    return 0;
}

float Vehicle::annualCost() {
    //a function to return the annual cost of either Car or Bus
    return 0.0;
}

int Vehicle::get_vehicle_type() {
    //a function to get a vehicle type (Car or Bus) (Bus - 0, Car - 1), to count their number
    return 0;
}

//=================================================
