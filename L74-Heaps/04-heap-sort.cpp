#include <bits/stdc++.h>
using namespace std;

void heapify(int arr[], int n, int i){
            int largest = i;
            int leftChild = 2 * i;
            int rightChild = (2 * i) + 1;

            if(leftChild <= n && arr[largest] < arr[leftChild]){
                largest = leftChild;
            }
            
            if(rightChild <= n && arr[largest] < arr[rightChild]){
                largest = rightChild;
            }

            if(largest != i){
                swap(arr[largest], arr[i]);
                heapify(arr, n, largest); // process remaining indexes
            }
        }

void heapSort(int arr[], int n){
    int t = n;

    while(t > 1){
        // step 1 : swap first and last element
        swap(arr[t], arr[1]);
        t--; 

        // step 2 : heapify
        heapify(arr, t, 1);
    }
}

int main(){
    int arr[6] = {-1, 54, 53, 55, 52, 50};
    int n = 5;

    // heap creation
    for(int i = n/2 ; i > 0 ; i--){
        heapify(arr, n, i);
    }
    cout << "Printing the array now " << endl;
    for(int i = 1 ; i <= n ; i++){
        cout << arr[i] << " ";
    } cout << endl;

    //heap sort
    heapSort(arr, n);
    
    cout << "Printing the heap sorted array now " << endl;
    for(int i = 1 ; i <= n ; i++){
        cout << arr[i] << " ";
    } cout << endl;
    return 0;
}