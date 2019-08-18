#include <bits/stdc++.h>
using namespace std;


void merge(vector<int> &arr, int l, int r){
	int m = (l+r)/2;
	vector<int> mem(arr.size());
	mem = arr;
	int i=l;
	int j=m+1;
	int k = l;
	while(i < (m+1) && j <= r){
		if(mem[i] < mem[j]){
			arr[k] = mem[i];
			i++;
		}
		else{
			arr[k] = mem[j];
			j++;
		}
		k++;
	}

	while(i<=m){
		arr[k] = mem[i];
		k++;
		i++;
	}

	while(j<=r){
		arr[k] = mem[j];
		k++;
		j++;
	}
}


void merge_sort(vector<int> &arr, int l, int r){
	if(l<r){
		int m = (l+r)/2;
		merge_sort(arr, l, m);
		merge_sort(arr, m+1, r);
		merge(arr, l, r);
	}
}

int main(){
	int n;
	cin>>n;
	vector<int> arr(n);
	for(int i=0;i<n;i++)
		cin>>arr[i];
	for(int i=0;i<n;i++)
		cout<<arr[i]<<" ";
	cout<<endl;
	merge_sort(arr, 0, n-1);
	for(int i=0;i<n;i++)
		cout<<arr[i]<<" ";
	cout<<endl;
	return 0;
}