// reverse alternate elements in array

#include <iostream>
using namespace std;

void revArray(int arr[], int n)
{
    int i=0,j=1;
    while(i<n && j <n){
        swap(arr[i],arr[j]);
        i += 2;
        j += 2;
    }
}

void printArray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}



int main()
{
    int four[4] = {5,7,9,-2};
    int three[3] = {5,4,3};

    revArray(four, 4);
    revArray(three, 3);

    printArray(four, 4);
    printArray(three, 3);
    return 0;
}