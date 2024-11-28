#include <bits/stdc++.h>
#define ll long long

using namespace std;

struct State {
  int total_count;
  deque<vector<string> > groups;
};

map<int, State> memo;
State dfs(int idx, vector<pair<string, int> > &A, int n, int m) {
  if (idx==n) return {0, {}};
  else if (memo.count(idx)) return memo[idx];
  else {
    State best_state;
    int mn=INT32_MAX;
    int mx=0;

    vector<string> cur;
    for (int i=0; i<m && i+idx<n; ++i) {
      mx=max(mx, A[i+idx].second);
      cur.push_back(A[i+idx].first);

      State next_state=dfs(i+idx+1, A, n, m);
      int total_time=mx+next_state.total_count;
      if (total_time<mn) {
        mn=min(mn, total_time);
        best_state=next_state;
        best_state.total_count=total_time;
        best_state.groups.push_front(cur);
      }
    }
    memo[idx]=best_state;
    return memo[idx];
  }
}

void solve() {
  int n, m;
  cin >> m >> n;

  vector<pair<string, int> > A(n);
  for (int i=0; i<n; ++i) {
    cin >> A[i].first >> A[i].second;
  }

  State state=dfs(0, A, n, m);

  cout << "Total Time: " << state.total_count << "\n";
  for (int i=0; i<state.groups.size(); ++i) {
    for (int j=0; j<state.groups[i].size(); ++j) {
      cout << state.groups[i][j] << " ";
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
