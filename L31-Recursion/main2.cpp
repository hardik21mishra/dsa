// 2 power n 

// Recursive relation   :    F(n) = 2 * F(n-1)

                        //   power(n) = 2 * power(n-1)

#include<iostream>
using namespace std;

int power(int a){
    if(a == 0)
        return 1;

    int sp = power(a-1);
    int bp = 2 * sp;
    
    return bp;
}
int main(){
    int n;
    cout<<"enter the power of 2: ";
    cin>>n;
    cout<<endl;
    power(n);
    cout<<power(n);
    return 0;
}