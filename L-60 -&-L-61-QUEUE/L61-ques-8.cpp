// Sum of minimum and maximum elements of all subarrays of size k(ques 8, 61)

// gfg --> https://www.geeksforgeeks.org/sum-minimum-maximum-elements-subarrays-size-k/

#include <bits/stdc++.h>
using namespace std;

int solve(int *arr, int n, int k){
    deque<int> maxi(k);
    deque<int> mini(k);

    // addition of first k sized window
    for(int i = 0 ; i < k ; i++){
        while(arr[maxi.back()] <= arr[i])
    }
}

int main(){
    int arr[7] = {2, -5, -1, 7, -3, -1, -2};
    cout << solve(arr, 7, 4) << endl;
    return 0;
}