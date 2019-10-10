#include <iostream>
#include <vector>

using std::vector;
using std::pair;

vector<bool> visited;

void explore(int x, vector< vector<int> > &adj){
  if(adj[x].size() == 0) return;
  for(int i=0;i<adj[x].size();i++){
    if(visited[adj[x][i]]) continue;
    visited[adj[x][i]] = true;
    explore(adj[x][i], adj);
  }
}

int number_of_components(vector<vector<int> > &adj) {
  int res = 0;
  //write your code here
  for(int i=0;i<adj.size();i++){
    if(visited[i]) continue;
    res++;
    visited[i] = true;
    explore(i, adj);
  }
  return res;
}

int main() {
  size_t n, m;
  std::cin >> n >> m;
  vector<bool>(n, false).swap(visited);
  vector<vector<int> > adj(n, vector<int>());
  for (size_t i = 0; i < m; i++) {
    int x, y;
    std::cin >> x >> y;
    adj[x - 1].push_back(y - 1);
    adj[y - 1].push_back(x - 1);
  }
  std::cout << number_of_components(adj);
}
