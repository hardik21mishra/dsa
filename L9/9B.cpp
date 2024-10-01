//_____________________________REVERSE A ARRAY________________________

#include <iostream>
using namespace std;

void revArray(int arr[], int n)
{
    int start = 0;
    int end = n - 1;
    while (start <= end)
    {
        swap(arr[start], arr[end]);
        start++;
        end--;
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