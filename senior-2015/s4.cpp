#include <bits/stdc++.h>
#include <queue>
#define ll long long

using namespace std;

struct Edge {
  int node, time, hull;

  bool operator>(const Edge& other) const {
    return time > other.time;
  }
};

void solve() {
  int k, n, m;
  cin >> k >> n >> m;

  vector<vector<int>> dist(n, vector<int>(k, INT32_MAX));
  dist[0][0]=0;
  vector<vector<Edge>> adj(n);

  for (int i=0; i<m; ++i) {
    int a, b, time, hull;
    cin >> a >> b >> time >> hull;
    adj[--a].push_back({--b, time, hull});
    adj[b].push_back({a, time, hull});
  }

  int start, end;
  cin >> start >> end;
  --start, --end;

  priority_queue<Edge, vector<Edge>, greater<Edge>> pq;
  pq.push(Edge{start, 0, 0});

  while (pq.size()) {
    Edge cur=pq.top();
    pq.pop();

    for (auto& child: adj[cur.node]) {
      int new_hull=child.hull + cur.hull;
      int new_time=child.time + cur.time;
      if (new_hull >= k || new_time > dist[child.node][new_hull]) continue;
      dist[child.node][new_hull] = new_time;
      pq.push(Edge{child.node, new_time, new_hull});
    }
  }
  int mn=INT32_MAX;
  for (int i=0; i<k; ++i) mn=min(mn, dist[end][i]);
  if (mn==INT32_MAX) cout << -1 << "\n";
  else cout << mn <<  "\n";
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int t=1;
  // cin >> t;

  while (t--)
    solve();
}
