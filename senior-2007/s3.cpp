#include <bits/stdc++.h>
#define ll long long

using namespace std;

int dfs(int u, int v, vector<bool>& vis, vector<int>& A, int dist) {
  if (vis[u]) {
    if (vis[v]) return dist-1;
    return -1;
  }
  vis[u]=true;
  return dfs(A[u], v, vis, A, dist+(vis[v] ? 0: 1));
}

void solve() {
  int n;
  cin >> n;

  vector<int> A(n+1, -1);
  for (int i=0; i<n; ++i) {
    int a, b;
    cin >> a >> b;
    A[--a]=--b;
  }

  while (true) {
    int a, b;
    cin >> a >> b;
    if (a==0 && b==0) break;
    --a, --b;
    vector<bool> vis(n+1, false);
    int res=dfs(a, b, vis, A, 0);
    if (res==-1) {
      cout << "No\n";
    } else {
      cout << "Yes " << res << "\n";
    }
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int t=1;
  // cin >> t;

  while (t--)
    solve();
}
