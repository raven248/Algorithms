#include <bits/stdc++.h>
using namespace std;

vector<int> max_subarray(vector<int> &A){
    int dp = 0;
    int maxim = 0;
    int end = 0;
    int prev = 0;
    int count = 0;
    for(int i = 0;i<A.size();i++){
        dp = max(0, dp+A[i]);
        if(dp != 0)
            count++;
        else
            count = 0;
        if(dp > maxim){
            prev = count;
            end = i;
            maxim = dp;
        }
        else if(dp == maxim && count > prev){
            prev = count;
            end = i;
        }
    }
    vector<int> result;
    for(int i = end-prev+1;i<end+1;i++)
        result.push_back(A[i]);
    return result;
}

int main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++)
        cin>>arr[i];
    vector<int> result = max_subarray(arr);
    for(int i: result)
        cout<<i<<" ";
    cout<<endl;
    return 0;
}