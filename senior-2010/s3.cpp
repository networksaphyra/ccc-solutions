#include <bits/stdc++.h>
#define ll long long

using namespace std;

ll circular_dist(ll a, ll b) {
  ll dist=abs(a-b);
  return min(dist, 1000000-dist);
}
bool in_range(ll val, set<ll> hoses, ll k) {
  auto first=hoses.lower_bound(val);
  if (first!=hoses.end()) {
    if (circular_dist(*first, val)<=k) return true;
  }
  if (first!=hoses.begin()) {
    auto second=--first;
    if (circular_dist(*second, val)<=k) return true;
  }
  if (circular_dist(*hoses.begin(), val)<=k) return true;
  return false;
}
bool dfs(ll idx, ll rem, set<ll> hoses, ll k, vector<ll>& houses, ll n) {
  // All houses work
  if (idx==n) return true;
  // See if the current index is approachable by any hose
  if (in_range(houses[idx], hoses, k)) return dfs(idx+1, rem, hoses, k, houses, n);
  if (rem==0) return false;
  else {
    hoses.insert((houses[idx]+k)%(ll) 1e6);
    return dfs(idx+1, rem-1, hoses, k, houses, n);
  }
}
void solve() {
  ll n, rem;
  cin >> n;
  vector<ll> A(n);
  for (ll i=0; i<n; ++i) {
    cin >> A[i];
  }
  sort(begin(A), end(A));
  cin >> rem;
  ll l=0, r=1e6;
  ll ans=INT32_MAX;
  while (l<=r) {
    ll mid=(l+r)/2;
    set<ll> hoses;
    set<ll> hoses2;
    hoses.insert((A[0]-mid+1000000) % 1000000);
    hoses2.insert((A[0]+mid) % 1000000);
    bool res=dfs(0, rem-1, hoses, mid, A, n);
    bool res2=dfs(0, rem-1, hoses2, mid, A, n);
    if (res || res2) {
      ans=min(ans, mid);
      r=mid-1;
    } else {
      l=mid+1;
    }
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
