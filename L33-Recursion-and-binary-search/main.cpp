// to check whether the array is sorted or not using recursion

#include<iostream>
using namespace std;

bool issorted(int arr[], int n){ 
    if (n == 0 || n == 1) return 1; //base condition

    if (arr[0]>arr[1]){
        return 0;
    }
    else{
        bool ans = issorted(arr + 1, n - 1);
        return ans;
    }
}


int main(){
    int arr[] = {2, 4, 6, 9, 19, 13};
    int x = issorted(arr, 6);
    cout<<x;
    return 0;
}