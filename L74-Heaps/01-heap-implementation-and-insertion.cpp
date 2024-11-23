// heap implementation and insertion code
#include <bits/stdc++.h>
using namespace std;
// Max Heap 
// T.C. --> O(log n)
class heap{
    public:
        int arr[1000];
        int size;

        heap() : size(0) { arr[0] = -1; }

        void insert(int val){
            size++;
            int index = size;
            arr[index] = val;

            while(index > 1){
                int parent = index/2;

                if(arr[parent] < arr[index]){
                    swap(arr[parent], arr[index]);
                    index = parent;
                }
                else return;
            }
        }

        void print(){
            for(int i = 1 ; i <= size ; i++){
                cout << arr[i] << " ";
            }
            cout << endl;
        }
};
int main(){
    heap h;
    h.insert(50);
    h.insert(55);
    h.insert(53);
    h.insert(52);
    h.insert(54);
    h.print();
    return 0;
}