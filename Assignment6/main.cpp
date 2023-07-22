#include <iostream>
#include <fstream>
#include <string>
#include<iostream>
#include "BQUEUE.h"

using namespace std;
int main( )

{

BQUEUE k;

k.Enqueue(60);

k.Print();

k.Enqueue(20);

k.Enqueue(30);

k.Print();

k.Enqueue(10);

k.Print();

k.Enqueue(50);

k.Enqueue(40);

k.Print();

BQUEUE j = k;

j.Dequeue();

j.Print();

j.Dequeue();

j.Dequeue();

j.Dequeue();

j.Print();

j.Dequeue();

j.Dequeue();

j.Print();

j.Dequeue();

j.Dequeue();

return 0;

}