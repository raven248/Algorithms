#include <bits/stdc++.h>
using namespace std;

// DYNAMIC PROGRAMMING
/*
example:
	0 0 1
	1 1 0
	1 1 0

	ans: 2
*/

int largest_square_recursive(vector<vector<int>> &dp, vector<vector<int>> &arr, int i, int j){
	if(i == 0 && j == 0)
		return arr[0][0];
	if(i == 0 || j == 0)
		dp[i][j] = arr[i][j];
	else if(dp[i][j] != 0)
		return dp[i][j];
	else if(arr[i][j]  != 0){
		dp[i][j] = min(largest_square_recursive(dp, arr, i-1, j), largest_square_recursive(dp, arr, i, j-1));
		dp[i][j] = min(dp[i][j], largest_square_recursive(dp, arr, i-1, j-1));
		dp[i][j]++;
	}

	if(j == 0)
		return max(dp[i][j], largest_square_recursive(dp, arr, i-1, arr.size()-1));
	return max(dp[i][j], largest_square_recursive(dp, arr, i, j-1));
}

int largest_square_iterative(vector<vector<int>> &arr){
	int result = 1;
	int n = arr.size();
	vector<vector<int>> dp(n, vector<int>(n));
	for(int i=0;i<n;i++){
		dp[0][i] = arr[0][i];
		dp[i][0] = arr[i][0];
	}

	for(int i=1;i<n;i++){
		for(int j=1;j<n;j++){
			if(arr[i][j]){
				dp[i][j] = min(dp[i-1][j], dp[i][j-1]);
				dp[i][j] = min(dp[i-1][j-1], dp[i][j]);
				dp[i][j]++;
				result = max(result, dp[i][j]);
			}
		}
	}
	return result;
}

int main(){
	int n;
	cin>>n;
	vector<vector<int>> arr(n, vector<int>(n));

	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			cin>>arr[i][j];
	vector<vector<int>> dp(n, vector<int>(n));

	for(int i=0;i<n;i++){
		dp[0][i] = arr[0][i];
		dp[i][0] = arr[i][0];
	}
	cout<<largest_square_recursive(dp, arr, n-1, n-1)<<endl;
	cout<<largest_square_iterative(arr)<<endl;
	return 0;
}