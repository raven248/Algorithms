#include <iostream>
#include <vector>

using std::vector;
using std::cin;
using std::cout;
using std::swap;

vector<bool>vertices;

int reach(vector< vector<int> > &adj, int x, int y) {
  if(x == y) return 1;
  if(adj[x].size() == 0) return 0;
  for(int i=0;i<adj[x].size();i++){
    if(vertices[adj[x][i]]) continue;
    vertices[adj[x][i]] = true;
    if(reach(adj, adj[x][i], y) == 1)
      return 1;
  }
  return 0;
}

int main() {
  size_t n, m;
  cin >> n >> m;
  vector<bool>(n).swap(vertices);
  vector<vector<int> > adj(n, vector<int>());
  for (size_t i = 0; i < m; i++) {
    int x, y;
    cin >> x >> y;
    adj[x - 1].push_back(y - 1);
    adj[y - 1].push_back(x - 1);
  }
  int x, y;
  cin >> x >> y;
  cout << reach(adj, x - 1, y - 1);
}
