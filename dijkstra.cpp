#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// using std::vector;
// using std::queue;
// using std::pair;
// using std::priority_queue;
// using std::make_pair;

// class myComparator 
// { 
// public: 
//     int operator() (const pair<int, int> &p1, const pair<int, int> &p2) 
//     { 
//         return p1.first < p2.first; 
//     } 
// };


int distance(vector<vector<int> > &adj, vector<vector<int> > &cost, int s, int t) {
  //write your code here
  priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > q;
  vector<int> dist(adj.size(), 100000);
  dist[s] = 0; 

  for(int i=0;i<adj.size();i++)
    q.push(make_pair(dist[i], i));
  pair<int, int> x;
  while(!q.empty()){
    x = q.top();
    q.pop();
    // std::cout<<x.first<<'\n';
    for(int i=0;i<adj[x.second].size();i++){
      // cout<<dist[adj[x.second][i]]<<" "<<x.first<<" "<<cost[x.second][adj[x.second][i]]<<endl;
      if(dist[adj[x.second][i]] > x.first + cost[x.second][i]){
        dist[adj[x.second][i]] = x.first + cost[x.second][i];
        q.push(make_pair(dist[adj[x.second][i]], adj[x.second][i]));
      }
    }
  }
  return (dist[t] != 100000)?dist[t]:-1;
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
  int s, t;
  std::cin >> s >> t;
  s--, t--;
  std::cout << distance(adj, cost, s, t);
}
