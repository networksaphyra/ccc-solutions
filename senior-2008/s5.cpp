#include <bits/stdc++.h>
#define ll long long

using namespace std;

vector<vector<int>> B = {
  {2, 1, 0, 2},
  {1, 1, 1, 1},
  {0, 0, 2, 1},
  {0, 3, 0, 0},
  {1, 0, 0, 1}
};

bool can_move(vector<int>& A, vector<int>& B) {
  for (int i=0; i<4; ++i) {
    if (A[i]<B[i]) return false;
  }
  return true;
}

int dp[31][31][31][31];

bool dfs(vector<int> A) {
  // Cannot go into a position if you are unable to
  // Case where current player loses
  if (dp[A[0]][A[1]][A[2]][A[3]]!=-1) return dp[A[0]][A[1]][A[2]][A[3]];

  bool can=false;
  for (int i=0; i<5; ++i) {
    can=can|can_move(A, B[i]);
  }
  if (can==false) return false;

  bool winning=false;
  for (int i=0; i<5; ++i) {
    if (can_move(A, B[i])==false) continue;
    vector<int> C=A;
    for (int j=0; j<4; ++j) C[j]-=B[i][j];
    if (dfs(C)==false) {
      winning=true;
      break;
    }
  }
  return dp[A[0]][A[1]][A[2]][A[3]]=winning;
}

void solve() {
  vector<int> A(4);
  for (int i=0; i<4; ++i) {
    cin >> A[i];
  }
  if (dfs(A)) {
    cout << "Patrick\n";
  } else {
    cout << "Roland\n";
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  for (int i=0; i<31; ++i) {
    for (int j=0; j<31; ++j) {
      for (int k=0; k<31; ++k) {
        for (int l=0; l<31; ++l) {
          dp[i][j][k][l]=-1;
        }
      }
    }
  }

  int t=1;
  cin >> t;

  while (t--)
    solve();
}
