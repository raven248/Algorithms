#include<bits/stdc++.h>
using namespace std;


vector<int> max_unsorted_array(vector<int> &A){
	int n = A.size();
	int l = -1,r = -2;
	int i=1;
	int maxim;
	int minim;
	while(i<n){
		if(A[i] < A[i-1]){
			l = i-1;
			maxim = A[i-1];
			minim = A[i-1];
			break;
		}
		i++;
	}
	while(i<n){
		if(A[i] < A[i-1])
			r = i;
		i++;
	}
	for(int j=l;j<=r;j++){
		minim = min(minim, A[j]);
		maxim = max(maxim, A[j]);
	}

	i = l-1;
	//adjusting left bound
	while(i >= 0){
		if(A[i] > minim)
			l = i;
		else
			break;
		// maxim = max(maxim, A[i]);
		minim = min(minim, A[i]);
		i--;
	}
	i = (l != -1)?r+1: n;
	//adjusting right bound
	while(i<n){
		if(A[i] < maxim)
			r = i;
		else
			break;
		maxim = max(maxim, A[i]);
		i++;
	}
	vector<int> result;
	if(l == -1)
		result.push_back(-1);
	else{
		result.push_back(l);
		result.push_back(r);
	}
	return result;
}

int main(){
	int n;
	cin>>n;
	vector<int> A(n);
	for(int i=0;i<n;i++)
		cin>>A[i];
	vector<int>indices = max_unsorted_array(A);
	for(int i:indices)
		cout<<i<<" ";
	cout<<endl;
	return 0;
}