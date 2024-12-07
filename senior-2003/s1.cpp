#include <bits/stdc++.h>
#define ll long long

using namespace std;

void solve() {
  map<int, int> mp;
  mp[99]=77;
  mp[67]=86;
  mp[90]=48;
  mp[40]=64;
  mp[9]=34;
  mp[54]=19;

  int cur=1;
  while (true) {
    int n;
    cin >> n;
    if (n==0) {
      cout << "You Quit!";
      return;
    }
    cur+=(cur+n>100?0:n);
    if (mp.count(cur)) cur=mp[cur];
    cout << "You are now on square " << cur << "\n";
    if (cur==100) {
      cout << "You Win!";
      return;
    }
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
