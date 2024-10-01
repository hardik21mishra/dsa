// to find sum of all elements in array
#include<iostream>
using namespace std;

int addArray(int x[], int size){
    int sum = 0;
    for (int i = 0; i < size; i++){
        sum = sum + x[i];
    }
    return sum;
}
int main(){
    int size;
    cout<<"Enter size of array: "<<endl;
    cin>>size;
    int x[size];
    cout<<"Enter elements in the array: "<<endl;
    for(int i=0;i<size;i++){
        cin>>x[i];
    }
    cout<<"array entered by you: ";
    for(int i=0;i<size;i++){
        cout<< x[i] <<" ";
    }

    cout<<endl<<"The sum of all elements in array is: "<<addArray(x,size)<<endl;

    return 0;
}