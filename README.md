# Max Heap Implementation (C++)

This project implements a max heap (priority queue) using a fixed-size array of pointers in C++. The heap manages `PrintJob` objects that contain priority, job number, and page count. It supports enqueueing new jobs, dequeueing the highest-priority job, retrieving the highest-priority job without removal, and printing job details. The program uses a simple menu for interaction.

This project was completed as part of a data structures and algorithms course.

## Technologies
- C++
- Standard Template Library (STL)

## Key concepts
- Max heap / priority queue
- Array-based heap implementation
- Pointer-based object management
- Exception-safe memory handling
- Menu-driven program design

## How to compile and run

### Compile
```
g++ main.cpp Heap.cpp PrintJob.cpp -o max_heap_program
```

### Run
```
./max_heap_program
```

The program presents a menu to enqueue jobs, print the highest-priority job, dequeue the highest-priority job, or quit.

## What I learned
- Building a max heap from scratch using a fixed-size array
- Managing dynamic memory and object lifecycles with pointers
- Implementing heap bubble-up and trickle-down operations
- Designing user-friendly menu interfaces for data structure testing
