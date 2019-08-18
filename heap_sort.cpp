#include <bits/stdc++.h>
using namespace std;

void heapify(vector<int> &arr, int n, int i){
	int l = 2*i+1;
	int r = 2*i+1;
	int largest = i;
	
	if(l < n && arr[largest] < arr[l])
		largest = l;
	if(r < n && arr[largest] < arr[r])
		largest = r;
	if(largest != i){
		swap(arr[i], arr[largest]);
		heapify(arr, n, largest);
	}
}

void heap_sort(vector<int> &arr){
	int n =arr.size();
	for(int i = n/2 - 1;i>=0;i--)
		heapify(arr, i, n);
	for(int i = n-1;i>0;i--){
		swap(arr[0], arr[i]);
		heapify(arr, i, 0);
	}
}


int main(){
	int n;
	cin>>n;
	vector<int> arr(n);
	for(int i=0;i<n;i++)
		cin>>arr[i];	
	heap_sort(arr);
	for(int i:arr)
		cout<<i<<" ";
	cout<<endl;
	return 0;
}
