#include <iostream>
#include <vector>

using std::vector;
using std::min;

int negative_cycle(vector<vector<int> > &adj, vector<vector<int> > &cost) {
  //write your code here
  vector<int> dist(adj.size(), 10000);
  dist[0] = 0;
  int v = adj.size()-1;
  while(v--){
    for(int i=0;i<adj.size();i++){
      for(int j=0;j<adj[i].size();j++){
        if(cost[i][j] < 0) 
          dist[adj[i][j]] = min(dist[i] + cost[i][j], dist[adj[i][j]]);
        else if(dist[i] != 10000)
          dist[adj[i][j]] = min(dist[i] + cost[i][j], dist[adj[i][j]]);
      }
    }
  }
  for(int i=0;i<adj.size();i++)
    for(int j=0;j<adj[i].size();j++)
      if(dist[adj[i][j]] > dist[i] + cost[i][j])
        return 1;
  return 0;
}

int main() {
  int n, m;
  std::cin >> n >> m;
  vector<vector<int> > adj(n, vector<int>());
  vector<vector<int> > cost(n, vector<int>());
  for (int i = 0; i < m; i++) {
    int x, y, w;
    std::cin >> x >> y >> w;
    adj[x - 1].push_back(y - 1);
    cost[x - 1].push_back(w);
  }
  std::cout << negative_cycle(adj, cost);
}
