#include <bits/stdc++.h>
#define ll long long

using namespace std;

void solve() {
  int n;
  cin >> n;

  vector<int> A(n+1);
  for (int i=1; i<=n; ++i)
    cin >> A[i];
  
  int dp[n+1][n+1];
  for (int i=0; i<=n; ++i) {
    for (int j=0; j<=n; ++j) {
      dp[i][j]=0;
    }
  }

  for (int i=1; i<=n; ++i) {
    int l=1, r=i, ans=1e9;
    while (r<=n) {
      dp[l][r]=dp[l+1][r-1]+abs(A[l]-A[r]);
      ans=min(ans, dp[l][r]);
      l++, r++;
    }
    cout << ans << (i==n?"\n": " ");
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
