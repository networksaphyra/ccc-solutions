#include <bits/stdc++.h>
#include <cstdint>
#define ll long long

using namespace std;

void solve() {
  int a, b;
  cin >> a >> b;

  int g=gcd(a, b);
  a/=g, b/=g;
  if (a%b==0) cout << a/b << "\n";
  else if (a>b) {
    cout << a/b << " " << a%b << "/" << b << "\n";
  } else {
    cout << a << "/" << b << "\n";
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int t=1;

  while (t--)
    solve();
}
