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

const int MAXN = 100100;

struct R {
  int x1, y1, x2, y2;

  bool operator<(const R &other) const {
    return x1 < other.x1;
  }
};

struct SegTree {
  stack<int> cor;
  int A, B;
  SegTree *l, *r;

  SegTree(int a, int b) {
    A = a; B = b;
    if (a != b) {
      int m = (a+b)/2;
      l = new SegTree(A, m);
      r = new SegTree(m+1,B);
    }
  }

  int get(int i) {
    int ret = -1;
    if (i < A || B < i) return ret;
    if (cor.size()) ret = cor.top();
    if (A != B) {
      int x = max(l->get(i), r->get(i));
      if (x>=0) ret = x;
    }
    return ret;
  }

  void push(int a, int b, int c) {
    if (b < A || B < a) return;
    if (a <= A && B <= b) {
      cor.push(c);
    } else {
      l->push(a, b, c);
      r->push(a, b, c);
    }
  }

  void pop(int a, int b) {
    if (b < A || B < a) return;
    if (a <= A && B <= b) {
      cor.pop();
    } else {
      l->pop(a, b);
      r->pop(a, b);
    }
  }

};

struct SweepLine {
  SegTree *st;
  set<pair<int,int> > end;

  SweepLine() {
    st = new SegTree(0,2*MAXN);
  }

  void insert(int y1, int y2, int x2, int idx) {
    st->push(y1, y2, idx);
    end.insert({x2, idx});
  }

  int firstEnded(int x) {
    if (!end.empty() && end.begin()->first < x)
      return end.begin()->second;
    return -1;
  }

  void pop(int y1, int y2) {
    st->pop(y1, y2);
    end.erase(end.begin());
  } 

  int get(int i) {
    return st->get(i);
  }
};

int n;
R r[MAXN];

void compress() {
  int k=0;
  map<int,int> mx, my;

  rep(i, n) mx[r[i].x1] = mx[r[i].x2] = 0;
  rep(i, n) my[r[i].y1] = my[r[i].y2] = 0;

  k = 0;
  for (auto &it : mx) it.second = k++;
  k = 0;
  for (auto &it : my) it.second = k++;

  rep(i, n) r[i].x2 = mx[r[i].x2], r[i].x1 = mx[r[i].x1];
  rep(i, n) r[i].y2 = my[r[i].y2], r[i].y1 = my[r[i].y1];
}

int main() {
  std::ios::sync_with_stdio(false); cin.tie(0);

  cin >> n;
  rep(i, n) cin >> r[i].x1 >> r[i].y2 >> r[i].x2 >> r[i].y1;
  compress();

  sort(r, r + n);

  int sol = n;
  bool leaf[n];
  ms(leaf, true);

  SweepLine sl;
  rep(i, n) {
    int x = r[i].x1;
    int j = -1;
    while ((j = sl.firstEnded(x)) != -1 )
      sl.pop(r[j].y1, r[j].y2);

    j = sl.get(r[i].y1);
    if (j != -1 && leaf[j]) --sol, leaf[j] = false;
    sl.insert(r[i].y1, r[i].y2, r[i].x2, i);
  }

  cout << sol << endl;

  return 0;
}
