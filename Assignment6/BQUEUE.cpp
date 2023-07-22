//Include the required header files.

#include "BQUEUE.h"
#include <iostream>

//Use the standard namespace.

using namespace std;

//Define the default constructor.

BQUEUE::BQUEUE()

{

    //Initialize the front

    //pointer with NULL value.

   front = NULL;

}

//Define the Print() function.

void BQUEUE::Print()

{

    //If the queue is empty then,

    //print an error message.

    if (front == NULL)

    {

        cout << "Error in Printing: The queue"

        <<" is empty.\n";

    }

    //Otherwise,print the

    //elements of the queue.

    else

    {

        bqnode *curr = front;

        do

        {

            cout << curr->time << endl;

            curr = curr->next;

        }while (curr != front);

    }

}

//Define the Enqueue() function.

void BQUEUE::Enqueue(int data)

{

    //Display an informative message.

    cout<<"Inserting "<<data

    <<" into the queue.\n";

    //Create a new node.

    bqnode * temp = new bqnode();

    temp->time = data;

    //If the queue is empty then,

    //insert the element at the front.

    if (front == NULL)

    {

        front = temp;

        front->next = front;

        front->prev = front;

    }

    //Otherwise, insert the element

    //at the end of the queue.

    else

    {

        bqnode * curr = front->prev;

        temp->prev = curr;

        curr->next = temp;

        temp->next = front;

        front->prev = temp;        

    }

}

//Define the Deque() function.

void BQUEUE::Dequeue()

{

    //If the queue is empty then,

    //display an error message.

    if (front == NULL)

    {

        cout<<"Error in Dequeue: The queue"

        <<" is empty.\n";

    }

    //Otherwise, if there is only one

    //element in the queue then,

    //delete the element and set the

    //front pointer to NULL.

    else if (front->next == front)

    {

        cout<<"Deleted "<<front->time

        <<" from the queue.\n";

        delete front;

        front = NULL;

       

    }

    //Otherwise, delete the element

    //at the front of the queue.

    else

    {

            bqnode *temp = front;

            front->prev->next = temp->next;

            front->next->prev = temp->prev;

            front = front ->next;

            cout<<"Deleted "<<temp->time

            <<" from the queue.\n";

            delete temp;

    }

   

}

//Define the copy constructor.

BQUEUE::BQUEUE(const BQUEUE &obj)

{

    //Set the front pointer to NULL.

    this->front = NULL;

    bqnode *temp = obj.front;

    //Traverse the queue to be copied

    //and insert its elements into

    //the current queue.

    do

    {

        this->Enqueue(temp->time);

        temp = temp->next;

       

    }while (temp != obj.front);

}

//Define the destructor.

BQUEUE::~BQUEUE()

{

    //Check if the Queue

    //is empty or not.

    if (front != NULL)

    {

        //Run the loop to deallocate the

        //memory that has been assignned

        //to the elements of the queue.

        //the elements.

        while(true)

        {

            //If only 1 element is remaining

            //in the queue then,

            //deallocate the memory, and

            //break out of the loop.

            if(front->next == front)

            {

              //Delete the front element

                //from the queue

                delete front;

               

                //Set the front pointer to NULL.

                front = NULL;

                break;

            }

            //Deallocate the memory allocated

            //to the current element and move

            //on to the next element.

            bqnode *curr = front->next;

            curr->next->prev = front;

            front->next = curr->next;

            delete curr;

        }

    }

}