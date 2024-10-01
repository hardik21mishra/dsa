#include <iostream>
using namespace std;

// Function to partition the array
int partition(int* arr, int s, int e) {
    int pivot = arr[s];
    int count = 0;
    
    // Count elements smaller than or equal to pivot
    for (int i = s + 1; i <= e; i++) {
        if (arr[i] <= pivot) {
            count++;
        }
    }

    // Place the pivot element at its correct position
    int pivotIndex = s + count;
    swap(arr[pivotIndex], arr[s]);

    int i = s;
    int j = e;
    
    // Partition the array
    while (i < pivotIndex && j > pivotIndex) {
        while (arr[i] < pivot) {
            i++;
        }
        while (arr[j] > pivot) {
            j--;
        }
        if (i < pivotIndex && j > pivotIndex) {
            swap(arr[i++], arr[j--]);
        }
    }
    
    return pivotIndex;
}

// Function to perform QuickSort
void quickSort(int* arr, int s, int e) {
    // Base condition
    if (s >= e) {
        return;
    }

    // Partition the array and get the pivot index
    int p = partition(arr, s, e);

    // Recursively sort the left and right parts
    quickSort(arr, s, p - 1);
    quickSort(arr, p + 1, e);
}

int main() {
    int arr[] = {5,2,7,8,41,2};
    int size = sizeof(arr) / sizeof(arr[0]); // Correct size calculation
    
    quickSort(arr, 0, size - 1);
    
    // Print the sorted array
    for (int i = 0; i < size; i++) {
        cout << arr[i] << ' ';
    }
    cout << endl;

    return 0;
}
