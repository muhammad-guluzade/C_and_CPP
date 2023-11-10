





//Getters and setters
//  Getters
//    Each of "getters" functions provides an ability to get and use certain private member of the class
//    outside the class scope, to provide protection and not change any of the protected variables
//  Setters
//    Each of "setters" functions provides an ability to set the protected values selectively. This is
//    needed to have certain control over the protected variables of the Vehicle class

//Required and additional functions
//  each of the required and additional functions is explained in cpp file that contains this function
//  for example, if you want the explanation of printVehicle() function inside of Vehicle class,
//  refer to Vehicle.cpp

#include <iostream>

//========================
//Vehicle
//========================

#ifndef Veh_h
#define Veh_h
class Vehicle{
protected:
    int id;
    char *brand;
    char *model;
    char *plate_no;
public:
    //================
    //constructors
    //================

    Vehicle();
    Vehicle(int, char*, char*, char*);

    //================
    //getters and setters
    //================

    void set_id(int);
    void set_brand(char*);
    void set_model(char*);
    void set_plate_no(char*);
    int get_id();
    char* get_brand();
    char* get_model();
    char* get_plate_no();

    //================
    //required functions
    //================

    virtual void printVehicle();
    virtual void printVehicle(int);
    virtual int checkSuitability(int);
    virtual float annualCost();

    //================
    //additional functions
    //================

    virtual int get_vehicle_type();

    //================
    //destructor
    //================

    ~Vehicle();

    //================
};

#endif

//========================
//Bus
//========================

#ifndef BUS_h
#define BUS_h

class Bus : public Vehicle{
private:
    int num_of_seats;
public:
    //================
    //constructors
    //================

    Bus();
    Bus(int, int, char*, char*, char*);

    //================
    //required functions
    //================

    int checkSuitability(int) override;
    float annualCost() override;
    void printVehicle() override;
    void printVehicle(int) override;

    //================
    //additional functions
    //================

    int get_vehicle_type();

    //================
    //destructor
    //================

    ~Bus();

    //================
};

#endif

//========================
//Car
//========================

#ifndef Car_h
#define Car_h

class Car : public Vehicle{
private:
    enum carType {None, Sedan, Hatchback, Limousine};
    int car_type;
public:
    //================
    //constructors
    //================

    Car();
    Car(int, char*, char*, char*, int);

    //================
    //required functions
    //================

    int getSeats();
    int checkSuitability(int) override;
    float annualCost() override;
    void printVehicle() override;
    void printVehicle(int) override;

    //================
    //additional functions
    //================

    int get_vehicle_type();

    //================
    //destructor
    //================

    ~Car();

    //================
};

#endif

//========================
//Branch
//========================

#ifndef Branch_h
#define Branch_h

class Branch{
private:
    int id;
    char *city;
    Vehicle *vehicles_array[30];
    int number_of_vehicles;
public:
    //================
    //constructors
    //================

    Branch();
    Branch(int,char*);

    //================
    //getters and setters
    //================

    void set_id(int);
    void set_city(char*);
    void set_number_of_vehicles(int);
    int get_id();
    char* get_city();
    int get_number_of_vehicles();

    //================
    //required functions
    //================

    void addVehicle();
    void printBranch();
    void printVehicles();
    void printVehiclesByType(int);
    void printTypeStatistics();
    void printVehiclesBySeat(int);
    float printAnnualCost();

    //================
    //additional functions
    //================

    int is_there_bus_or_car_in_the_branch(int);
    int is_there_vehicle_with_suitable_number_of_seats(int);

    //================
    //destructor
    //================

    ~Branch();

    //================
};

#endif

//========================
//Company
//========================

#ifndef Company_h
#define Company_h

class Company{
private:
    char *name;
    Branch branches_array[10];
    int number_of_branches;
public:
    //================
    //constructors
    //================

    Company();
    Company(char*, Branch[], int);

    //================
    //getters and setters
    //================

    void set_name(char*);
    void set_number_of_branches(int);
    char* get_name();
    Branch* get_branches_array();
    int get_number_of_branches();

    //================
    //required functions
    //================

    void addBranch();
    void printBranches();
    void printVehicles();
    void printVehiclesByType();
    void printTypeStatistics();
    void printVehiclesBySeat();
    void printAnnualCost();

    //================
    //destructor
    //================

    ~Company();

    //================
};

#endif

//========================
