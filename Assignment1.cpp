#include <iostream>
#include <string.h>
#include <fstream>
#include <iomanip>
using namespace std;

/*********************************************************
//Following is the declaration of a order record
**********************************************************/
class order_record {
public:
   string pname;
   string cname;
   double plant_cost;
   double quantity;
   double purchase_tax;
   double net_cost;
   double discount;
   double total_cost;
};

// Prototypes for your functions: input, output and process will go here

void input(ifstream&, order_record&);
void output(const order_record&);
void process(order_record&);

// Function implementations will go here

///**********************************************************************************
//Name: input
//Precondition: The variables (plant name, country name, plant cost, quantity)
//of the order record have not been initialized
//Postcondition: The variables (plant name, country name, plant cost, quantity)
//of the order record have been initialized
//Description: Get input (values of plant_name, country name, plant cost, quantity)
//from data file order record (p_record).

//PURPOSE: SHOW ME THAT YOU KNOW HOW TO READ INPUT AND USE INPUT (CALL BY VALUE) & OUTPUT (CALL BY
//VALUE) PARAMETERS
//**********************************************************************************
void input(ifstream& in, order_record& plant_record) {
   in >> plant_record.pname;
   //add more code to read the rest of the fields (country name, plant cost, quantity) into the
   //order record, plant_record
   in >> plant_record.cname;
   in >> plant_record.plant_cost;
   in >> plant_record.quantity;
}

///**********************************************************************************
//Name: output
//Precondition: order record should contain some data and should not be null
//Postcondition: order record data should be seen on console screen
//Description: Prints the information of order record on the console screen
//**********************************************************************************
void output(const order_record& plant_record) {
   //Use the following statement to help you format your ouput. These
   //statements are called the magic formula.
   cout.setf(ios::showpoint);
   cout.precision(2);
   cout.setf(ios::fixed);
   /*************************************/
  
   // setw manipulator fixes the width within which the data will be displayed,
   // left makes the data left aligned while right aligns it to the right
   cout << setw(11) << left << plant_record.pname << "\t";
   //add more code to print all the fields in the order record
   cout << setw(7) << left << plant_record.cname << "\t";
   cout << setw(7) << right << plant_record.plant_cost << "\t";
   cout << setw(4) << right << (int) plant_record.quantity << "\t";
   cout << setw(8) << right << plant_record.net_cost << "\t";
   cout << setw(7) << right << plant_record.discount << "\t";
   cout << setw(8) << right << plant_record.purchase_tax << "\t";
   cout << setw(10) << right << plant_record.total_cost << endl;
}

///**********************************************************************************
//Name: process
//Precondition: purchase_tax, net_cost, discount and total_cost variables are undefined
//Postcondition: The above mentioned variables are initialized with appropriate calculated values
//Description: Calculates the tax and various costs that are not yet done in the order record
//               to finally calculate the total cost
//**********************************************************************************

//Note: there is one 1 input/output parameter
void process(order_record& plant_record) {
   //put your code here to process/calculate the net cost, purchase tax, discount, and total cost
   //for the plant_record
   double tax_rate = 0;
   // Considering the tax rate based on the country
   if(strcmp(plant_record.cname.c_str(), "dade") == 0) {
       tax_rate = 6.5;
   }
   else if(strcmp(plant_record.cname.c_str(), "broward") == 0) {
       tax_rate = 6;
   }
   else if(strcmp(plant_record.cname.c_str(), "palm") == 0) {
       tax_rate = 7;
   }
   // Calculating the net cost
   plant_record.net_cost = plant_record.quantity * plant_record.plant_cost;
   // Calculating the discount
   if(plant_record.quantity == 0)
       plant_record.discount = 0;
   else if(plant_record.quantity >= 1 && plant_record.quantity <= 5)
       plant_record.discount = 1 * plant_record.net_cost / 100;
   else if(plant_record.quantity >= 6 && plant_record.quantity <= 11)
       plant_record.discount = 3 * plant_record.net_cost / 100;
   else if(plant_record.quantity >= 12 && plant_record.quantity <= 20)
       plant_record.discount = 5 * plant_record.net_cost / 100;
   else if(plant_record.quantity >= 21 && plant_record.quantity <= 50)
       plant_record.discount = 8 * plant_record.net_cost / 100;
   else if(plant_record.quantity > 50)
       plant_record.discount = 12 * plant_record.net_cost / 100;
   // Calculating the purchase tax
   plant_record.purchase_tax = plant_record.net_cost * tax_rate / 100;
   // Calculating total cost of purchase
   plant_record.total_cost = plant_record.net_cost + plant_record.purchase_tax - plant_record.discount;
}

//Here is your driver to test the program
int main() {
   order_record purchase_record;
   string pname, cname;
   double cost;
   int quantity;
  
   ifstream in;   //declaring an input file stream
   in.open("nursery_stock.txt");   //opening the input file stream
   if(!in.is_open()) {
       cout << "Input file did not open correctly" << endl;
   }
   else {
       //the following while loop processes one order record at a time
       while(!in.eof()) {
           input(in, purchase_record);
           process(purchase_record);
           output(purchase_record);
       }
   }
  
   in.close();   //always close opened files.
  
   return 0;
}
