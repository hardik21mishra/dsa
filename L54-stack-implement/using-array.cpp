
// Implementation of stack using array

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Mystack{
    private:
        int *arr;
        int size;
        int top;
    public:
        Mystack(int size){
            this -> size = size;
            arr = new int[size];
            top = -1;
            }
        bool isEmpty() {return top == -1;}
        bool isFull() {return top == size - 1;}
        
        void push(int val){
            if (isFull()) throw runtime_error("Stack Overflow");
            
            else{
                arr[++top] = val;
            }
        }
        
        void pop(){
            if(isEmpty()) throw runtime_error("Stack Underflow");
            else{
                arr[top--];
            }
        }
        
        void peek(){
            if(isEmpty()) throw runtime_error("Stack Underflow");
            else{
                cout << arr[top] << endl;
            }
        }
        
        void getSize(){ cout << top + 1 << endl;}
        
        void printStack(){
            if(isEmpty()) throw runtime_error("Stack Underflow");
            
            else{
                for(int i = 0 ; i <= top ; i++){
                    cout << arr[i] << " ";
                }
                cout<<endl;
            }
        }
    
};
int main() {
    Mystack st(5);
    st.push(11);
    st.push(12);
    st.push(13);
    st.push(14);
    st.push(15);
    
    st.printStack();
    
    st.pop();
    
    st.printStack();
    
    st.peek();
    
    cout << "size is:";
    st.getSize();
    
    return 0;
}