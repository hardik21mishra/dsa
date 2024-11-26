// Implementing a queue using array
#include <bits/stdc++.h>
using namespace std;

class   Queue{
    int *arr;
    int front;
    int rear;
    int size;

    public:
            Queue(int val){
            this -> size = val;
            arr = new int[size];
            front  = 0;
            rear = 0;
        }

        void push(int data){
            if(rear == size){
                cout << "Queue is full" << endl;
                return;
            }
            arr[rear] = data;
            rear++;
        }

        int pop(){
            if(front == rear){
                cout << "queue is empty" << endl;
                return -1;
            }
            int result = arr[front];
            arr[front] = -1;
            front++;
            if(front == rear){
                front = 0;
                rear = 0;
            }
            return result;
        }

        void display(){
            if(front == rear){
                cout << "queue is empty" << endl;
                return;
            }
            for(int i = front ; i < rear ; i++){
                cout << arr[i] << " ";
            }
            cout << endl;
        }
};

int main(){
    Queue q(5);

    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    q.push(5);

    q.display();


    return 0;
}