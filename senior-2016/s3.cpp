#include <bits/stdc++.h>
#define ll long long

using namespace std;

pair<int, int> dfs(int u, int p, int cur, vector<vector<int>>& adj, set<int>& bad) {
  pair<int, int> best={cur, u};
  for (auto& v: adj[u]) {
    if (v==p || bad.count(v)) continue;
    pair<int, int> res=dfs(v, u, cur+1, adj, bad);
    if (res.first>best.first) {
      best=res;
    }
  }
  return best;
}

void find_parent(int u, int p, vector<vector<int>>& adj, vector<int>& parent) {
  parent[u]=p;
  for (auto& v: adj[u]) {
    if (v!=p || parent[v]==INT32_MAX) find_parent(v, u, adj, parent);
  }
}

void update_bad(int u, set<int>& bad, vector<int>& parent) {
  bad.erase(u);
  if (parent[u]==u || bad.count(parent[u])==0) return;
  update_bad(parent[u], bad, parent);
}

void solve() {
  int n, m;
  cin >> n >> m;

  vector<int> targets(m);
  for (int i=0; i<m; ++i) cin >> targets[i];

  vector<vector<int>> adj(n);
  set<int> bad; bad.insert(n-1);
  for (int i=0; i<n-1; ++i) {
    int a, b;
    cin >> a >> b;
    adj[a].push_back(b);
    adj[b].push_back(a);
    bad.insert(i);
  }
  int root=targets[0];
  vector<int> parent(n, INT32_MAX);
  find_parent(root, root, adj, parent);

  for (int i=0; i<m; ++i) {
    update_bad(targets[i], bad, parent);
  }
  // Everything in bad is not part of the tree
  int good=n-bad.size();
  pair<int, int> first_dfs=dfs(root, root, 0, adj, bad);
  pair<int, int> second_dfs=dfs(first_dfs.second, first_dfs.second, 0, adj, bad);
  cout << 2*(good-1)-second_dfs.first << "\n";
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int t=1;
  // cin >> t;

  while (t--)
    solve();
}
