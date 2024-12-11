#include <bits/stdc++.h>
#include <cstdint>
#define ll long long

using namespace std;

void solve() {
  int n, m;
  cin >> n;

  vector<vector<int>> A(n, vector<int>(3));
  for (int i=0; i<n; ++i) {
    cin >> A[i][0] >> A[i][1] >> A[i][2];
  }
  cin >> m;
  vector<vector<int>> B(m, vector<int>(3));
  for (int i=0; i<m; ++i) {
    cin >> B[i][0] >> B[i][1] >> B[i][2];
  }

  for (int i=0; i<n; ++i) {
    sort(begin(A[i]), end(A[i]));
  }
  for (int i=0; i<m; ++i) {
    sort(begin(B[i]), end(B[i]));
  }
  vector<int> volume(n);
  for (int i=0; i<n; ++i) volume[i]=A[i][0]*A[i][1]*A[i][2];

  for (int i=0; i<m; ++i) {
    int mn=INT32_MAX;
    for (int j=0; j<n; ++j) {
      bool ok=true;
      for (int k=0; k<3; ++k) {
        if (A[j][k]<B[i][k]) ok=false;
      }
      if (ok) mn=min(mn, volume[j]);
    }
    if (mn==INT32_MAX) cout << "Item does not fit.\n";
    else cout << mn << "\n";
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
