#include <bits/stdc++.h>
using namespace std;


int get_max_sum(vector<int> &arr){
	int dp = 0;
	int maxim = INT_MIN;
	int n = arr.size();
	for(int i:arr){
		dp += i;
		maxim = max(dp, maxim);
		dp = max(0, dp);
	}
	return maxim;
}

int main(){
	int n;
	cin>>n;
	vector<int> arr(n);
	for(int i=0;i<n;i++)
		cin>>arr[i];
	int result = get_max_sum(arr);
	cout<<result<<endl;
	return 0;
}