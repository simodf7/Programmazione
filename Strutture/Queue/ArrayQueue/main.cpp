#include "AQueue.h"
#include <iostream>

int main(){


    ArrayQueue<int> q;
    q.enqueue(2);
    q.enqueue(45);
    q.enqueue(8);
    std::cout << "Q front is " << q.front() << "\n";
    q.dequeue();
    std::cout << "Q front is " << q.front() << "\n";
    q.dequeue();
    std::cout << "Q front is " << q.front() << "\n";
    q.dequeue();



}