#include <bits/stdc++.h>
#define ll long long

using namespace std;

int row, col;
char A[110][110];
int dp[110][110][3];

// state: 0, can go up or down
// state: 1, can go up only
// state: 2, can go down only

int dfs(int cur_row, int cur_col, int state) {
  if (cur_row<0 || cur_col<0 || cur_row>=row || cur_col>=col || A[cur_row][cur_col]=='*') return INT32_MIN;
  if (cur_row==row-1 && cur_col==col-1) return (A[cur_row][cur_col]!='.' ? A[cur_row][cur_col]-'0': 0);
  if (dp[cur_row][cur_col][state]!=-1) return dp[cur_row][cur_col][state];

  int current_coin=(A[cur_row][cur_col]!='.' ? A[cur_row][cur_col]-'0': 0);
  int mx=INT32_MIN;

  int first=dfs(cur_row, cur_col+1, 0) + current_coin, second=INT32_MIN, third=INT32_MIN;
  if (state==0) {
    second=dfs(cur_row-1, cur_col, 1) + current_coin;
    third=dfs(cur_row+1, cur_col, 2) + current_coin;
  } else if (state==1) {
    second=dfs(cur_row-1, cur_col, 1) + current_coin;
  } else {
    third=dfs(cur_row+1, cur_col, 2) + current_coin;
  }
  mx=max({first, second, third});
  return dp[cur_row][cur_col][state]=mx;
}

void solve() {
  while (true) {
    cin >> row >> col;
    if (row==0 && col==0) break;

    for (int i=0; i<row; ++i) {
      for (int j=0; j<col; ++j) {
        cin >> A[i][j];
      }
    }
    for (int i=0; i<110; ++i) {
      for (int j=0; j<110; ++j) {
        for (int k=0; k<3; ++k) {
          dp[i][j][k]=-1;
        }
      }
    }
    cout << dfs(row-1, 0, 0) << "\n";
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
