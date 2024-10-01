#include<iostream>
using namespace std;

void merge(int *arr, int s, int e){
    int mid = s + (e - s)/2;

    int len1 = mid - s + 1;
    int len2 = e - mid;

    int *first = new int[len1];
    int *second = new int[len2];

    int mainArrayIndex = s;

    for(int i = 0; i<len1 ; i++){
        first[i]
    }

}
void mergesort(int *arr, int s, int e){
    if (s>=e) return;
    
    int mid = s + (e - s)/2;
    
    mergesort(arr, s, mid);
    
    mergesort(arr, mid+1, e);
 
    merge(arr, s, e);
}
int main(){
    int arr[15] = {3,7,0,1,5,8,3,2,34,66,87,23,12,12,12};
    int n = 15;
    mergesort(arr, 0, n-1);
    return 0;
}