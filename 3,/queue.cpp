#include <iostream>
using namespace std;

#define SIZE 5   // Fixed size of the circular queue

class CircularQueue {
private:
    int items[SIZE];
    int front, rear;

public:
    CircularQueue() {
        front = -1;
        rear = -1;
    }

    // Check if the queue is full
    bool isFull() {
        return (front == 0 && rear == SIZE - 1) || (rear + 1 == front);
    }

    // Check if the queue is empty
    bool isEmpty() {
        return (front == -1);
    }

    // Insertion (Enqueue)
    void enqueue(int value) {
        if (isFull()) {
            cout << "\nQueue is Full! Cannot insert " << value << ".\n";
            return;
        }

        if (front == -1)
            front = 0; // first element
        rear = (rear + 1) % SIZE;
        items[rear] = value;

        cout << value << " inserted into the queue.\n";
    }

    // Deletion (Dequeue)
    void dequeue() {
        if (isEmpty()) {
            cout << "\nQueue is Empty! Cannot dequeue.\n";
            return;
        }

        cout << items[front] << " deleted from the queue.\n";

        if (front == rear) {
            // Queue becomes empty after deletion
            front = rear = -1;
        } else {
            front = (front + 1) % SIZE;
        }
    }

    // Display the elements
    void display() {
        if (isEmpty()) {
            cout << "\nQueue is Empty!\n";
            return;
        }

        cout << "\nQueue elements are: ";
        int i = front;
        while (true) {
            cout << items[i] << " ";
            if (i == rear)
                break;
            i = (i + 1) % SIZE;
        }
        cout << endl;
    }
};

// ---------------- MAIN FUNCTION ----------------
int main() {
    CircularQueue q;
    int choice, value;

    do {
        cout << "\n--- CIRCULAR QUEUE MENU ---\n";
        cout << "1. Enqueue (Insert)\n";
        cout << "2. Dequeue (Delete)\n";
        cout << "3. Display\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter value to insert: ";
            cin >> value;
            q.enqueue(value);
            break;

        case 2:
            q.dequeue();
            break;

        case 3:
            q.display();
            break;

        case 4:
            cout << "\nExiting program...\n";
            break;

        default:
            cout << "\nInvalid choice! Try again.\n";
        }

    } while (choice != 4);

    return 0;
}
