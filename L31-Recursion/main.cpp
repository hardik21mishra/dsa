// factorial of a number

// Recursive relation   :  F(n) = 2 * F(n-1)
//                         factorial(n) = n * factorial(n-1)    

#include<iostream>
using namespace std;

int factorial(int a){
    if (a == 0)
        return 1;

    int sp = factorial(a-1);
    int bp = a * sp; 

    return bp;
}

int main(){
    int n, m; 
    cout<<"Enter number: "<<endl;
    cin>>n;
    m = factorial(n);
    cout<<m;
    return 0;
}