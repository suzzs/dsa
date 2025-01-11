#include <iostream>
using namespace std;

struct Node {
    int data;            
    Node* next;          

    Node(int value) {    // Constructor to initialize a new node
        data = value;
        next = nullptr;  
    }
};

class LinkedList {
private:
    Node* head; 

public:
    LinkedList() : head(nullptr) {} // Constructor to initialize an empty list

    
    void addAtEnd(int val) {
        Node* node = new Node(val); 

        if (head == nullptr) {      
            head = node;            // Set the new node as the head
        } else {
            Node* temp = head;      // Start from the head
            while (temp->next != nullptr) { // Traverse to the last node
                temp = temp->next;
            }
            temp->next = node;      // Link the last node to the new node
        }
    }

    
    void display() {
        if (head == nullptr) {       
            cout << "List is empty.\n";
            return;
        }

        Node* temp = head;           
        while (temp != nullptr) {    // Traverse the list
            cout << temp->data << " -> "; // Print each node's data
            temp = temp->next;
        }
        cout << "NULL\n";         // Indicate the end of the list
    }

    
    void addAtBeginning(int val) {
        Node* node = new Node(val); // Create a new node with the given value
        node->next = head;          // Point the new node to the current head
        head = node;                // Update the head to the new node
    }

    // Function to insert a node after a specific value
    void addAfter(int target, int val) {
        Node* temp = head;          // Start from the head

        while (temp != nullptr && temp->data != target) { // Find the target node
            temp = temp->next;
        }

        if (temp == nullptr) {
            cout << "Target node not found.\n";
            return;
        }

        Node* node = new Node(val); // Create a new node
        node->next = temp->next;    // Link the new node to the next node
        temp->next = node;          // Link the target node to the new node
    }

    
    void deleteFromBeginning() {
        if (head == nullptr) {       
            cout << "List is empty, nothing to delete.\n";
            return;
        }

        Node* temp = head;           // Store the current head
        head = head->next;           // Update the head to the next node
        delete temp;                 // Delete the old head node
    }

    
    void deleteFromEnd() {
        if (head == nullptr) {       // If the list is empty
            cout << "List is empty, nothing to delete.\n";
            return;
        }

        if (head->next == nullptr) { // If there's only one node
            delete head;
            head = nullptr;
            return;
        }

        Node* temp = head;           // Start from the head
        while (temp->next->next != nullptr) { // Find the second-to-last node
            temp = temp->next;
        }

        delete temp->next;           // Delete the last node
        temp->next = nullptr;        // Set the new last node's next to null
    }

    // Function to delete a node after a specific value
    void deleteAfter(int target) {
        Node* temp = head;           // Start from the head

        while (temp != nullptr && temp->data != target) { // Find the target node
            temp = temp->next;
        }

        if (temp == nullptr || temp->next == nullptr) { // If target node or next node doesn't exist
            cout << "No node found to delete after the target.\n";
            return;
        }

        Node* toDelete = temp->next; // Node to be deleted
        temp->next = toDelete->next; // Update the link
        delete toDelete;             // Delete the node
    }
};

int main() {
    LinkedList list; 

    
    list.addAtEnd(10); 
    list.addAtEnd(20); 
    list.addAtEnd(30); 

    
    list.display(); 

    
    list.addAtBeginning(5);
    list.display(); 

    
    list.addAfter(20, 25);
    list.display(); 

    
    list.deleteFromBeginning();
    list.display(); 

    
    list.deleteFromEnd();
    list.display(); 

    
    list.deleteAfter(20);
    list.display(); 

    return 0;
}
