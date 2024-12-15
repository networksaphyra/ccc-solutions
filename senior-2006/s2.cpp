#include <bits/stdc++.h>
#define ll long long

using namespace std;

void solve() {
  string s, t, u;
  getline(cin, s);
  getline(cin, t);
  getline(cin, u);

  map<char, char> mp;
  set<char> not_seen;

  for (char d='A'; d<='Z'; ++d) not_seen.insert(d);
  not_seen.insert(' ');

  for (int i=0; i<(int) s.size(); ++i) {
    mp[t[i]]=s[i];
    not_seen.erase(s[i]);
  }

  char missing='1';
  if (not_seen.size()==1) missing=*not_seen.begin();

  for (int i=0; i<(int) u.size(); ++i) {
    if (mp.count(u[i])) cout << mp[u[i]];
    else {
      if (missing!='1') cout << missing;
      else cout << '.';
    }
  }
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
