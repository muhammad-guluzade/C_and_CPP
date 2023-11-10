
/* Muhammad A Guluzade – 2545952
I read and accept the submission rules and the extra rules specified in
each question. This is my own work that is done by myself only */


#include "company.h"
#include <cstring>

using namespace std;

//=================================================

//Default constructor
//  Works as described in the assignment

//=================================================

Bus::Bus(){
    id = -1;
    num_of_seats = 0;

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
//  and additionally sets the number of seats in the bus

//=================================================

Bus::Bus(int given_id, int given_num_of_seats, char *given_brand, char *given_model, char *given_plate_no) : Vehicle(given_id, given_brand, given_model, given_plate_no){
    num_of_seats = given_num_of_seats;
}

//=================================================

//printVehicle
//  Functionality
//    This is special function, because it has 2 declarations.
//    Without inputs
//      This one basically prints the details of the bus
//    With input (type)
//      This one is used in order to print specifically the Bus object

//=================================================

void Bus::printVehicle() {
    cout<<"Vehicle ID: "<<id<<
        ", Brand: "<<brand<<
        ", Model: "<<model<<
        ", Plate Number: "<<plate_no<<
        ", Car Type: Bus"<<
        ", Number of Seats: "<<num_of_seats;
    cout<<endl;
}

void Bus::printVehicle(int type) {
    if(type!=0){
        return;
    }
    else{
        printVehicle();
    }
}

//=================================================

//checkSuitability()
//  Inputs
//    seats
//      this is number of seats entered by the user
//  Functionality
//    It checks whether the bus has enough seats

//=================================================

int Bus::checkSuitability(int seats){
    if(num_of_seats>=seats){
        return 1;
    }
    return 0;
}

//=================================================

//Destructor
//  Works as a destructor of Vehicle class (see line 94 in Vehicle.cpp)

//=================================================

Bus::~Bus(){
    delete [] plate_no;
    delete [] model;
    delete [] brand;
}

//=================================================

//annualCost()
//  Functionality
//    Returns the cost of the vehicle as specified in the assignment

//=================================================

float Bus::annualCost(){
    int number_of_times_serviced;
    float maintenance_cost;

    cout<<"Enter the maintenance cost: ";
    cin>>maintenance_cost;
    cout<<"Enter the number of times bus has been serviced: ";
    cin>>number_of_times_serviced;

    return maintenance_cost*number_of_times_serviced;
}

//=================================================

//get_vehicle_type()
//  Functionality
//    Returns 0 when the vehicle is bus object

//=================================================

int Bus::get_vehicle_type(){
    return 0;
}

//=================================================