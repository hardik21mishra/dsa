#include<iostream>
using namespace std;
// sample input array: arr[] = {10, 1, 7, 4, 8, 2, 11};

void BubbleSort(int arr[], int n){
    for(int i = 1; i<n; i++){
        bool swapped = false;
        for(int j = 0; j < n-i; j++ ){
            if (arr[j]>arr[j+1]){
                swap(arr[j],arr[j+1]);
                swapped = true;
            }
            }
        if(swapped == false){
            break;
        }
        }
}

int main(){
    int n,i,j, arr[100];
    cout << "Enter Size of array: ";
    cin >> n;
    cout << endl;
    cout << "Enter elements in your array: " << endl;
    for (int x = 0; x < n; x++)
    {
        cin >> arr[x];
    }

    BubbleSort(arr, n); // function call
    
    cout<<"the sorted array: ";
    for (int i = 0; i < n ; i++)
        {
            cout<<arr[i]<<" ";
        }

    return 0;
}