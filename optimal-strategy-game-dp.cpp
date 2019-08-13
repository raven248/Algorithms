#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> memo;

int maximize_my_share(vector<int> &arr, int summ, int i, int j){
	if(i == j)
		return arr[i];
	if(i+1 == j)
		return max(arr[i], arr[j]);
	if(memo[i][j] != 0)
		return memo[i][j];
	memo[i][j] = max(summ-arr[i]-maximize_my_share(arr, summ-arr[i], i+1, j), summ-arr[j]-maximize_my_share(arr, summ-arr[j], i, j-1));
	return memo[i][j];
}

int main(){
	//input is the array of even length
	int n;
	cin>>n;
	vector<int> arr(n);
	for(int i=0;i<n;i++)
		cin>>arr[i];
	int summ = 0;
	summ = accumulate(arr.begin(), arr.end(), 0);
	for(int i=0;i<n;i++)
		memo.push_back(vector<int>(n));
	int maximum_won = maximize_my_share(arr, summ, 0, n-1);
	cout<<maximum_won<<endl;
	return 0;
}