#include <bits/stdc++.h>
#define ll long long

using namespace std;

vector<string> A;
vector<vector<bool> > vis;
int cur=0, row, col;
vector<pair<int, int> > dir={{0, -1}, {-1, 0}, {1, 0}, {0, 1}};

void dfs(int i, int j) {
  if (i<0 || j<0 || j>=col || i>=row || A[i][j]=='I' || vis[i][j]) return;
  vis[i][j]=true;
  cur++;

  for (int idx=0; idx<4; ++idx)
    dfs(i + dir[idx].first, j + dir[idx].second);
}

void solve() {
  int n;
  cin >> n >> row >> col;
  A.resize(row);
  vis.resize(row, vector<bool>(col, false));

  for (int i=0; i<row; ++i) {
    cin >> A[i];
  }

  vector<int> rooms;
  for (int i=0; i<row; ++i) {
    for (int j=0; j<col; ++j) {
      if (A[i][j]!='I' && vis[i][j]==false) {
        dfs(i, j);
        rooms.push_back(cur);
        cur=0;
      }
    }
  }
  sort(rooms.rbegin(), rooms.rend());
  int ans=0;
  for (int i=0; i<rooms.size(); ++i) {
    if (rooms[i]>n) break;
    n-=rooms[i];
    ans++;
  }
  string bad_problem_statement_bruh=(ans==1?"room, ":"rooms, ");
  cout << ans << " " << bad_problem_statement_bruh << n << " square metre(s) left over\n";
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int t=1;
  // cin >> t;

  while (t--)
    solve();
}
