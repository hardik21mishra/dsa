// previous problem is resolved here by using circular queue logic

// previous problem happens because the queue does not reuse the 
// space created by popping elements, this is not how a queue is 
// normally designed to function. A queue should allow the reuse 
// of space once elements are popped, provided there is enough capacity

// Solution: Use a Circular Queue

#include <bits/stdc++.h>
using namespace std;

class Queue {
    int *arr;
    int front;
    int rear;
    int size;
    int count; // To track the number of elements in the queue

public:
    Queue(int val) {
        this->size = val;
        arr = new int[size];
        front = 0;
        rear = 0;
        count = 0;
    }

    void push(int data) {
        if (count == size) { // Check if the queue is full
            cout << "Queue is full" << endl;
            return;
        }
        arr[rear] = data;
        rear = (rear + 1) % size; // Circular increment
        count++;
    }

    int pop() {
        if (count == 0) { // Check if the queue is empty
            cout << "Queue is empty" << endl;
            return -1;
        }
        int result = arr[front];
        arr[front] = -1; // Optional: For debugging purposes
        front = (front + 1) % size; // Circular increment
        count--;
        return result;
    }

    void display() {
        if (count == 0) {
            cout << "Queue is empty" << endl;
            return;
        }
        int i = front;
        for (int k = 0; k < count; k++) {
            cout << arr[i] << " ";
            i = (i + 1) % size; // Circular increment
        }
        cout << endl;
    }
};

int main() {
    Queue q(5);

    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    q.push(5);

    q.display();

    q.pop();
    q.display();

    q.push(7);
    q.display();

    return 0;
}


