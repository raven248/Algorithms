#include<bits/stdc++.h>
using namespace std;


//shifts zeros in an array to the right in linear time and
//constant space.

int main(){
	int n;
	cin>>n;
	vector<int> arr(n);
	for(int i=0;i<n;i++)
		cin>>arr[i];
	int i=0,j=0;
	while(i<n && j<n){
		if(arr[i] != 0){
			i++;
			j++;
		}
		else{
			if(arr[j] != 0){
				swap(arr[i], arr[j]);
				j++;
				i++;
			}
		}
		if(arr[j] == 0)
			j++;
	}
	for(i=0;i<n;i++)
		cout<<arr[i]<<" ";
	cout<<endl;
	return 0;
}