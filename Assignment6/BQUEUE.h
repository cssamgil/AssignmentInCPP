#include <iostream>
#include <fstream>
#include <string>

using namespace std;

#ifndef BQUEUE_h

#define BQUEUE_h

//Define the class bqnode.

class bqnode

{

    //Declare the required

    //public members.

    public:

        int time;

        bqnode *prev, *next;

};

//Define the class BQUEUE.

class BQUEUE

{

    //Declare the required

    //public members.

    public:

        //Declare the default constructor.

        BQUEUE();

        //Declare the destructor.

        ~BQUEUE();

        //Declare the copy constructor.

        BQUEUE(const BQUEUE &);

       

        //Declare the Enqueue() function.

        void Enqueue(int);

        //Declare the Dequeue() function.

        void Dequeue();

        //Declare the Print() function.

        void Print();

    //Declare the required

    // private members.

    private:

        bqnode *front;//use ONLY one pointer

};

//End the definition of

//the header file.

#endif