#include<iostream>
#include<string>
#include <iomanip>
#include <fstream>
#include <stdlib.h>

using namespace std;

class order_record
{
public:
   string pname;
   string cname;
   double plant_cost;
   double quantity;
   double net_cost;
   double discount;
   double total_cost;

   //to holds records tax and total cost
   double purchase_tax;
   double tax_rate;
};

void input(ifstream&, order_record&);
void output(const order_record&);
void process(order_record&);

//implementation of input function here
/*this function accepts two parameters
one fot file address to open it
and second to access order_records
*/
void input(ifstream& in, order_record& plant_recod)
{
   //reading each data field from order_record
   //reading data words(pname, cname..) for each record

   string word;
   //array to store records and then passing them to records class
   string* records = new string[4];
   int count = 0;
   //getting records until end of file
   while (in >> word)
   {
       if (count == 4)
       {
           //strong records fields
           plant_recod.pname = records[0];
           plant_recod.cname = records[1];
           plant_recod.plant_cost = atof(records[2].c_str());
           plant_recod.quantity = atof(records[3].c_str());

           //calling process function to calculate cost, tax...
           process(plant_recod);
           count = 0;

       }
       records[count] = word;
       count++;
   }

}

void process(order_record& plant_record)
{

   //calculatng tax rate of total
   //based on county name
   if (plant_record.cname.compare("dade") == 0)
   {
       //tax rate for broward is 6.5%
       plant_record.tax_rate = plant_record.plant_cost / (1 + 6.5);
   }
   else if (plant_record.cname.compare("broward") == 0)
   {
       //tax rate for broward is 6%
       plant_record.tax_rate = plant_record.plant_cost / (1 + 6);
   }
   //if count is not dady neither broward then calcultae for plam
   else
   {
       //tax rate for palm is 7%
       plant_record.tax_rate = plant_record.plant_cost / (1 + 7);
   }

   //calculating discounts
   if (plant_record.quantity == 0)
       plant_record.discount = 0;
   else if (plant_record.quantity >= 1 && plant_record.quantity <= 5)
       plant_record.discount = 1;//1% discount
   else if (plant_record.quantity >= 6 && plant_record.quantity <= 11)
       plant_record.discount = 3;//3% discount
   else if (plant_record.quantity >= 12 && plant_record.quantity <= 20)
       plant_record.discount = 5;//5% discount
   else if (plant_record.quantity >= 21 && plant_record.quantity <= 50)
       plant_record.discount = 8;//8% discount
   else if (plant_record.quantity > 50)
       plant_record.discount = 12;//12% discount

   //net cost
   plant_record.net_cost = plant_record.quantity*plant_record.plant_cost;

   //calculating tax on purchase
   plant_record.purchase_tax = (plant_record.net_cost*plant_record.tax_rate);

   //calculating total cost of purchase
   plant_record.total_cost = plant_record.net_cost + (plant_record.purchase_tax - plant_record.discount);

   //calling output to show outputs
   output(plant_record);

}

//function to show outputs//
void output(const order_record& plant_record)
{
   //setting output precision
   cout.precision(2);
   cout.setf(ios::fixed);

   //print records in given formate
   cout << plant_record.pname << "\t" << plant_record.cname << "\t" << plant_record.plant_cost
       << "\t" << plant_record.quantity << "\t" << plant_record.net_cost << "\t" << plant_record.discount
       << "\t" << plant_record.purchase_tax << "\t" << plant_record.total_cost << endl;

}

//main driver function
int main()
{
   //order_record class object
   order_record purchase_record;

   //opening nursery file t read its records
   ifstream in;
   in.open("nursery_stock.txt");
   if (in.fail())
       cout << "\nError! File Opening.";
   else
   {
       //calling input function to read records
       input(in, purchase_record);
   }
}
