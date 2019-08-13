#include <bits/stdc++.h>
using namespace std;


struct data{
	int r;
	int c;
	int val;
};

//contruct min heap
bool comp(const data &a, const data &b){
	return a.val > b.val;
}

int get_kth_minimum(vector<vector<int>> &arr, int k){
	int n = arr.size();		//row size
	int m = arr[0].size(); //column size
	vector<data> hp(m);
	for(int i=0;i<m;i++){
		hp[i].val = arr[0][i];
		hp[i].r = 0;
		hp[i].c = i;
	}
	// make_heap(hp.begin(), hp.end(), comp);
	int res;
	while(k--){
		data tmp = hp[0];
		res = tmp.val;
		pop_heap(hp.begin(), hp.end(), comp);
		if(tmp.r != n-1){
			data temp;
			temp.val = arr[tmp.r+1][tmp.c];
			temp.r = tmp.r+1;
			temp.c = tmp.c;
			hp.push_back(temp);
			push_heap(hp.begin(), hp.end(), comp);
		}
	}
	return res;
}

int main(){
	int n,m,k;
	cin>>n>>m>>k;
	//here the matrix is row-wise and col-wise sorted
	vector<vector<int>> arr(n, vector<int>(m));
	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++)
			cin>>arr[i][j];

	int res = get_kth_minimum(arr, k);
	cout<<res<<endl;
}