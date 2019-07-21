#include <bits/stdc++.h>
using namespace std;

struct node{
	int value=0;
	node *left = NULL;
	node *right = NULL;
};

void print_breadth_first(node *root){
	queue<node*> q;
	q.push(root);
	int count = 1;
	int actual = 1;
	while(!q.empty()){
		node *val = q.front();
		q.pop();
		if(count == actual){
			cout<<val->value<<endl;
			actual *= 2;
			count = 1;
		}
		else{
			cout<<val->value<<" ";
			count++;
		}
		if(val->left){
			q.push(val->left);
		}
		if(val->right)
			q.push(val->right);
	}
	//you can print a endlin here if needed
	//done printing
	//if u want to store the values instead then store it in aarray instead
}

int main(){
	int n; //number of nodes
	cin>>n;
	//scan and store the node values
	node *root = new node;
	root->value = 1;
	node *temp_left = new node;
	temp_left->value = 2;
	root->left = temp_left;
	node *temp_right = new node;
	temp_right->value = 3;
	root->right = temp_right;
	node *some = new node;
	some->value = 4;
	root->left->left = some;
	print_breadth_first(root);
	cout<<endl;
	return 0;
}