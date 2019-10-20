#include <bits/stdc++.h>
using namespace std;

int main(){
	//given n numbers find hamming summ of all of them taken 2 at a time
	int n;
	cin>>n;
	vector<int> arr;
	int a;
	while(n--){
		cin>>a;
		arr.push_back(a);
	}
	//int has 32 bits so
	int bit_position = 0;
	int one_count = 0;
	unsigned int hamming_sum = 0;
	unsigned int m = 100000007;
	while(bit_position < 32){
		one_count = 0;
		for(int i=0;i<arr.size();i++)
			if((1<<bit_position) & arr[i])
				one_count++;
		hamming_sum += (one_count*(arr.size() - one_count));
		hamming_sum %= m;
		bit_position++;
	}

	cout<<hamming_sum<<endl;
	return 0;
}