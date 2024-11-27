// Implementing a queue using array


// problems: if we push n elements in n sized queue, and then if we pop an element, 
//           technically there should be created a space to push another element ,
//           but that's not happening here, its showing queue is full
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

    q.pop();
    q.display();
    q.push(7);

    return 0;
}