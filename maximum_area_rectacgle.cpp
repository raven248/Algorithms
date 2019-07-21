#include<bits/stdc++.h>
using namespace std;


int get_max_area(vector<int> &heights){
	stack<int> stk;
	if(heights.size() == 0) return -1;
	int i=0;
	int max_area = 0;
	int n = heights.size();
	int area=0, index = 0;
	while(i<n){
		if(stk.empty() || heights[i] > heights[stk.top()]){
			stk.push(i);
			i++;
		}
		else{
			index = stk.top();
			stk.pop();
			if(stk.empty())
				area = heights[index]*(index+1);
			else
				area = heights[index]*(index - stk.top());
			max_area = max(area, max_area);
		}
	}
	while(!stk.empty()){
		index = stk.top();
		stk.pop();
		if(stk.empty())
			area = heights[index]*(n);
		else
			area = heights[index]*(n - stk.top() - 1);
		max_area = max(area, max_area);
	}
	return max_area;
}

int main(){
	int n;
	cin>>n;
	vector<int> heights(n);
	for (int i = 0; i < n; ++i)
		cin>>heights[i];
	int area = get_max_area(heights);
	cout<<area<<endl;
	return 0;
}
