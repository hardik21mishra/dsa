#include <iostream>
using namespace std;
// ques -----> [6, 2, 8, 4, 10]
// ans ------> [2, 4, 6, 8, 10]

void SelectionSort(int arr[], int n){
    for (int i = 0; i < n - 1; i++)
    {
        int minIndex = i;
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[minIndex])
            {
                minIndex = j;
            }
           
        }
    swap(arr[minIndex], arr[i]);
    }
}
int main()
{
    int n,i, arr[100];
    cout << "Enter Size of array: ";
    cin >> n;
    cout << endl;
    cout << "Enter elements in your array: " << endl;
    for (int x = 0; x < n; x++)
    {
        cin >> arr[x];
    }

SelectionSort(arr, n);
    
cout<<"the sorted array: "<<endl;
for (int i = 0; i < n ; i++)
    {
        cout<<arr[i]<<" ";
    }
return 0;
}