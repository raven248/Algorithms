#include <bits/stdc++.h>
using namespace std;


void Push(stack<int> &stk, int val, int &minim){
	if(minim == INT_MAX)
		minim = val;

	if(minim > val){
		int temp = val;
		val = 2*val - minim;
		minim = temp;
	}
	stk.push(val);
}

void Pop(stack<int> &stk, int &minim){
	if(minim > stk.top())
		minim = 2*minim - stk.top();
	stk.pop();
}


int main(){
	int n;
	cin>>n;
	// vector<int> arr(n);
	stack<int> stk;
	int minim = INT_MAX;
	for(int i=0;i<n;i++){
		int a;
		cin>>a;
		Push(stk, a, minim);
		cout<<minim<<endl;
	}
	int q;
	cin>>q;
	//enter queries;
	while(q--){
		return 0; // replace this code to add queries
	}
	return 0;
}