#include <bits/stdc++.h>
using namespace std;


bool has_sum(vector<int> &arr, int i, int summ){
	int r = arr.size()-1;
	while(i < r){
		if(arr[i] + arr[r] == summ)
			return true;
		if(arr[i]+arr[r] > summ)
			i++;
		else
			r--;
	}
	return false;
}

bool compare(int &a, int &b){
	return a>b;
}

bool has_pythagorian(vector<int> &arr){
	sort(arr.begin(), arr.end(), compare);
	for(int i=0;i<arr.size();i++)
		arr[i] = arr[i]*arr[i];
	for(int i=0;i<arr.size()-2;i++){
		if(has_sum(arr, i+1, arr[i]))
			return true;
	}
	return false;
}


int main(){
	int n;
	cin>>n;
	vector<int> arr(n);
	for(int i=0;i<n;i++)
		cin>>arr[i];
	bool has_it = has_pythagorian(arr);
	if(has_it)
		cout<<"has it"<<endl;
	else
		cout<<"doesnt has it"<<endl;
	return 0;
}