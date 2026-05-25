#include <iostream>
using namespace std;

class CircularQueue {
    int *arr;
    int front;
    int rear;
    int size;

public:
    CircularQueue(int s) {
        size = s;
        arr = new int[size];
        front = -1;
        rear = -1;
    }

    // Enqueue Operation
    void enqueue(int value) {

        // Check if queue is full
        if ((rear + 1) % size == front) {
            cout << "Queue is Full!" << endl;
            return;
        }

        // First insertion
        if (front == -1) {
            front = rear = 0;
        }
        else {
            rear = (rear + 1) % size;
        }

        arr[rear] = value;

        cout << value << " inserted successfully." << endl;
    }

    // Dequeue Operation
    void dequeue() {

        // Check if queue is empty
        if (front == -1) {
            cout << "Queue is Empty!" << endl;
            return;
        }

        cout << arr[front] << " deleted successfully." << endl;

        // If only one element exists
        if (front == rear) {
            front = rear = -1;
        }
        else {
            front = (front + 1) % size;
        }
    }

    // Display Queue
    void display() {

        if (front == -1) {
            cout << "Queue is Empty!" << endl;
            return;
        }

        cout << "Queue Elements: ";

        int i = front;

        while (i != rear) {
            cout << arr[i] << " ";
            i = (i + 1) % size;
        }

        cout << arr[rear] << endl;
    }

    // Destructor
    ~CircularQueue() {
        delete[] arr;
    }
};

int main() {

    CircularQueue q(5);

    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.enqueue(40);

    q.display();

    q.dequeue();
    q.dequeue();

    q.display();

    q.enqueue(50);
    q.enqueue(60);

    q.display();

    return 0;
}