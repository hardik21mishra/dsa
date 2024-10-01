//ROTATE IMAGE PROBLEM

#include <iostream>
using namespace std;


void imagerotate(int a[][3]){
    for(int i=0;i<3;i++){
        for(int j=i; j<3;j++){
            swap(a[i][j], a[j][i]);
        }
        
    }
    
    for(int i=0;i<3;++i){
        int left = 0;
        int right = 2;
        while (left<right){
            swap(a[i][left],a[i][right]);
            ++left;
            --right;
        }
            
    }
     for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            std::cout << a[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    // Initialize a 2D array with the values 1 to 9
    int arr[3][3] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };
    imagerotate(arr);
    return 0;
}
