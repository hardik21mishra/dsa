// Implementation of queue using linked list

#include <bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node* next;

    public:
        Node(int val) : data(val), next(NULL) {}
};

class Queue{
    Node* front;
    Node* rear;

    public:
        Queue() : front(NULL), rear(NULL) {}

        void push(int x){
            Node* newNode = new Node(x);
            if(!rear) front = rear = newNode;
            else{
                rear -> next = newNode;
                rear = newNode;
            }
        }

        void pop(){
            if(!front){
                cout << "Queue Underflow, can't pop" << endl;
                return;
            }
            Node* temp = front;
            front = front -> next;

            if(!front) rear = NULL;

            delete temp;
        }

        void peek(){
            if(!front){
                cout << "Queue is empty" << endl;
                return;
            }
            cout << front -> data << endl;
        }

        bool isEmpty(){
            return front == NULL;
        }

        void display(){
            if(!front){
                cout << "Queue is empty "<<endl;
                return;
            }
            Node* temp = front;
            while(temp){
                cout << temp -> data << " ";
                temp = temp -> next;
            }
            cout << endl;
        }
};

int main(){
    Queue q;

    q.push(11);
    q.push(12);
    q.push(13);
    q.push(14);
    q.push(15);

    q.display();

    q.pop();

    q.display();

    q.peek();
    cout << (q.isEmpty() ? "Queue is Empty" : "Not empty");
    return 0;
}