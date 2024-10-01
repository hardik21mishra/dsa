#include<iostream>
using namespace std;

int binarySearch(int arr[], int size, int key){
    int start = 0;
    int end = size - 1;
    int mid = start + (end - start)/2;
    
    while (start<=end){
        if (arr[mid] == key){
            return mid;
        }

        if (key > arr[mid]){
            start = mid + 1;
        }
        else{
            end = mid - 1;
        }    
        mid = start + (end - start)/2; // same as m = (s + e)/2
    }
    return -1;
}   
int main(){
    int even[6] = {11, 56, 2, 7, 55, -7};
    int odd[5] = {4, 8, 5, 11, 12};

    int index = binarySearch(even,6,7);
    cout<<"Index of 7 in even array is: "<<index<<endl;
    return 0;
}