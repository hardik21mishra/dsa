// MAX HEAP
#include <bits/stdc++.h>
using namespace std;
// in deletion we always delete heap node(here we deleted 55)

// Steps of Deletion: tc --> O(log N)
    // 1. swap first(root) node with last node(righmost leaf)
    // 2. Remove last Node
    // 3. Propagate root node to its correct position

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

        void deletefromHeap(){
            if(size == 0) {
                cout << "Nothing to delete" << endl;
                cout << endl;
            }

            arr[1] = arr[size]; // step 1
            size--; // step 2

            // step 3
            int i = 1;
            while (i < size){
                int leftIndex = 2 * i;
                int RightIndex = 2 * i + 1;

                if(leftIndex < size && arr[i] < arr[leftIndex] && arr[leftIndex] > arr[RightIndex]){
                    swap(arr[i], arr[leftIndex]);
                    i = leftIndex;
                }
                else if(leftIndex < size && arr[i] < arr[RightIndex] && arr[leftIndex] < arr[RightIndex]){
                    swap(arr[i], arr[RightIndex]);
                    i = RightIndex;
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

    h.deletefromHeap();
    h.print();
    return 0;
}
