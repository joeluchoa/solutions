#include <bits/stdc++.h>

using namespace std;

#define rep(i,n) for (int i=0; i<(n); ++i)
#define all(x) x.begin(),x.end()
#define dbg(x) cerr << #x << " = " << x << endl
#define sz(x) (int)(x.size())
#define ms(m,v) memset((m), (v), sizeof (m))
#define mp make_pair
#define pb push_back
#define endl "\n"


int n, m;
int xe, xs, ye, ys;
bool vis[6][6];

int di[] = {0,1,0,-1};
int dj[] = {1,0,-1,0};

bool valido(int i, int j) {
  return (0 <= i && i < n) && (0 <= j && j < m) && !vis[i][j];
}

int dfs(int i, int j) {
  if (i == ye && j == ys) return 0;
  vis[i][j] = true;
  int res = 0;
  for (int k = 0; k < 4; ++k) {
    int ii = i + di[k], jj = j + dj[k];
    if (valido(ii,jj)) res = max(res, dfs(ii,jj) + 1);
  }
  vis[i][j] = false;
  return res;
}


int main() {
  std::ios::sync_with_stdio(false); cin.tie(0);

  cin >> n >> m;
  cin >> xe >> xs;
  cin >> ye >> ys;

  n = (n+1)/2; m = (m+1)/2;
  xe /= 2; xs /= 2;
  ye /= 2; ys /= 2;

  ms(vis, false);
  cout << dfs(xe, xs) * 2 + 1 << endl;

  return 0;
}
