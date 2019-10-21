#include <algorithm>
#include <iostream>
#include <iomanip>
#include <cassert>
#include <vector>
#include <cmath>
using namespace std;
using std::vector;
using std::pair;

int get_parent(vector<int> &parent, int i){
  if(parent[i] == -1)
    return i;
  else
    parent[i] = get_parent(parent, parent[i]);
  return parent[i];
}

double distance(int x1, int y1, int x2, int y2){
  return pow(pow(x1-x2, 2)+pow(y1-y2, 2), 0.5);
}

double clustering(vector<int> x, vector<int> y, int k) {
  //write your code here
  int n = x.size(); //number of disjoint sets
  vector<int> parent(n, -1);
  //build the distances first
  vector<pair<double, pair<int, int>>> cost;
  int i,j;
  for(i=0;i<n;i++)
    for(j=i+1;j<n;j++)
      cost.push_back(make_pair(distance(x[i], y[i], x[j], y[j]), make_pair(i, j)));
  sort(cost.begin(), cost.end()); //O(ElogE)
  for(i=0;i<cost.size();i++){
    int p1 = get_parent(parent, cost[i].second.first);
    int p2 = get_parent(parent, cost[i].second.second);
    if(p1 == p2) continue;
    if(n == k) return cost[i].first;
    if(p1 > p2) swap(p1, p2);
    parent[p2] = p1;
    n--; 
  }
  return cost[0].first;
} 

int main() {
  size_t n;
  int k;
  std::cin >> n;
  vector<int> x(n), y(n);
  for (size_t i = 0; i < n; i++) {
    std::cin >> x[i] >> y[i];
  }
  std::cin >> k;
  std::cout << std::setprecision(10) << clustering(x, y, k) << std::endl;
}
