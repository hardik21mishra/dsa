// linear search using recursion

#include<iostream>
using namespace std;

bool linearsearch(int arr[], int size, int key){
    if (size == 0) return 0;

    if (arr[0] == key) return 1;

    else{
        bool remaining = linearsearch(arr + 1, size - 1, key);
        return remaining;
    }
}

int main(){
    int arr[] = {11, 5, 8, 6, 9};
    int size = 5;
    int key = 9;
    bool x = linearsearch(arr, size, key);
    if (x) {
        cout<<"present";
    }
    else {
        cout<<"absent";
    }
    return 0;
}