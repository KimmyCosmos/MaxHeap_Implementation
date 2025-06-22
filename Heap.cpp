#include "Heap.h"
#include <iostream>

Heap::Heap() : numItems(0) {
    for (int i = 0; i < MAX_HEAP_SIZE; ++i) {
        heap[i] = nullptr;
    }
}

void Heap::enqueue(PrintJob* job) {
    if (numItems >= MAX_HEAP_SIZE) {
        return; // Heap is full
    }

    heap[numItems] = job;
    int child = numItems;
    int parent = (child - 1) / 2;

    // Bubble up to maintain heap order
    while (child > 0 && heap[child]->getPriority() > heap[parent]->getPriority()) {
        std::swap(heap[child], heap[parent]);
        child = parent;
        parent = (child - 1) / 2;
    }

    ++numItems;
}

void Heap::dequeue() {
    if (numItems == 0) {
        return;
    }

    delete heap[0]; // Remove the root
    heap[0] = heap[numItems - 1];
    heap[numItems - 1] = nullptr;
    --numItems;

    // Trickle the root down
    int index = 0;
    bool done = false;

    while (!done) {
        int left = 2 * index + 1;
        int right = 2 * index + 2;
        int largest = index;

        if (left < numItems && heap[left]->getPriority() > heap[largest]->getPriority()) {
            largest = left;
        }

        if (right < numItems && heap[right]->getPriority() > heap[largest]->getPriority()) {
            largest = right;
        }

        if (largest != index) {
            std::swap(heap[index], heap[largest]);
            index = largest;
        } else {
            done = true;
        }
    }
}

PrintJob* Heap::highest() {
    if (numItems == 0) {
        return nullptr;
    }
    return heap[0];
}

void Heap::print() const {
    if (numItems == 0) {
        return;
    }

    const PrintJob* job = heap[0];
    std::cout << "Priority: " << job->getPriority()
              << ", Job Number: " << job->getJobNumber()
              << ", Number of Pages: " << job->getPages() << std::endl;
}
