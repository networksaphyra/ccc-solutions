#include <bits/stdc++.h>
#define ll long long

using namespace std;

void solve() {
  int n;
  cin >> n;

  map<char, int> mp;
  mp['A']=2;
  mp['B']=2;
  mp['C']=2;
  mp['D']=3;
  mp['E']=3;
  mp['F']=3;
  mp['G']=4;
  mp['H']=4;
  mp['I']=4;
  mp['J']=5;
  mp['K']=5;
  mp['L']=5;
  mp['M']=6;
  mp['N']=6;
  mp['O']=6;
  mp['P']=7;
  mp['Q']=7;
  mp['R']=7;
  mp['S']=7;
  mp['T']=8;
  mp['U']=8;
  mp['V']=8;
  mp['W']=9;
  mp['X']=9;
  mp['Y']=9;
  mp['Z']=9;


  for (int q=0; q<n; ++q) {
    string s;
    cin >> s;

    string ans;
    int dash=0;
    for (int i=0; i<s.size(); ++i) {
      if (ans.size()==12) break;
      if (s[i]=='-') continue;
      if (mp.count(s[i])) ans+=char(mp[s[i]]+'0');
      else ans+=s[i];

      if (ans.size()<=8 && (ans.size()-dash)%3==0) {
        ans+='-';
        dash++;
      }
    }
    cout << ans << "\n";
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int t=1;

  while (t--)
    solve();
}
