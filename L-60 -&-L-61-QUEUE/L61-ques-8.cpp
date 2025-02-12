// Sum of minimum and maximum elements of all subarrays of size k(ques 8, 61)

// gfg --> https://www.geeksforgeeks.org/sum-minimum-maximum-elements-subarrays-size-k/

#include <bits/stdc++.h>
using namespace std;

int solve(int *arr, int n, int k) {
    deque<int> maxi(k); // To store indices of elements for max in window
    deque<int> mini(k); // To store indices of elements for min in window

    // Initialize the first window of size k
    for (int i = 0; i < k; i++) {
        // Remove elements smaller than the current element for maxi deque
        while (!maxi.empty() && arr[maxi.back()] <= arr[i])
            maxi.pop_back();
        // Remove elements greater than the current element for mini deque
        while (!mini.empty() && arr[mini.back()] >= arr[i])
            mini.pop_back();
        // Add current element index to both deques
        maxi.push_back(i);
        mini.push_back(i);
    }

    int ans = 0; 
    // Add the sum of the maximum and minimum for the first window
    ans += arr[maxi.front()] + arr[mini.front()];

    // Process the rest of the array
    for (int i = k; i < n; i++) {
        // Remove elements out of the current window
        while (!maxi.empty() && i - maxi.front() >= k)
            maxi.pop_front();
        while (!mini.empty() && i - mini.front() >= k)
            mini.pop_front();

        // Remove elements smaller than the current element for maxi deque
        while (!maxi.empty() && arr[maxi.back()] <= arr[i])
            maxi.pop_back();
        // Remove elements greater than the current element for mini deque
        while (!mini.empty() && arr[mini.back()] >= arr[i])
            mini.pop_back();

        // Add current element index to both deques
        maxi.push_back(i);
        mini.push_back(i);

        // Add the sum of the maximum and minimum for this window
        ans += arr[maxi.front()] + arr[mini.front()];
    }

    // Return the final answer
    return ans;
}

int main() {
    int arr[7] = {2, 5, -1, 7, -3, -1, -2};
    int k = 4;
    cout << solve(arr, 7, k) << endl; // Expected output: 18
    return 0;
}
