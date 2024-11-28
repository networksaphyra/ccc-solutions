#include <bits/stdc++.h>
#define ll long long

using namespace std;

void solve() {
  int row, col, n;
  cin >> row >> col;

  vector<string> A(row);
  for (int i=0; i<row; ++i) {
    cin >> A[i];
  }

  auto ok=[&](pair<int, int> p) {
    return p.first>=0 && p.second>=0 && p.first<row && p.second<col;
  };

  vector<pair<int, int>> dirs={{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
  set<pair<pair<int, int>, int>> coords;
  for (int i=0; i<row; ++i) {
    for (int j=0; j<col; ++j) {
      if (A[i][j]=='X') continue;
      for (int k=0; k<4; ++k) coords.insert({{i, j}, k});
    }
  }

  cin >> n;
  vector<char> moves(n);
  for (int i=0; i<n; ++i) {
    cin >> moves[i];
  }

  vector<char> actual;
  for (int i=0; i<n; ++i) {
    if (actual.size() && actual.back()!=moves[i] && actual.back()!='F' && moves[i]!='F') actual.pop_back();
    else actual.push_back(moves[i]);
  }

  for (int q=0; q<actual.size(); ++q) {
    char c=actual[q];

    set<pair<pair<int, int>, int>> tmp;
    for (auto& elem: coords) {
      pair<int, int> coord=elem.first;
      int dir=elem.second;

      if (c=='R') dir=(dir+1)%4;
      else if (c=='L') dir=(dir-1+4)%4;
      else {
        coord.first+=dirs[dir].first;
        coord.second+=dirs[dir].second;
        if (ok(coord)==false || A[coord.first][coord.second]=='X') continue;
      }
      tmp.insert({coord, dir});
    }
    coords=tmp;
  }

  for (auto& elem: coords) {
    A[elem.first.first][elem.first.second]='*';
  }

  for (int i=0; i<row; ++i) {
    for (int j=0; j<col; ++j) {
      cout << A[i][j];
    }
    cout << "\n";
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
