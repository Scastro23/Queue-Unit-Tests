#include <iostream>
#include "Queue.h"

int main() {
    Queue<int> q(5); // Queue object with capacity of 5

    // Enqueue numbers 1 through 5 into the queue
    std::cout << "Enqueue: ";
    for (int i = 1; i <= 5; ++i) {
        q.enqueue(i);
        std::cout << i << " ";
    }
    std::cout << std::endl;

    // Dequeue elements from the queue and print
    std::cout << "Dequeue: ";
    while (!q.isEmpty()) {
        std::cout << q.dequeue() << " ";
    }
    std::cout << std::endl;

    return 0;
}