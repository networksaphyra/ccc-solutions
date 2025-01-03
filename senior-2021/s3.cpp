#include <bits/stdc++.h>
#define ll long long

using namespace std;

void solve() {
  // Friend i is at p[i], can walk at 1 meter / w[i] seconds, and can hear from d[i] distance
  // first subtask is just brute force.
  // At some optimal position C, moving to the right will produce more and moving to left will produce more
  ll n;
  cin >> n;

  vector<vector<ll>> A(n, vector<ll>(3, 0));
  for (ll i=0; i<n; ++i) {
    for (ll j=0; j<3; ++j) cin >> A[i][j];
  }

  auto res=[&](ll c) {
    ll ans=0;
    for (ll i=0; i<n; ++i) {
      ll dist=abs(c-A[i][0]);
      dist=max(0LL, dist-A[i][2]);
      ans+=dist * A[i][1];
    }
    return ans;
  };

  ll l=0, r=1e9+1;
  ll ans=0;
  while (l<=r) {
    ll c=(l+r)/2;
    ll cur_cost=res(c);
    // Look at both sides and see which way we should go
    ll left=res(c-1), right=res(c+1);
    if (cur_cost<=left && cur_cost<=right) {
      ans=cur_cost;
      break;
    } else if (left<right) r=c-1;
    else l=c+1;
  }
  cout << ans << "\n";
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  ll t=1;
  // cin >> t;

  while (t--)
    solve();
}
