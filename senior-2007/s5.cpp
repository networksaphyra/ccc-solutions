#include <bits/stdc++.h>
#define ll long long

using namespace std;

int dfs(int idx, int used, int width, int n, vector<int>& A, vector<int>& pref, vector<vector<int>>& memo) {
  if (idx>n) return INT32_MIN;
  if (memo[idx][used]!=-1) return memo[idx][used];
  if (used==0 || idx==n) return 0;

  int take=dfs(min(idx+width, n), used-1, width, n, A, pref, memo) + (pref[min(idx+width, n)] - pref[idx]);
  int skip=dfs(idx+1, used, width, n, A, pref, memo);

  return memo[idx][used]=max(take, skip);
}

void solve() {
  int n, balls, width;
  cin >> n >> balls >> width;

  vector<int> A(n);
  for (int i=0; i<n; ++i) {
    cin >> A[i];
  }
  vector<int> pref(n+1);
  for (int i=0; i<n; ++i) {
    pref[i+1]=pref[i]+A[i];
  }

  vector<vector<int>> memo(n+10, vector<int>(balls+10, -1));
  cout << dfs(0, balls, width, n, A, pref, memo) << "\n";
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int t=1;
  cin >> t;

  while (t--)
    solve();
}
