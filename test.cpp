#include<bits/stdc++.h>
using namespace std;

int *ptr;

void print(int &val){
	cout<<&val - ptr<<endl;
}

int main(){
	vector<int> arr;
	for(int i=0;i<100;i++)
		arr.push_back(i);
	ptr = &arr[0];
	for(int i=0;i<arr.size();i++)
		print(arr[i]);
	return 0;	
}