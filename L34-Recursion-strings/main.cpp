// swap strings using recursion

#include<iostream>
using namespace std;

void revstr(string s, int i, int j){
    // base case
    
    if (i > j){
        return;
    }

    swap(s[i], s[j]);
    i++;
    j--;
    revstr(s, i, j);

}
int main(){
    string s = "hardik";
    revstr(s, 0, s.length() - 1);
    cout<<s;
    return 0;
}