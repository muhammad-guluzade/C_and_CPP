





#include "company.h"
#include <cstring>

using namespace std;

//=================================================

//Default constructor
//  Works as described in the assignment

//=================================================

Company::Company() {
    number_of_branches = 0;
    name = new char[100];
    strcpy(name,"Undefined");
}

//=================================================

//Constructor
//  Inputs
//    given_name
//      this is the name of the company
//    given_branch_array
//      this is the array of the branches inside the company
//    given_num_of_branches
//      number of branches inside the company
//  Functionality
//    This constructor takes the inputs described above and a company
//    with the given name, array of branches, and number of branches

//=================================================

Company::Company(char *given_name, Branch given_branch_array[], int given_num_of_branches) {
    name = new char[100];
    strcpy(name,given_name);

    for(int i=0;i<given_num_of_branches-1;i++){
        branches_array[i] = given_branch_array[i];
    }

    number_of_branches = given_num_of_branches;
}

//=================================================

//Getters & Setters
//  The functions below do not need any extra explanation for each
//  because all they do it set or get the private/protected member
//  of Company class

//=================================================

void Company::set_name(char *given_name) {
    strcpy(name, given_name);
}

void Company::set_number_of_branches(int given_num_of_branches) {
    number_of_branches = given_num_of_branches;
}

char* Company::get_name() {
    return name;
}

Branch* Company::get_branches_array() {
    return branches_array;
}

int Company::get_number_of_branches() {
    return number_of_branches;
}

//=================================================

//Destructor
//  The destructor of the Company class only destroys the "name" protected
//  member of the class.

//=================================================

Company::~Company(){
    delete [] name;
}

//=================================================

//addBranch
//  Functionality
//    This function asks the user to enter the name and location of the branch
//    that they want to add. After this, it uses the constructor to initialize
//    and add the created branch into branches array of the company.

//=================================================

void Company::addBranch() {
    int given_branch_id;
    char given_branch_location[100];

    cout<<"Please enter branch's ID: ";
    cin>>given_branch_id;
    cout<<"Please enter the city, where branch is located: ";
    fflush(stdin);
    cin>>given_branch_location;

    branches_array[number_of_branches] = *new Branch(given_branch_id, given_branch_location);
    number_of_branches++;
}

//=================================================

//printBranches
//  Functionality
//    This function simply calls printBranch function (see line 140 in Branches.cpp)
//    for each branch of the company's branch array to print all branches and
//    their number of vehicles

//=================================================

void Company::printBranches() {
    for(int i=0;i<number_of_branches;i++){
        branches_array[i].printBranch();
    }
}

//=================================================

//printVehicles
//  Functionality
//    This function simply calls printVehicles function (see line 153 in Branches.cpp)
//    for each branch of the company's branch array to print all vehicles
//    with all the details in all branches

//=================================================

void Company::printVehicles() {
    for(int i=0; i<number_of_branches;i++){
        branches_array[i].printVehicles();
    }
}

//=================================================

//printVehiclesByType
//  Functionality
//    This function asks the user to enter the type of the Vehicle they want to see
//    and then uses printVehiclesByType function (see line 174 in Branches.cpp) for each branch
//    to determine which vehicles are to be printed according to the entered type

//=================================================

void Company::printVehiclesByType(){
    int type;
    cout<<"Please select the type of the vehicles, You want to see: (0) Bus, (1) Car\nYour choice: ";
    cin>>type;
    for(int i=0; i<number_of_branches; i++){
        branches_array[i].printVehiclesByType(type);
    }
}

//=================================================

//printTypeStatistics
//  Functionality
//    This function calls printTypeStatistics (see line 199 in Branches.cpp) for
//    each branch to print out the number of buses and cars inside each branch

//=================================================

void Company::printTypeStatistics() {
    for(int i=0; i<number_of_branches; i++){
        cout<<"At Branch with ID: "<<branches_array[i].get_id()<<" there are:"<<endl;
        branches_array[i].printTypeStatistics();
    }
}

//=================================================

//printVehiclesBySeat()
//  Functionality
//    This function asks the user to enter the number of seats and then calls
//    printVehiclesBySeat function (see line 225 in Branches.cpp) to print the
//    vehicles in each branch that have enough seats

//=================================================

void Company::printVehiclesBySeat() {
    int seats=0;
    cout<<"Please enter the number of passengers vehicle should be able to carry: ";
    cin>>seats;
    for(int i=0; i<number_of_branches; i++){
        branches_array[i].printVehiclesBySeat(seats);
    }
}

//=================================================

//printAnnualCost()
//  Functionality
//    This function calls printAnnualCost function (see line 254 in Branches.cpp)
//    for each branch to receive the cost of each vehicle and then print out
//    the total cost for each branch as well as total cost for Quick Transports

//=================================================

void Company::printAnnualCost() {
    float cost_of_all_branches=0, cost_of_current_branch=0;
    for(int i=0; i<number_of_branches; i++){
        cost_of_current_branch = branches_array[i].printAnnualCost();
        cout<<"Total Annual Cost for Branch with ID:"<<branches_array[i].get_id()<<" is "<<cost_of_current_branch<<endl;
        cost_of_all_branches += cost_of_current_branch;
    }
    cout<<"Total Annual Cost for Quick Transport is "<<cost_of_all_branches<<endl;
}

//=================================================
