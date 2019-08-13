#include <bits/stdc++.h>
using namespace std;

int dp(int i, int j, vector<vector<int>> &mem){
	if(mem[i][j] != -1)
		return mem[i][j];
	for(;i<j;i++,j--){
		if()
	}
}

int max_palindrome(string &s, vector<vector<int>>mem, int i, int j){
	if(i == j)
		return 1;
	if(mem[i][j] == 1)
		return j-i+1;
	if(mem[i][j] == 0)
		return max(max_palindrome(s, mem, i+1, j), max_palindrome(s, mem, i, j-1), compare);
	if(max_palindrome(s, mem, i, j-1) == j-i)
}

int main(){
	string s;
	cin>>s;
	vector<vector<int>> mem(n, vector<int>(n, -1));
	cout<<max_palindrome(s, mem, 0, s.size()-1)<<endl;
	return 0;
}