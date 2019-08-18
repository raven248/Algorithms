#include <bits/stdc++.h>
using namespace std;


//returns as a 0-based index
int safe_position(int n, int k){
	if(n == 1)
		return 0;
	return (safe_position(n-1, k)+k)%n;
}


int main(){
	int n,k;
	cin>>n>>k;
	int safe_loc = safe_position(n, k);
	cout<<safe_loc<<endl;
	return 0;
}