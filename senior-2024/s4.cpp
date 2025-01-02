#include <bits/stdc++.h>
#define ll long long

using namespace std;

vector<int> parent;
vector<bool> vis;
map<pair<int,int>, char> ans;

int find(int u) {
  if (parent[u]==u) return u;
  return parent[u]=find(parent[u]);
}

void unite(int u, int v) {
  int first=find(u);
  int second=find(v);
  if (first!=second) parent[second]=first;
}

void init(int n) {
  parent.resize(n);
  for (int i=0; i<n; ++i) {
    parent[i]=i;
  }
}

bool same(int u, int v) {
  return find(u)==find(v);
}

void dfs(int u, char color, vector<vector<int>>& adj) {
  vis[u]=true;
  char next_color=(color=='R'?'B': 'R');
  for (auto child: adj[u]) {
    if (vis[child] || same(u, child)) continue;
    unite(u, child);
    ans[{min(u,child), max(u,child)}] = next_color;
    dfs(child, next_color, adj);
  }
}

void solve() {
  int n, m;
  cin >> n >> m;

  vis.resize(n, false);
  init(n);

  vector<vector<int>> adj(n);
  vector<pair<int, int>> edges;

  for (int i=0; i<m; ++i) {
    int a, b;
    cin >> a >> b;
    --a, --b;
    adj[a].push_back(b);
    adj[b].push_back(a);
    edges.push_back({min(a,b), max(a,b)});
  }

  // Try a greedy approach with union set.
  // If u and v are in the same set, then we should not make a color between them
  for (int i=0; i<n; ++i) {
    if (!vis[i]) {
      dfs(i, 'R', adj);
    }
  }

  for (auto [u,v] : edges) {
    cout << (ans.count({u,v}) ? ans[{u,v}] : 'G');
  }
  cout << "\n";
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  solve();
}
