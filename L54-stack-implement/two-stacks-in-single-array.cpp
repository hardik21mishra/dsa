#include <iostream>
using namespace std;

class TwoStacks
{
private:
    int size;
    int top1;
    int top2;
    int *arr;

public:
    TwoStacks(int size)
    {
        this->size = size;
        top1 = -1;
        top2 = size;
        arr = new int[size];
    }

    ~TwoStacks()
    {
        delete[] arr;
    }

    void push1(int value)
    {
        if (top1 + 1 == top2)
            throw runtime_error("Stack 1 Overflow");
        else
        {
            arr[++top1] = value;
        }
    }

    void push2(int value)
    {
        if (top2 - 1 == top1)
            throw runtime_error("Stack 2 Overflow");
        else
        {
            arr[--top2] = value;
        }
    }

    void pop1()
    {
        if (top1 == -1)
            throw runtime_error("Stack Underflow");
        else
            arr[top1--];
    }

    void pop2()
    {
        if (top2 == size)
            throw runtime_error("Stack Underflow");
        else
            arr[top2++];
    }

    void peek1()
    {
        if (top1 == -1)
            throw runtime_error("Stack Underflow");
        else
            cout << arr[top1] << endl;
    }

    void peek2()
    {
        if (top2 == size)
            throw runtime_error("Stack Underflow");
        else
            cout << arr[top2] << endl;
    }

    void printStack1()
    {
        if (top1 == -1)
            throw runtime_error("Stack Underflow");
        else
        {
            cout << "Stack 1 elements are : ";
            for (int i = 0; i <= top1; ++i)
            {
                cout << arr[i] << " ";
            }
            cout << endl;
        }
    }

    void printStack2()
    {
        if (top2 == size)
            throw runtime_error("Stack Underflow");
        else
        {
            cout << "Stack 2 elements are : ";
            for (int i = size - 1; i >= top2; --i)
            {
                cout << arr[i] << " ";
            }
            cout << endl;
        }
    }
};

int main()
{
    TwoStacks st(5);

    st.push1(11);
    st.push1(12);
    st.push1(13);

    st.push2(14);
    st.push2(15);

    st.printStack1();
    st.printStack2();

    st.pop1();
    st.printStack1();

    st.pop2();
    st.printStack2();

    st.peek1();
    st.peek2();

    return 0;
}