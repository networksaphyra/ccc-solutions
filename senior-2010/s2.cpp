#include <bits/stdc++.h>
#define ll long long

using namespace std;

void solve() {
  int n;
  cin >> n;

  map<string, char> mp;
  for (int i=0; i<n; ++i) {
    char c;
    string s;
    cin >> c >> s;
    mp[s]=c;
  }

  string s;
  cin >> s;

  vector<char> ans;
  int l=0, r=0;
  while (r<s.size()) {
    string cur;
    for (int j=l; j<=r; ++j) {
      cur+=s[j];
    }
    if (mp.count(cur)) {
      ans.push_back(mp[cur]);
      l=r+1;
      r=l;
    } else {
      r++;
    }
  }
  for (auto& elem: ans) cout << elem;
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
