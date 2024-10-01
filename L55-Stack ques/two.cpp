// DELETE MIDDLE OF A STACK

// question link = https://www.geeksforgeeks.org/problems/delete-middle-element-of-a-stack/1?itm_source=geeksforgeeks&itm_medium=article&itm_campaign=practice_card

// gfg copy paste
#include <iostream>
#include<bits/stdc++.h>
using namespace std;

int main() {
	stack<char> st;
	st.push('1');
	st.push('2');
	st.push('3');
	st.push('4');
	st.push('5');
	st.push('6');
	st.push('7');
	vector<char>v;
	while(!st.empty()){
	v.push_back(st.top());
	st.pop();
	}
	int n=v.size();
	if(n%2==0){
	int target=(n/2);
	for(int i=0;i<n;i++){
		if(i==target)continue;
		st.push(v[i]);
	}
	}else{
	int target=ceil(n/2); 
	for(int i=0;i<n;i++){
		if(i==target)continue;
		st.push(v[i]);
	}
	}
	cout<<"Printing stack after deletion of middle: "; 
	while (!st.empty()) {
		char p = st.top();
		st.pop();
		cout << p << " ";
	}
	return 0;
}

