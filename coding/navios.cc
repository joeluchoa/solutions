#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;

const int INF = 0x3f3f3f3f;
const int MAXN = 10100;

int n, h, m;
int c[MAXN];
vector<pii> g[MAXN];

int dijkstra() {
  priority_queue<pii> q;
  int dist[MAXN];
  vector<int> origens; 
  int sol = 0;

  origens.push_back(1);

  do {
    fill(dist, dist + n + 1, INF);

    for (auto o : origens) {
      q.push(pii(0, o));
      dist[o] = 0;
    }	

    while (!q.empty()) {
      int v = q.top().second; q.pop();

      if (v == n) return sol;

      for (auto e : g[v]) {
        int u = e.first;
        int cost = dist[v] + e.second;
        if (cost > 600) continue;

        if (dist[u] > cost) {
          dist[u] = cost;
          q.push(pii(-dist[u], u));
        }
      }
    }

    origens.clear();
    for (int i = 0; i < h; ++i) if (c[i] != -1) {
      if (dist[c[i]] != INF) {
        origens.push_back(c[i]);
        c[i] = -1;
      }
    }

    ++sol;
  } while (origens.size() > 0);

  return -1;
}

int main() {
  while ((cin >> n) && n) {
    cin >> h;
    for (int i = 0; i < h; ++i)
      cin >> c[i];

    for (int i = 1; i <= n; ++i)
      g[i].clear();

    cin >> m;
    for (int i = 0, u, v, t; i < m; ++i) {
      cin >> u >> v >> t;
      g[u].push_back(pii(v,t));
      g[v].push_back(pii(u,t));
    }

    cout << dijkstra() << endl;
  }
  return 0;
}
