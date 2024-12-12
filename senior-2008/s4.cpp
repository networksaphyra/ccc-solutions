#include <algorithm>
#include <bits/stdc++.h>
#define ll long long

using namespace std;

ll f(ll a, ll b, ll type) {
  if (type==0) return a+b;
  if (type==1) return a-b;
  if (type==2) return a*b;
  if (type==3) {
    if (b==0) return INT32_MAX;
    if (a%b==0) return a/b;
    return INT32_MAX;
  }
}

void solve() {
  vector<ll> A(4);
  for (ll i=0; i<4; ++i) {
    cin >> A[i];
  }
  sort(begin(A), end(A));

  ll ans=-1;
  do {
    ll a=A[0], b=A[1], c=A[2], d=A[3];
    // cout << a << " " << b << ' ' << c << " " << d << "\n";
    for (ll i=0; i<4; ++i) {
      for (ll j=0; j<4; ++j) {
        for (int k=0; k<4; ++k) {
          ll first=f(a, b, i);
          ll second=f(c, d, j);
          if (first==INT32_MAX || second==INT32_MAX) continue;
          ll cur=f(first, second, k);
          if (cur>=0 && cur<=24) ans=max(cur, ans);
          for (int l=0; l<4; ++l) {
            ll second=f(first, c, k);
            ll third=f(second, d, l);
            if (second==INT32_MAX || third==INT32_MAX) continue;
            if (third>=0 && third<=24) ans=max(ans, third);
          }
        }
      }
    }
  } while (next_permutation(begin(A), end(A)));
  cout << ans << "\n";
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  ll t=1;
  cin >> t;

  while (t--)
    solve();
}
