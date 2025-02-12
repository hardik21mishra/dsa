#include <bits/stdc++.h>
using namespace std;

class DisjointSet{
    private:
        vector<int> rank, parent, size;
    public:
        DisjointSet(int n){
            rank.resize(n+1, 0);
            parent.resize(n+1);
            size.resize(n+1, 1);

            for(int i = 0; i < n; i++){
                parent[i] = i;
            }
        }
        int findpu(int node) {
            if (node != parent[node]) {
                parent[node] = findpu(parent[node]); // Path compression
            }
            return parent[node];
        }

        void unionByRank(int u, int v){
            int ulp_u = findpu(u);
            int ulp_v = findpu(v);
            
            if(ulp_u == ulp_v) return;

            if(rank[ulp_u] < rank[ulp_v]){
                parent[ulp_u] = ulp_v;
                // the rank will not increase because, smaller
                // structure is connected to the larger, which will 
                // have no impact on height
            }
            else if(rank[ulp_v] < rank[ulp_u]){
                parent[ulp_v] = ulp_u;
                // no rank increase
            }
            else{
                parent[ulp_v] = ulp_u;
                rank[ulp_u]++;
            }
        }

        void unionBySize(int u, int v){
            int ulp_u = findpu(u);
            int ulp_v = findpu(v);

            if(ulp_u == ulp_v) return;

            if(size[ulp_u] < size[ulp_v]){
                parent[ulp_u] = ulp_v;
                size[ulp_v] += size[ulp_u];
            }
            else{
                parent[ulp_v] = ulp_u;
                size[ulp_u] += size[ulp_v];
            }
        }
};

int main(){
    /*
    DisjointSet d(7);
    d.unionByRank(1,2);
    d.unionByRank(2,3);
    d.unionByRank(4,5);
    d.unionByRank(6,7);
    d.unionByRank(5,6);
    // to know if 3 and 7 are part
    // of the same component 
    if (d.findpu(3) == d.findpu(7)) cout << "same" << endl;
    else cout << "not same" << endl;
    
    d.unionByRank(3,7);
    
    if (d.findpu(3) == d.findpu(7)) cout << "same" << endl;
    else cout << "not same" << endl;
    */

    // below is the same result using union by size
    DisjointSet d(7);
    d.unionBySize(1,2);
    d.unionBySize(2,3);
    d.unionBySize(4,5);
    d.unionBySize(6,7);
    d.unionBySize(5,6);
    // to know if 3 and 7 are part
    // of the same component 
    if (d.findpu(3) == d.findpu(7)) cout << "same" << endl;
    else cout << "not same" << endl;
    
    d.unionBySize(3,7);
    
    if (d.findpu(3) == d.findpu(7)) cout << "same" << endl;
    else cout << "not same" << endl;
    return 0;
}