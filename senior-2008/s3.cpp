#include <bits/stdc++.h>
#define ll long long

using namespace std;

void solve() {
  int row, col;
  cin >> row >> col;
  vector<string> A(row);

  for (int i=0; i<row; ++i) {
    cin >> A[i];
  }

  vector<vector<int>> dist(row, vector<int>(col, INT_MAX));
  vector<pair<int, int>> dirs={{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
  set<pair<int, int>> visited;
  queue<pair<int, int>> bfs;

  bfs.push({0, 0});
  dist[0][0]=1;

  auto in_bound=[&](pair<int, int> a) {
    return !(a.first<0 || a.second<0 || a.first>=row || a.second>=col);
  };

  while (!bfs.empty()) {
    pair<int, int> cur=bfs.front();
    bfs.pop();

    if (cur.first==row-1 && cur.second==col-1) {
      cout << dist[cur.first][cur.second] << "\n";
      return;
    }

    if (A[cur.first][cur.second]=='+') {
      for (int i=0; i<4; ++i) {
        int new_row=cur.first+dirs[i].first;
        int new_col=cur.second+dirs[i].second;
        if (in_bound({new_row, new_col}) && A[new_row][new_col]!='*' && dist[new_row][new_col]==INT32_MAX) {
          bfs.push({new_row, new_col});
          dist[new_row][new_col]=dist[cur.first][cur.second]+1;
        }
      }
    }
    if (A[cur.first][cur.second]=='-') {
      for (int i=2; i<4; ++i) {
        int new_row=cur.first+dirs[i].first;
        int new_col=cur.second+dirs[i].second;
        if (in_bound({new_row, new_col}) && A[new_row][new_col]!='*' && dist[new_row][new_col]==INT32_MAX) {
          bfs.push({new_row, new_col});
          dist[new_row][new_col]=dist[cur.first][cur.second]+1;
        }
      }
    }
    if (A[cur.first][cur.second]=='|') {
      for (int i=0; i<2; ++i) {
        int new_row=cur.first+dirs[i].first;
        int new_col=cur.second+dirs[i].second;
        if (in_bound({new_row, new_col}) && A[new_row][new_col]!='*' && dist[new_row][new_col]==INT32_MAX) {
          bfs.push({new_row, new_col});
          dist[new_row][new_col]=dist[cur.first][cur.second]+1;
        }
      }
    }
  }

  cout << -1 << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t=1;
    cin >> t;

    while (t--)
      solve();
}
