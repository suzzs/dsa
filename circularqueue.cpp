#include<iostream>
using namespace std;
class queue{
    public:
    int size=5;
    int rear=-1; int front=0;
    bool isFull(queue[5], int &rear,int front){
        if((rear+1)%size==front){
            cout<<"Queue overflow"<<endl;
            return 0;
        }
        else{
            rear+=(rear+1)%size;
            int element;
            int queue[rear]=element;
            cout<<element<<"is enqueued"<<endl;
        }
    }
};
int main(){
    queue q;
    q.isFull(10,1,0);
    return 0;
}





























/*
#include <iostream>
using namespace std;

class CircularQueue {
private:
    int size;
    int *queue;
    int front, rear;

public:
    // Constructor to initialize the queue
    CircularQueue(int s) {
        size = s;
        queue = new int[size];
        front = -1;
        rear = -1;
    }

    // Function to check if the queue is full
    bool isFull() {
        return (front == (rear + 1) % size);
    }

    // Function to check if the queue is empty
    bool isEmpty() {
        return (front == -1);
    }

    // Function to enqueue (add) an element
    void enqueue(int element) {
        if (isFull()) {
            cout << "Queue Overflow! Cannot enqueue " << element << "." << endl;
            return;
        }
        if (isEmpty()) {
            front = 0;
        }
        rear = (rear + 1) % size;
        queue[rear] = element;
        cout << element << " enqueued to the queue." << endl;
    }

    // Function to dequeue (remove) an element
    void dequeue() {
        if (isEmpty()) {
            cout << "Queue Underflow! Cannot dequeue any element." << endl;
            return;
        }
        cout << queue[front] << " dequeued from the queue." << endl;
        if (front == rear) {
            // Queue becomes empty
            front = -1;
            rear = -1;
        } else {
            front = (front + 1) % size;
        }
    }

    // Function to display the queue elements
    void display() {
        if (isEmpty()) {
            cout << "Queue is empty!" << endl;
            return;
        }
        cout << "Queue elements: ";
        int i = front;
        while (true) {
            cout << queue[i] << " ";
            if (i == rear) break;
            i = (i + 1) % size;
        }
        cout << endl;
    }
};

int main() {
    CircularQueue q(5); // Circular queue of size 5
    int choice, element;

    do {
        cout << "\n--- Circular Queue Operations ---" << endl;
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
*/