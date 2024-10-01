//binary search using recursion

#include <iostream>
using namespace std;

int binsearcharray(int arr[], int s, int e, int k) {
    // Base case: if start index exceeds end index
    if (s > e) return -1;  // Return false if key is not found

    // Calculate the middle index
    int mid = s + (e - s) / 2;

    // Check if the middle element is the key
    if (arr[mid] == k) return mid;

    // If key is greater than the middle element, search in the right half
    if (arr[mid] < k) {
        return binsearcharray(arr, mid + 1, e, k);
        
    }
    // If key is smaller than the middle element, search in the left half
    else {
        return binsearcharray(arr, s, mid - 1, k);
    }
}

int main() {
    int arr[] = {2, 4, 6, 10, 14, 16};
    int start = 0, end = 5, key = 14;
    cout<< binsearcharray(arr, start, end, key);
    // Perform binary search and print result
    // if (binsearcharray(arr, start, end, key)) {
    //     cout << "present";
    // } else {
    //     cout << "absent";
    // }

    return 0;
}
