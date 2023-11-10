#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//DO NOT CHANGE DATA STRUCTURE
struct Customer {
    char name[81];
    int transactions;
    int items_purchased;
    float amount_paid;
};

typedef struct Customer customer;

//DO NOT CHANGE FUNCTION PROTOTYPES
void menu();
void printCustomers(customer *, int);
int countCustomers(FILE*);
void readTransactions(FILE*, customer* ,int);
void heapify(customer*, int, int, int);
void heapSort(customer*, int,int);

//DO NOT CHANGE THE main FUNCTION
int main() {
    FILE *inFile;
    int no_of_customers = 0;
    customer *customers;

    inFile = fopen("transactions.txt", "r");
    if (inFile == NULL){
        printf("File could not be opened.\n");
        exit(1);
    }
    no_of_customers = countCustomers(inFile);
    printf("There are %d unique customers\n", no_of_customers);

    customers = (customer*) malloc(no_of_customers * sizeof (customer));
    fclose(inFile);
    inFile = fopen("transactions.txt", "r");
    if (inFile == NULL){
        printf("File could not be opened.\n");
        exit(1);
    }

    readTransactions(inFile, customers, no_of_customers);
    if (customers == NULL) {
        printf("\nCustomers have NOT been read successfully!\n");
        exit(1);
    }
    printCustomers(customers, no_of_customers);

    char command = 0;
    int exit = 0;
    while (exit != 1) {
        menu();
        printf("\nCommand: ");
        fflush(stdin);
        scanf("%c", &command);

        if (command == '1' || command == '2' || command == '3' || command == '4') {
            heapSort(customers, no_of_customers, command - '0');
            printCustomers(customers, no_of_customers);
        }
        else if (command == '5'){
            exit = 1;
            printf("Goodbye!\n");
        }
        else{
            printf("Please enter a valid command!\n");
        }
    }
    free(customers);
    return 0;
}

//DO NOT CHANGE THE menu FUNCTION
void menu () {
    printf("Please choose one of the following options:\n"
           "(1) Display customers sorted by number of transactions\n"
           "(2) Display customers sorted by number of items purchased\n"
           "(3) Display customers sorted by total amount paid\n"
           "(4) Display customers sorted by average amount paid per transaction\n"
           "(5) Exit\n");
}

//DO NOT CHANGE THE printCustomers FUNCTION

void printCustomers (customer* customers, int no_of_customers) {
    printf("List of customers:\n");
    int i;
    for (i = 0; i < no_of_customers; ++i) {
        printf("Name: %s, number of transactions = %d, number of items = %d, total amount paid = %.2f,"
               " average amount paid per transaction = %.2f\n",
               customers[i].name, customers[i].transactions, customers[i].items_purchased, customers[i].amount_paid,
               customers[i].amount_paid/customers[i].transactions);
    }
}

// =========================
// countCustomers() - Logic explained
//     First, I determine the number of transactions, since it could be the case
//     that each customer made 1 transaction, in which number of transactions will
//     be equal to the number of customers
//
//     Next, I create an array of names in order add only unique, non-repeating names
//     so that I am left with the exact number of customers with different names
// =========================

int countCustomers (FILE *inFile){
    // =========================
    // skipping the first line of the file (column names)
    // =========================
    while(fgetc(inFile) != '\n'){

    }

    // =========================
    //counting the number of transactions
    // =========================
    int transactions=0, number_of_customers=0, counter=0;
    char c;
    while((c = fgetc(inFile)) != EOF){
        if (c == '\n'){
            transactions++;
        }
    }

    char unique_customers[transactions][81], name[81];

    // =========================
    // coming back to the beginning of the file
    // and skipping the first line again
    // =========================
    fseek(inFile, 0, SEEK_SET);
    while(fgetc(inFile) != '\n'){

    }

    // =========================
    // *******************
    // IMPORTANT NOTE ABOUT THE LOOP BELOW
    // It works IFF there is endline ('\n') in the end of the file
    // since it was the format of the file provided in ODTUCLASS
    // *******************
    // =========================

    while(fgetc(inFile) != EOF){
        fseek(inFile, -1, SEEK_CUR);
        fscanf(inFile, "%[^;]", name);
        while(counter < number_of_customers){
            if(strcmp(unique_customers[counter], name) == 0){
                break;
            }
            counter++;
        }
        if(counter == number_of_customers){
            strcpy(unique_customers[number_of_customers], name);
            number_of_customers++;
        }
        while(fgetc(inFile) != '\n'){

        }
        counter = 0;
    }
    return number_of_customers;
}

// =========================
// readTransactions() - Logic explained
//     First, I store all unique names inside *customers dynamic array
//     The reason that I have a separate loop for this task is that I
//     need to iterate through EVERY transaction in order to determine
//     all names present in transactions.txt
//     After storing all unique names, I go to the first transaction of the file
//     and loop through the transactions. For each transaction, I find the person
//     who made the transaction by finding his/her name in unique names array,
//     and increment the other parts of data structure accordingly.
//     After this, we get a finalized list of customers, alongside with their
//     number of transactions, number of items bought, and money spent.
// =========================

void readTransactions (FILE* inFile, customer* customers, int no_of_customers) {

    // =========================
    //skipping the first line
    // =========================
    while(fgetc(inFile) != '\n'){

    }
    // =========================
    // the adders declared below (items_purchased_adder, money_spent_adder)
    // do the addition operations to money spent value and items purchased value
    // of the relevant customer structure
    // =========================
    int i=0, counter=0, items_purchased_adder=0;
    float money_spent_adder=0;
    char name[81];
    // =========================
    // The first loop - only storing unique names
    // =========================
    while(fgetc(inFile) != EOF){
        fseek(inFile, -1, SEEK_CUR);
        fscanf(inFile, "%[^;]", name);
        while(counter < i){
            if(strcmp(customers[counter].name, name) == 0){
                break;
            }
            counter++;
        }
        if(counter == i){
            strcpy(customers[i].name, name);
            customers[i].transactions = 0;
            customers[i].items_purchased = 0;
            customers[i].amount_paid = 0;
            i++;
        }
        while(fgetc(inFile) != '\n'){

        }
        counter = 0;
    }
    // =========================
    // go to beginning of the file and skipping the first line
    // =========================
    fseek(inFile, 0, SEEK_SET);
    counter=0;
    // =========================
    // The second loop which adds the remaining info to the customer structure
    // based on their unique names
    // =========================
    while(fgetc(inFile) != EOF){
        fseek(inFile, -1, SEEK_CUR);
        fscanf(inFile, "%[^;]", name);
        fseek(inFile, 1, SEEK_CUR);
        while(counter < no_of_customers){
            if(strcmp(customers[counter].name, name) == 0){
                break;
            }
            counter++;
        }
        fscanf(inFile, "%[^;]", name);
        fseek(inFile, 1, SEEK_CUR);
        fscanf(inFile, "%[^;]", name);
        fseek(inFile, 1, SEEK_CUR);
        fscanf(inFile, "%[^;]", name);
        fseek(inFile, 1, SEEK_CUR);
        fscanf(inFile, "%d", &items_purchased_adder);
        fseek(inFile, 1, SEEK_CUR);
        fscanf(inFile, "%f", &money_spent_adder);
        customers[counter].transactions++;
        customers[counter].items_purchased += items_purchased_adder;
        customers[counter].amount_paid += money_spent_adder * items_purchased_adder;
        while(fgetc(inFile) != '\n'){

        }
        counter=0;
    }
}

// =========================
// heapify function implements a typical heap sort, but in addition,
// as requested by the assignment, it sorts the customers based on
// certain criteria.
// =========================

void heapify(customer* customers, int no_of_customers, int i, int criteria) {
    int biggest = i, left = 2*i+1, right = 2*i+2;

    if(criteria == 1){
        if (left < no_of_customers && customers[left].transactions > customers[biggest].transactions){
            biggest = left;
        }
        if (right < no_of_customers && customers[right].transactions > customers[biggest].transactions){
            biggest = right;
        }
        if (biggest != i) {
            customer temp_customer = customers[i];
            customers[i] = customers[biggest];
            customers[biggest] = temp_customer;
            heapify(customers, no_of_customers, biggest, criteria);
        }
    }
    else if(criteria == 2){
        if (left < no_of_customers && customers[left].items_purchased > customers[biggest].items_purchased){
            biggest = left;
        }
        if (right < no_of_customers && customers[right].items_purchased > customers[biggest].items_purchased){
            biggest = right;
        }
        if (biggest != i) {
            customer temp_customer = customers[i];
            customers[i] = customers[biggest];
            customers[biggest] = temp_customer;
            heapify(customers, no_of_customers, biggest, criteria);
        }
    }
    else if(criteria == 3){
        if (left < no_of_customers && customers[left].amount_paid > customers[biggest].amount_paid){
            biggest = left;
        }
        if (right < no_of_customers && customers[right].amount_paid > customers[biggest].amount_paid){
            biggest = right;
        }
        if (biggest != i) {
            customer temp_customer = customers[i];
            customers[i] = customers[biggest];
            customers[biggest] = temp_customer;
            heapify(customers, no_of_customers, biggest, criteria);
        }
    }
    else if(criteria == 4){
        if (left < no_of_customers && (customers[left].amount_paid / (float)customers[left].transactions) > (customers[biggest].amount_paid / (float)customers[biggest].transactions)){
            biggest = left;
        }
        if (right < no_of_customers && (customers[right].amount_paid / (float)customers[right].transactions) > (customers[biggest].amount_paid / (float)customers[biggest].transactions)){
            biggest = right;
        }
        if (biggest != i) {
            customer temp_customer = customers[i];
            customers[i] = customers[biggest];
            customers[biggest] = temp_customer;
            heapify(customers, no_of_customers, biggest, criteria);
        }
    }
}

// =========================
// heapSort function implements a typical heap sort and uses
// heapify in order to finalize the heap sorting algorithm
// Just like heapify, it works with certain criteria given
// and passes it to the heapify function
// =========================

void heapSort(customer* customers, int no_of_customers, int criteria) {
    int i;

    for (i=no_of_customers/2-1; i>=0; i--)
        heapify(customers, no_of_customers, i, criteria);

    for (i=no_of_customers-1; i>0; i--) {
        customer temp_customer = customers[0];
        customers[0] = customers[i];
        customers[i] = temp_customer;
        heapify(customers, i, 0, criteria);
    }
}
