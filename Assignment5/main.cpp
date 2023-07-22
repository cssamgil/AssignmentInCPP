#include "stack.h"

#include <iostream>

#include <string>

#include <vector>

using namespace std;

int main()

{

     int err;

     linkedStack stk;

     string post, inf, oper1, oper2, exprsn, choice;

     do

     {

          // Read postfix expression

          cout << "Postfix exp: " << endl;

          getline(cin, post);

          err = 0;

          for(int di = 0; di < post.length(); di++)

          {

              string cha = post.substr(di, 1);

              if (cha == "+" || cha == "-" || cha == "*" || cha == "/")

              {

                   oper2 = stk.pop();

                   if (oper2 == "\0")

                   {

                        cout << "Too many operators and not enough operands" << endl;

                        err = 1;

                        break;

                   }

                   oper1 = stk.pop();

                   if (oper1 == "\0")

                   {

                        cout << "Too many operators and not enough operands" << endl;

                        err = 1;

                        break;

                   }

                   exprsn = "(" + oper1 + " " + cha + " " + oper2 + ")";

                   stk.push(exprsn);

              }

              else if (cha == " ")

              {

                   continue;

              }

              else

              {

                   stk.push(cha);

              }

          }

          if (!err)

          {

              inf = stk.pop();

              if (stk.pop() == "\0")

              {

                   cout << "The infix expression is" << endl << inf << endl;

              }

              // If stack not empty

              else

              {

                   cout << "Too many operands and not enough operators" << endl;

                   while(stk.pop() != "\0");

              }

          }

          cout << "Want to continue y/n : ";

          cin >> choice;

          getchar();

          cout<< endl;

     }

     while(choice == "y" || choice == "Y");

     system("pause");

     return 0;

}