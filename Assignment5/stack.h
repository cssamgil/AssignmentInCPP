#ifndef STACK_H

#define STACK_H

#include <string>

using namespace std;

// Structure stack node

struct stackNode

{

     string value;

     struct stackNode *link;

};

// Linked stack

class linkedStack

{

     struct stackNode *top;

     public:

     linkedStack()

     {

          top = 0;

     }

     // Member functions

     void push(string value);

     string pop();

};
#endif