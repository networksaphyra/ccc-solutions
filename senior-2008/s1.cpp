#include <bits/stdc++.h>
#include <cmath>
#include <cstdint>
#define ll long long

using namespace std;

void solve() {
  int mn=INT32_MAX;
  string ans;
  while (true) {
    string s;
    int x;
    cin >> s >> x;

    if (x<mn) {
      mn=x;
      ans=s;
    }
    if (s=="Waterloo") break;
  }
  cout << ans << "\n";
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int t=1;
  // cin >> t;

  while (t--)
    solve();
}
