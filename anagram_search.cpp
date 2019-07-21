#include<bits/stdc++.h>
using namespace std;


bool compare(const int arr1[], const int arr2[]){
	for(int i=0;i<256;i++)
		if(arr1[i] != arr2[i])
			return false;
	return true;
}

void print(int arr[]){
	for(int i=0;i<256;i++)
		cout<<arr[i]<<" ";
	cout<<endl;
}

vector<int> search_anagrams(string &text, string &pat, int countP[], int countT[]){
	vector<int> result;
	if(compare(countP, countT))
		result.push_back(0);
	const int l = pat.size();
	const int n = text.size();
	for(int i=l;i<n;i++){
		countT[text[i]]++;
		countT[text[i-l]]--;
		if(compare(countP, countT))
			result.push_back(i-l+1);
	}
	return result;
}


int main(){

	// 1) Input:  txt[] = "BACDGABCDA"  pat[] = "ABCD"
	//   Output:   Found at Index 0
	//             Found at Index 5
	//             Found at Index 6
	// 2) Input: txt[] =  "AAABABAA" pat[] = "AABA"
	//   Output:   Found at Index 0
	//             Found at Index 1
	//             Found at Index 4
	string text;
	string pat;
	cin>>text>>pat;
	int countP[256] = {0};
	int countT[256] = {0};
	//assuming pattern size <= text size
	for(int i=0;i<pat.size();i++){
		countP[pat[i]]++;
		countT[text[i]]++;
	}
	vector<int> result = search_anagrams(text, pat, countP, countT);
	for(int i:result)
		cout<<"Found pattern at index: "<<i<<endl;
	return 0;
}