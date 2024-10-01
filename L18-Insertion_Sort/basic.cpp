#include<iostream>
using namespace std;
// sample input array: arr[] = {10, 1, 7, 4, 8, 2, 11};
int main(){
    int n,i,j, arr[100];
    cout << "Enter Size of array: ";
    cin >> n;
    cout << endl;
    cout << "Enter elemrnts in your array: " << endl;
    for (int x = 0; x < n; x++)
    {
        cin >> arr[x];
    }

    for(int i = 1; i<n; i++){
        int temp = arr[i];  // temp = 1 (as per sample input array)
        int j = i-1;
        for(; j>=0; j--){
            if(arr[j]>temp){
                arr[j+1] = arr[j];
            }
            else{
                break;
            }
        }
    arr[j+1] = temp;
    }
    cout<<"the sorted array: ";
    for (int i = 0; i < n ; i++)
        {
            cout<<arr[i]<<" ";
        }

    return 0;
}