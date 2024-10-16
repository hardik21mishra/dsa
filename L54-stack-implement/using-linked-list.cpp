#include <iostream>
#include <stdexcept>
using namespace std;

struct Node{
    int data;
    Node* next;

    Node(int value) : data(value), next(NULL) {}; // constructor
};

class Stack{
    private:
        Node* top;
        int StackSize;
    public:
        Stack() : top(NULL), StackSize(0) {}; // constructor
        

        bool isEmpty() const {
            return top == NULL;
        }

        void push(int val){
            Node* newNode = new Node(val);
            newNode -> next = top;
            top = newNode;
            StackSize++;
        }

        void pop(){
            if(isEmpty()) throw runtime_error("stack is empty!!!");
            
            else{
                Node* temp = top;
                top = top -> next;
                delete temp;
                StackSize--;
            }
        }

        int peek() const{
            if (isEmpty()) throw runtime_error("Stack is Empty!!!");
            
            else return top -> data;
        }

        void print() const{
            Node* curr = top;
            cout<<"stack fron top to bottom"<<endl;
            while(curr){
                cout << curr -> data<<" ";
                curr = curr -> next;
            }
            cout<<endl;
        }

        void GetSize(){
            cout << StackSize;
        }
};

int main(){
    Stack st;
    st.push(11);
    st.push(12);
    st.push(13);
    st.push(14);
    st.push(15);

    st.print();

    st.pop();
    st.pop();

    st.print();

    st.pop();

    cout << st.peek() << endl;

    st.GetSize();
    return 0;
}