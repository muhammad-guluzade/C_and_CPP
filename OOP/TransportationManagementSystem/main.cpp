
/* Muhammad A Guluzade – 2545952
I read and accept the submission rules and the extra rules specified in
each question. This is my own work that is done by myself only */


//This file contains main function that runs a loop to let the user choose the options
//It contains only one company, as shown in sample output, and it uses the Company class
//functions in order to maintain every operation needed

#include "company.h"

using namespace std;

int main(){
    Company the_company = Company();

    cout<<"Welcome to Quick Transports"<<endl<<endl;
    int choice=0;
    while(choice!=9){
        cout<<"Options:\n"
              "1. Add a new branch to the company.\n"
              "2. Add a new vehicle (car or bus) to a branch.\n"
              "3. Print all the branches along with their cities and the number of vehicles.\n"
              "4. Print the details stored as member variables for the vehicles in each branch.\n"
              "5. Print the details stored as member variables for the vehicles in each branch\n"
              "whose type is a given type.\n"
              "6. Print the number of each type of vehicle in each branch.\n"
              "7. Print the details stored as member variables for the vehicles that can carry a\n"
              "given number of people in each branch.\n"
              "8. Calculate the total annual cost for the company.\n"
              "9. Exit\n"
              "Your selection: ";
        cin>>choice;
        if(choice==1){
            the_company.addBranch();
        }
        //===========================================================================

        //the condition choice==2 is longer than every other condition in this loop
        //  Reason
        //    when the user enters branch ID, the program needs to find the branch with that
        //    ID, and otherwise return the message that signals that there is no branch with
        //    the given ID
        //  Possible solutions
        //    I could implement this process inside addVehicle function, but this would make
        //    a code much more complex than it is currently. It's much simpler to keep the
        //    return type of the functions "void" and keep them without any inputs

        //===========================================================================
        else if(choice==2){
            int j;
            int branch_id;

            cout<<"Please enter the ID of the Branch: ";
            cin>>branch_id;

            for(j=0; j<the_company.get_number_of_branches(); j++){
                if(branch_id==the_company.get_branches_array()[j].get_id()){
                    the_company.get_branches_array()[j].addVehicle();
                    break;
                }
            }

            if(j==the_company.get_number_of_branches()){
                cout<<"There is no branch with ID "<<branch_id<<" at Quick Transport"<<endl<<endl;
            }
        }
        else if(choice==3){
            the_company.printBranches();
        }
        else if(choice==4){
            the_company.printVehicles();
        }
        else if(choice==5){
            the_company.printVehiclesByType();
        }
        else if(choice==6){
            the_company.printTypeStatistics();
        }
        else if(choice==7){
            the_company.printVehiclesBySeat();
        }
        else if(choice==8){
            the_company.printAnnualCost();
        }
        else if(choice==9){
            cout<<"Goodbye!"<<endl;
        }
    }
}