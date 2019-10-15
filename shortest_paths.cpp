#include <iostream>
#include <limits>
#include <vector>
#include <queue>

using std::vector;
using std::queue;
using std::pair;
using std::priority_queue;
using std::cout;
using std::endl;

void dfs(vector<vector<int> > &adj, int s, vector<int> &shortest){
  for(int i=0;i<adj[s].size();i++){
    if(shortest[adj[s][i]] == 0) continue;
    shortest[adj[s][i]] = 0;
    dfs(adj, adj[s][i], shortest);
  }
}

void find_cycle(vector<vector<int> > &adj, vector<int> &cycle, vector<int> &prev, vector<int> &shortest){
  int v = adj.size();
  for(int i=0;i<cycle.size();i++){
    v = adj.size();
    if(shortest[cycle[i]] == 0) continue;
    while(v-- && (prev[cycle[i]] != -1)){
      if(shortest[cycle[i]] == 0) break;
      shortest[cycle[i]] = 0;
      dfs(adj, cycle[i], shortest);
      cycle[i] = prev[cycle[i]];
    }
  }
}

void fill_dist(vector<vector<int> > &adj, int s, vector<int> &reachable, vector<long long> &distance, vector<vector<int> > &cost, vector<int> &prev){
  for(int i=0;i<adj[s].size();i++){
    if(reachable[adj[s][i]] == 1) continue;
    reachable[adj[s][i]] = 1;
    if(distance[adj[s][i]] > distance[s] + cost[s][i]){
      prev[adj[s][i]] = s;
      distance[adj[s][i]] = distance[s] + cost[s][i];
    }
    fill_dist(adj, adj[s][i], reachable, distance, cost, prev);
  }
}

void shortest_paths(vector<vector<int> > &adj, vector<vector<int> > &cost, int s, vector<long long> &distance, vector<int> &reachable, vector<int> &shortest) {
  //write your code here
  int v = adj.size() - 1;
  distance[s] = 0;
  vector<int> prev(adj.size(), -1); //O(n)
  fill_dist(adj, s, reachable, distance, cost, prev); //O(n)
  //reachable is done
  //O(n2)
  while(v--){
    for(int i=0;i<adj.size();i++){
      if(!reachable[i]) continue;
      for(int j=0;j<adj[i].size();j++){
        // if(distance[adj[i][j]] == std::numeric_limits<long long>::max()) continue;
        if(distance[adj[i][j]] > distance[i] + cost[i][j]){
          prev[adj[i][j]] = i;
          distance[adj[i][j]] = distance[i] + cost[i][j];
        }
      }
    }
  }
  //now to find cycles and nodes leading to the cycles.
  vector<int> cycle;
  // O(n)
  for(int i=0;i<adj.size();i++){
    if(!reachable[i]) continue;
    for(int j=0;j<adj[i].size();j++)
      if(distance[adj[i][j]] > distance[i] + cost[i][j])
        cycle.push_back(adj[i][j]);
  }

  shortest[s] = 1;
  reachable[s] = 1;
  find_cycle(adj, cycle, prev, shortest);
  
  // for(int i=0;i<shortest.size();i++)
  //   shortest[i] = (shortest[i] == 1)?0:1;
}

int main() {
  int n, m, s;
  std::cin >> n >> m;
  vector<vector<int> > adj(n, vector<int>());
  vector<vector<int> > cost(n, vector<int>());
  for (int i = 0; i < m; i++) {
    int x, y, w;
    std::cin >> x >> y >> w;
    adj[x - 1].push_back(y - 1);
    cost[x - 1].push_back(w);
  }
  std::cin >> s;
  s--;
  vector<long long> distance(n, std::numeric_limits<long long>::max());
  vector<int> reachable(n, 0);
  vector<int> shortest(n, 1);
  shortest_paths(adj, cost, s, distance, reachable, shortest);
  for (int i = 0; i < n; i++) {
    if (!reachable[i]) {
      std::cout << "*\n";
    } else if (!shortest[i]) {
      std::cout << "-\n";
    } else {
      std::cout << distance[i] << "\n";
    }
  }
}
