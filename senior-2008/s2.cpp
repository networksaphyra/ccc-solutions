#include <bits/stdc++.h>
#include <cstdint>
#define ll long long

using namespace std;

void solve() {
  while (true) {
    int r;
    cin >> r;
    if (r==0) break;

    int ans=0;
    for (int i=0; i<=r; ++i) {
      int pos=floor(sqrt(r*r - i*i)) * 2;
      ans+=pos;
    }
    cout << ans * 2 + 1 << "\n";
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
