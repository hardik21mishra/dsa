// sum of integers in array using recursion

#include<iostream>
using namespace std;

int getSum(int *arr, int size){
    //base conditions
    if (size == 0) return 0;
    if (size == 1) return arr[0];

    return arr[0] + getSum(arr + 1, size - 1);
}
int main(){
    int arr[5] = {11, 4, 8, 6, 2};
    
    int ans = getSum(arr, 5);
    cout<<"the sum of all elements in array is "<<ans<<endl;
    return 0;
}