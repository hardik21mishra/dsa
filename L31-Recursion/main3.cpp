// to print n counts : 1 2 3 4 5 6 7 8 9................n

// Recursive relation   :   F(n) = 2 * F(n-1)
//                          print(n) = n  print(n-1)

#include<iostream>
using namespace std;

void print(int a){
    if (a == 0)
        return;

    print(a-1);
    cout<<a<<endl;
}
int main(){
    int n,m;
    cout<<"Enter no. : ";
    cin>>n;
    print(n);
    return 0;
}
