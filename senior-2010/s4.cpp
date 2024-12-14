#include <bits/stdc++.h>
#define ll long long

using namespace std;

vector<int> parent;

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
  parent.resize(n, 0);
  for (int i=0; i<n; ++i) {
    parent[i]=i;
  }
}

bool same(int u, int v) {
  return find(u)==find(v);
}

void solve() {
  int n;
  cin >> n;
  vector<vector<int>> picked(1001, vector<int>(1001, 0));
  vector<vector<pair<int, int>>> A(1001, vector<pair<int, int>>(1001));
  vector<pair<int, pair<int, int>>> edge_list;

  for (int i=0; i<n; ++i) {
    int m;
    cin >> m;
    vector<int> order(m), weights(m);
    for (int j=0; j<m; ++j) cin >> order[j];
    for (int j=0; j<m; ++j) cin >> weights[j];

    for (int j=0; j<m; ++j) {
      int first=order[j];
      int second=order[(j+1)%m];

      if (first>second) swap(first, second);
      picked[first][second]++;

      if (picked[first][second]==1) {
        A[first][second]={i, weights[j]};
      } else {
        edge_list.push_back({weights[j], {A[first][second].first, i}});
      }
    }
  }

  init(n+110);
  sort(begin(edge_list), end(edge_list));

  int ans=0;
  for (int i=0; i<edge_list.size(); ++i) {
    int first=edge_list[i].second.first;
    int second=edge_list[i].second.second;
    if (same(first, second)) continue;
    unite(first, second);
    ans+=edge_list[i].first;
  }

  for (int i=0; i<1001; ++i) {
    for (int j=0; j<1001; ++j) {
      if (picked[i][j]!=1) continue;
      edge_list.push_back({A[i][j].second, {A[i][j].first, n}});
    }
  }

  sort(begin(edge_list), end(edge_list));
  init(n+10);

  int ans2=0;
  for (int i=0; i<edge_list.size(); ++i) {
    int first=edge_list[i].second.first;
    int second=edge_list[i].second.second;

    if (same(first, second)) continue;
    unite(first, second);

    ans2+=edge_list[i].first;
  }
  cout << min(ans, ans2) << "\n";
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int t=1;
  // cin >> t;
  //
  while (t--)
    solve();
}
