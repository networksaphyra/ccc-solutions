#include <bits/stdc++.h>
#include <cstdint>
#define ll long long

using namespace std;

void solve() {
  int a, b, c, d, n;
  cin >> a >> b >> c >> d >> n;

  int mn=INT32_MAX;
  int cnt=0;
  for (int i=0; i<=n/a; ++i) {
    for (int j=0; j<=n/b; ++j) {
      for (int k=0; k<=n/c; ++k) {
        for (int l=0; l<=n/d; ++l) {
          int sum=i*a+j*b+k*c+l*d;
          if (sum==n) {
            cout << "# of PINK is " << i <<  " # of GREEN is " << j << " # of RED is " << k << " # of ORANGE is " << l << "\n";
            mn=min(mn, i+j+k+l);
            cnt++;
          }
        }
      }
    }
  }
  cout << "Total combinations is " << cnt << ".\n";
  cout << "Minimum number of tickets to print is " << mn << ".\n";
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int t=1;

  while (t--)
    solve();
}
