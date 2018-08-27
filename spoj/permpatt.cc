#include <bits/stdc++.h>
 
#define mid(a,b) ((a+b)>>1)
 
using namespace std;
 
const int MAXN = 100100;
const int INF = 0x3f3f3f3f;
 
struct st_min {
  int m, a, b;
  st_min *l, *r;
 
  st_min(int a, int b) : a(a), b(b) {
    m = INF;
    if (a == b) l = r = NULL;
    else l = new st_min(a,mid(a,b)), r = new st_min(mid(a,b)+1,b);
  }
 
  int update(int p, int v) {
    if (p < a || b < p) return m;
    if (a == b) m = v;
    else m = min(l->update(p,v), r->update(p,v));
    return m;
  }
 
  int get(int A, int B) {
    if (B < a || b < A) return INF;
    if (A <= a && b <= B) return m;
    return min(l->get(A,B), r->get(A,B));
  }
};
 
struct st_max {
  int m, a, b;
  st_max *l, *r;
 
  st_max(int a, int b) : a(a), b(b) {
    m = 0;
    if (a == b) l = r = NULL;
    else l = new st_max(a,mid(a,b)), r = new st_max(mid(a,b)+1,b);
  }
 
  int update(int p, int v) {
    if (p < a || b < p) return m;
    if (a == b) m = v;
    else m = max(l->update(p,v), r->update(p,v));
    return m;
  }
 
  int get(int A, int B) {
    if (B < a || b < A) return 0;
    if (A <= a && b <= B) return m;
    return max(l->get(A,B), r->get(A,B));
  }
};
 
int n;
int p[MAXN];
int pos[MAXN];
 
int main() {
  int t;
 
  scanf("%d", &t);
  while (t--) {
    scanf("%d", &n);
 
    st_min tmin(1,n);
    st_max tmax(1,n);
    for (int i = 1, v; i <= n; ++i) {
      scanf("%d", &p[i]);
      pos[p[i]] = i;
      tmin.update(i,p[i]);
      tmax.update(i,p[i]);
    }
 
    int x = n, y = n-1;
    bool ok = false;
    for (int i = 0; !ok && i < n-3; ++i) {
      int px = pos[x];
      int py = pos[y];
 
      if (px < py) {
        tmin.update(px, INF);
        tmax.update(px, 0);
        x = y;
        y = y-1;
      } else if (px == py + 1 ) {
        tmin.update(py, INF);
        tmax.update(py, 0);
        y = y-1;
      } else {
        int m = tmax.get(py+1, px-1);
        //printf("[%d %d] %d %d %d %d\n", py,px,
        //tmin.get(1,py-1), y, m, x);
        if (m < y && tmin.get(1,py-1) < m)
          ok = true;
        else {
          tmin.update(py, INF);
          tmax.update(py, 0);
          y = y-1;
        }
      }
    }
    cout << (ok ? "yes" : "no") << endl;
  }
  return 0;
} 
