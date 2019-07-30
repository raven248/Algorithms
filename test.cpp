#include<bits/stdc++.h>
using namespace std;

int *ptr;

void print(int &val){
	cout<<&val - ptr<<endl;
}

int main(){
	int n = 8;
	n>>1;
	cout<<n<<endl;
	return 0;	
}