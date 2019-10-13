#include <iostream>
#include <vector>
using namespace std;

vector<bool> visited;
vector<bool> dead;

bool explore(vector< vector<int> > &adj, int x){
  if(visited[x] == true)
    return !dead[x];
  visited[x] = true;
  for(int i=0;i<adj[x].size();i++){
    if(explore(adj, adj[x][i]))
      return true;
  }
  dead[x] = true;
  return false;
}

int acyclic(vector< vector<int> > &adj) {
  //write your code here
  vector<bool>(adj.size()).swap(visited);
  vector<bool>(adj.size()).swap(dead);
  for(int i=0;i<adj.size();i++){
    if(visited[i]) continue;
    if(explore(adj, i))
      return 1;
  }
  return 0;
}

int main() {
  size_t n, m;
  cin >> n >> m;
  vector<vector<int> > adj(n, vector<int>());
  for (size_t i = 0; i < m; i++) {
    int x, y;
    cin >> x >> y;
    adj[x - 1].push_back(y - 1);
  }
  cout << acyclic(adj);
}
