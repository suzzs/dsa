/*
What is a Queue?
A queue is a linear data structure that follows the FIFO (First In, First Out) principle, meaning that the element that is added first will be removed first.

Key Characteristics of a Queue:
Front and Rear:
Front: Points to the first element (the one to be dequeued next).
Rear: Points to the last element (the most recently enqueued).

Operations:
Enqueue: Add an element at the rear of the queue.
Dequeue: Remove an element from the front of the queue.

Use Cases:
Task scheduling (e.g., CPU scheduling).
Handling requests in real-time systems (e.g., printer queue).
Breadth-First Search (BFS) in graphs and trees.

Queue Representation:
Initial state (empty queue): front = -1, rear = -1.

After enqueue of 10, 20, 30:
Queue: [10, 20, 30], front = 0, rear = 2.

After dequeue:
Queue: [20, 30], front = 1.


STACK!!!
A stack is a linear data structure that follows the LIFO (Last In, First Out) principle, meaning that the element added most recently is the one removed first.

Key Characteristics of a Stack:

Single Pointer:
top: Points to the last added element.

Operations:
Push: Add an element to the top of the stack.
Pop: Remove the top element from the stack.

Use Cases:
Function call management in programming.
Undo operations in text editors.
Expression evaluation and conversion (e.g., infix to postfix).

Stack Representation:
Initial state (empty stack): top = -1.

After push of 10, 20, 30:
Stack: [10, 20, 30], top = 2.

After pop:
Stack: [10, 20], top = 1.

*/


/*
Linear Queue
A linear queue is a data structure that follows the FIFO (First In, First Out) principle:
The element that is added first is removed first.

It is implemented using:
Arrays:
The queue has a fixed size.
The front pointer indicates the position of the first element.
The rear pointer indicates the position where the next element will be inserted.

Linked Lists:
The queue can grow dynamically, unlike arrays.

Characteristics of Linear Queue:
Front and Rear:
front: Points to the first element of the queue.
rear: Points to the last element of the queue.

Insertion (Enqueue):
Elements are added at the rear.

Deletion (Dequeue):
Elements are removed from the front.

Limitations:
When implemented using arrays, space is wasted after multiple enqueue and dequeue operations because the front pointer keeps moving forward but cannot wrap around.
Example:
Suppose the queue size is 5, and it starts empty:

Initially: front = -1, rear = -1, Queue: [].
Enqueue 10:
rear = 0, front = 0, Queue: [10].
Enqueue 20:
rear = 1, Queue: [10, 20].
Dequeue:
front = 1, Queue: [20]. (The 10 is logically removed.)
In a linear queue implemented with arrays, after the dequeue, the memory used by 10 is not reused, leading to inefficiency. Circular queues solve this issue.


*/







#include <iostream>
using namespace std;

#define SIZE 5 // Maximum size of the queue

class LinearQueue {
private:
    int queue[SIZE];
    int front, rear;

public:
    // Constructor to initialize front and rear
    LinearQueue() {
        front = 0;
        rear = -1;
    }

    // Function to check if the queue is full
    bool isFull() {
        return rear == SIZE - 1;
    }

    // Function to check if the queue is empty
    bool isEmpty() {
        return front > rear;
    }

    // Function to enqueue (add) an element to the queue
    void enqueue(int element) {
        if (isFull()) {
            cout << "Queue Overflow! Cannot add " << element << "." << endl;
            return;
        }
        rear++;
        queue[rear] = element;
        cout << "Enqueued: " << element << endl;
    }

    // Function to dequeue (remove) an element from the queue
    void dequeue() {
        if (isEmpty()) {
            cout << "Queue Underflow! Cannot remove any element." << endl;
            return;
        }
        cout << "Dequeued: " << queue[front] << endl;
        front++;
    }

    // Function to display the current elements of the queue
    void display() {
        if (isEmpty()) {
            cout << "Queue is empty!" << endl;
            return;
        }
        cout << "Queue elements: ";
        for (int i = front; i <= rear; i++) {
            cout << queue[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    LinearQueue q;
    int choice, element;

    do {
        cout << "\n--- Linear Queue Operations ---" << endl;
        cout << "1. Enqueue\n2. Dequeue\n3. Display\n4. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter the element to enqueue: ";
            cin >> element;
            q.enqueue(element);
            break;

        case 2:
            q.dequeue();
            break;

        case 3:
            q.display();
            break;

        case 4:
            cout << "Exiting program." << endl;
            break;

        default:
            cout << "Invalid choice! Please try again." << endl;
        }
    } while (choice != 4);

    return 0;
}

















