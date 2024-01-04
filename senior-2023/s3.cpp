// Weird Implementation Problem
// You need to consider a couple different cases to solve this
// The special case is when R==row && C!=col or C==col && R!=row 
// If you make mistakes in the implemention process, it may take a while to debug (speaking from experience T-T)


#include <bits/stdc++.h>
#define ll long long
 
using namespace std;

void solve() {
  int row, col, R, C;
  cin >> row >> col >> R >> C;

  char ans[row][col];
  for (int i=0; i<row; ++i) {
    for (int j=0; j<col; ++j) {
      ans[i][j]='a';
    }
  }

  if (R==0 && C==0) {
    ans[0][col-1]='b';
    for (int i=1; i<row; ++i) {
      ans[i][col-1]='c';
    }
    ans[row-1][0]='d';
    for (int j=0; j<col-1; ++j) {
      ans[row-1][j]='e';
    }
  } else if (row==R && col!=C) {
    int rem=col-C;
    int ones=rem%2 && col%2;
    int twos=rem-ones;
    if (twos%2) {
      cout << "IMPOSSIBLE\n";
      return;
    }
    twos/=2;
    for (int i=0; i<twos; ++i) {
      ans[0][i]='b';
      ans[0][col-i-1]='b';
    }
    if (ones) ans[0][col/2]='b';
  } else if (col==C && row!=R) {
    int rem=row-R;
    int ones=rem%2 && row%2;
    int twos=rem-ones;
    if (twos%2) {
      cout << "IMPOSSIBLE\n";
      return;
    }
    twos/=2;
    for (int i=0; i<twos; ++i) {
      ans[i][0]='b';
      ans[row-i-1][0]='b';
    }
    if (ones) ans[row/2][0]='b';
  } else if (R==0 || C==0) {
    if (R==0) {
      for (int i=0; i<row; ++i) {
        for (int j=0; j<C; ++j) {
          ans[i][j]='a';
        }
        for (int j=C; j<col; ++j) {
          if (i==0) ans[i][j]='c';
          else ans[i][j]='b';
        }
      }
    } else if (C==0) {
      for (int i=0; i<R; ++i) {
        for (int j=0; j<col; ++j) {
          ans[i][j]='a';
        }
      }
      for (int i=R; i<row; ++i) {
        ans[i][0]='b';
        for (int j=1; j<col; ++j) {
          ans[i][j]='c';
        }
      }
    }
  } else if (R<=row && C<=col) {
    for (int i=0; i<R; ++i) {
      for (int j=0; j<col; ++j) {
        ans[i][j]='a';
      }
    }
    for (int i=R; i<row; ++i) {
      for (int j=0; j<C; ++j) {
        ans[i][j]='a';
      }
      for (int j=C; j<col; ++j) {
        ans[i][j]='b';
      }
    }
  }

  for (int i=0; i<row; ++i) {
    for (int j=0; j<col; ++j) {
      cout << ans[i][j];
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

