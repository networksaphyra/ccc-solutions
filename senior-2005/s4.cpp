#include <bits/stdc++.h>
#define ll long long

using namespace std;

void solve() {
  int n;
  cin >> n;

  vector<string> A(n);
  for (int i=0; i<n; ++i) {
    cin >> A[i];
  }

  string root=A[n-1];
  map<string, int> level; // where is the person located in terms of depth of the tree
  level[root]=1;

  int mx=0;
  string prev;
  if (n>1) {
    level[A[0]]=2;
    prev=A[0];
    mx=1;
  }

  for (int i=1; i<n; ++i) {
    if (!level[A[i]]) {
      level[A[i]]=level[prev]+1;
      mx=max(mx, level[A[i]]-1);
    }
    prev=A[i];
  }
  cout << n*10 - mx*20 << "\n";
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int t=1;
  cin >> t;

  while (t--)
    solve();
}
