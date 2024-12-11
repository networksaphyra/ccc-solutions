#include <bits/stdc++.h>
#include <cmath>
#define ll long long

using namespace std;

int dfs(int u, int v, vector<int>& memo, vector<vector<int>>& adj) {
  if (u==v) return 1;
  if (memo[u]!=-1) return memo[u];

  int ans=0;
  for (auto& child: adj[u]) {
    ans+=dfs(child, v, memo, adj);
  }
  return memo[u]=ans;
}

void solve() {
  int n;
  cin >> n;
  vector<vector<int>> adj(n);
  vector<int> memo(n, -1);

  while (true) {
    int a, b;
    cin >> a >> b;
    if (a==0 && b==0) break;
    adj[--a].push_back(--b);
  }
  cout << dfs(0, n-1, memo, adj) << "\n";
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int t=1;
  // cin >> t;

  while (t--)
    solve();
}
