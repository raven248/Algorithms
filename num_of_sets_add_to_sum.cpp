#include<bits/stdc++.h>
using namespace std;
//Dynamic Programming

map<pair<int, int>, int> mem;

int num_of_sets(vector<int> &arr, int s, int i){
	//using hashmap
	int temp;
	if(i == arr.size()-1)
		return (arr[i] == s)?1:0;
	auto ptr = mem.find(make_pair(i, s));
	if(ptr != mem.end())
		return ptr->second;
	if(arr[i] > s)
		temp =  num_of_sets(arr, s, i+1);
	else if(arr[i] == s)
		temp = 1+num_of_sets(arr, s, i+1);
	else{
		temp = num_of_sets(arr, s, i+1);
		int k = num_of_sets(arr, s-arr[i], i+1);
		if(k != 0)
			temp += k;
	}
	mem[make_pair(i, s)] = temp;
	return temp;
}


int number_of_sets(vector<int> &arr, vector<vector<int>> &dp, int s, int i){
	//using matrix as a memory
	if(i == arr.size()-1)
		return (arr[i] == s)?1:0;
	if(dp[i][s] != -1)
		return dp[i][s];
	if(arr[i] > s)
		dp[i][s] =  number_of_sets(arr, dp, s, i+1);
	else if(arr[i] == s)
		dp[i][s] = 1+number_of_sets(arr, dp, s, i+1);
	else{
		dp[i][s] = number_of_sets(arr, dp, s, i+1);
		int k = number_of_sets(arr, dp, s-arr[i], i+1);
		if(k != 0)
			dp[i][s] += k;
	}
	return dp[i][s];
}


int main(){
	int n,s;
	cin>>n>>s;
	vector<int> arr(n);
	for(int i=0;i<n;i++)
		cin>>arr[i];
	vector<vector<int>> dp(n, vector<int>(s+1, -1));
	cout<<number_of_sets(arr, dp, s, 0)<<endl;
	cout<<num_of_sets(arr, s, 0)<<endl;
	return 0;
}