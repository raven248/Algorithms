#include <bits/stdc++.h>
using namespace std;


struct node{
	int val = 0;
	node *next = NULL;
};

void Push(node *stk, int val){
	
}


int main(){
	int n;
	cin>>n;
	// vector<int> arr(n);
	node *stk = new node;
	for(int i=0;i<n;i++){
		int a;
		cin>>a;
		Push(stk, a);
	}
	int q;
	//enter queries;
	while(q--){

	}
	return 0;
}