#include <bits/stdc++.h>
using namespace std;

//recursive approach : few lines and easy
int convert_to_base(int n, int b){
	if(n == 0)
		return 0;
	return (n%b + 10*convert_to_base(n/b, b));
}


// iterative approach : more lines a bit hard
string convert_to_base_iterative(int n, int b){
	string num = "";
	if(n == 0)
		return 0;
	while(n>0){
		num = char(n%b + '0') + num;
		n /= b;
	}
	//returning num directly instead of integer bcz of int overflow
	return num;
}

int main(){
	int n; //decimal value
	int b; //base 
	cin>>n>>b;
	cout<<convert_to_base_iterative(n, b)<<endl;
	return 0;
}