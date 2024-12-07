#include <bits/stdc++.h>
#define ll long long

using namespace std;

void dfs(int u, int weight, vector<bool>& vis, vector<vector<pair<int, int>>>& adj) {
  vis[u]=true;
  for (int i=0; i<adj[u].size(); ++i) {
    if (adj[u][i].second>=weight && vis[adj[u][i].first]==false) {
      dfs(adj[u][i].first, weight, vis, adj);
    }
  }
}

void solve() {
  int nodes, edges, cities;
  cin >> nodes >> edges >> cities;

  vector<vector<pair<int, int>>> adj(nodes);
  vector<int> weights, A;

  set<int> seen;
  for (int i=0; i<edges; ++i) {
    int a, b, w;
    cin >> a >> b >> w;
    --a, --b;
    adj[a].push_back({b, w});
    adj[b].push_back({a, w});
    if (seen.count(w)==0) {
      weights.push_back(w);
      seen.insert(w);
    }
  }
  for (int i=0; i<cities; ++i) {
    int city;
    cin >> city;
    A.push_back(--city);
  }
  sort(begin(weights), end(weights));

  int l=0, r=weights.size()-1;
  int ans=weights[0];

  while (l<=r) {
    int mid=(l+r)/2;
    bool ok=true;
    vector<bool> vis(nodes, false);
    dfs(0, weights[mid], vis, adj);
    for (int i=0; i<A.size(); ++i) {
      if (vis[A[i]]==false) {
        ok=false;
        break;
      }
    }
    if (ok) {
      l=mid+1;
      ans=weights[mid];
    } else {
      r=mid-1;
    }
  }
  cout << ans << "\n";
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int t=1;
  // cin >> t;

  while (t--)
    solve();
}
