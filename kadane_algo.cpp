// KADANE'S ALGORITHM --> FIND MAXIMUM SUM POSSIBLE FROM ALL THE SUBARRAYS
#include<bits/stdc++.h>
#include<iostream>
#include<vector>
#define INT_MIN (-INT_MAX-1)
using namespace std;

int maxSubarraySum(vector<int> &arr, int n){
    int maxi = INT_MIN; // Maximum sum, initialized to the smallest possible integer
    int curr_sum = 0;
    for(int i = 0 ; i < n ; i++){
        curr_sum += arr[i];

        // Update maxi with the maximum of itself and current_sum
        maxi = max(curr_sum, maxi);

        // If current_sum becomes negative, reset it to 0
        if (curr_sum < 0) curr_sum = 0;
    }
    return maxi;
    
}
int main(){
    vector <int> arr = {5, 4, 7};
    int n = arr.size();
    cout<< maxSubarraySum(arr, n);
    return 0;
}