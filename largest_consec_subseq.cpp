#include <bits/stdc++.h>
using namespace std;

//Time complexity: O(n).

int largest_subseqence(vector<int> &arr){
	int n = arr.size();
	unordered_set<int> ht;
	int max_len = 1;
	for(int i: arr)
		ht.insert(i);
	for(int i: arr){
		if(ht.find(i-1) == ht.end()){
			int cur_val = i;
			int length = 0;
			while(ht.find(cur_val) != ht.end()){
				length++;
				cur_val++;
			}
			max_len = max(max_len, length);
		}
	}
	return max_len;
}

int main(){
	int n;
	cin>>n;
	vector<int> arr(n);
	for(int i=0;i<n;i++)
		cin>>arr[i];
	int largest_length = largest_subseqence(arr);
	cout<<largest_length<<endl;
	return 0;
}