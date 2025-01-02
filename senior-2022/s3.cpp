#include <bits/stdc++.h>
#define ll long long

using namespace std;

void solve() {
  ll n, m, k;
  cin >> n >> m >> k;

  vector<ll> A(n, -1);
  k--;
  A[0]=1;
  for (ll i=1; i<n; ++i) {
    ll rem=n-i-1;
    ll take=min(k-rem, m);

    if (i-take<0) {
      A[i]=i+1;
      k-=A[i];
    } else {
      A[i]=A[i-take];
      k-=take;
    }
  }
  if (k!=0 || A[n-1]==-1) cout << -1;
  else for (auto& elem: A) cout << elem << " ";
  cout << "\n";
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int t=1;
  // cin >> t;

  while (t--)
    solve();
}
