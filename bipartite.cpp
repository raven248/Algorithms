#include <iostream>
#include <vector>
#include <queue>

using std::vector;
using std::queue;

bool bfs(vector<vector<int> > &adj, int s, vector<int> &is_black){
  is_black[s] = 0;
  if(adj[s].size() == 0)
    return true;
  queue<int> q;
  q.push(s);
  int x;
  while(q.size() != 0){
    x = q.front();
    q.pop();
    for(int i=0;i<adj[x].size();i++){
      if(is_black[adj[x][i]] == -1){
        is_black[adj[x][i]] = (is_black[x] == 1)?0:1;
        q.push(adj[x][i]);
      }
      else if(is_black[x] == is_black[adj[x][i]])
        return false;
    }
  }
  return true;
}


int bipartite(vector<vector<int> > &adj) {
  //write your code here
  vector<int> is_black(adj.size(), -1);
  //1 means coloured black
  //0 means coloured white
  //-1 means uncoloured
  for(int i=0;i<adj.size();i++){
    if(is_black[i] == -1){
      if(!bfs(adj, i, is_black))
        return 0;
    }
  }
  return 1;
}

int main() {
  int n, m;
  std::cin >> n >> m;
  vector<vector<int> > adj(n, vector<int>());
  for (int i = 0; i < m; i++) {
    int x, y;
    std::cin >> x >> y;
    adj[x - 1].push_back(y - 1);
    adj[y - 1].push_back(x - 1);
  }
  std::cout << bipartite(adj);
}
