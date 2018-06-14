#include <bits/stdc++.h>

using namespace std;

#define rep(i,n) for (int (i)=0; (i)<(n); ++(i))
#define all(x) (x).begin(),(x).end()
#define dbg(x) cerr << #x << " = " << x << endl
#define sz(x) (int)((x).size())
#define ms(m,v) memset((m), (v), sizeof (m))
#define mp make_pair
#define pb push_back


typedef long long ll;
const int MAXR = 300;

struct B {
  ll s;
  deque<int> a;

  B() { s = 0; }

  void add(int pos, int v) {
    a.insert(a.begin() + pos, v);
    s += v;
  }

  B split() {
    B b; int i = 0; s = 0;
    for (auto it : a) {
      if (++i <= sz(a)/2) s += it;
      else b.a.pb(it), b.s += it;
    }
    a.erase(a.begin()+sz(a)/2,a.end());
    return b;
  }

  ll presum(int pos) {
    deque<int>::iterator it = a.begin();
    ll s = 0;
    while (pos-->=0)
      s += *it, ++it;
    return s;
  }

  ll possum(int pos) {
    pos = a.size() - pos;
    deque<int>::reverse_iterator it = a.rbegin();
    ll s = 0;
    while (pos-->0)
      s += *it, ++it;
    return s;
  }

  ll sum(int a, int b) {
    return presum(b) - presum(a-1);
  }
};

ostream& operator<<(ostream& stream, const B b) {
  stream << "[" << b.s << " :";
  for (auto i : b.a) stream << " " << i;
  stream << "]";
  return stream;
}

struct RMQ {
  deque<B> b;

  RMQ() { b.pb(B()); }

  deque<B>::iterator find(int &pos) {
    deque<B>::iterator it = b.begin();
    while (it != b.end() && sz(it->a) <= pos)
      pos -= sz(it->a), ++it;
    if (it != b.end()) return it;
    pos += sz((b.end()-1)->a);
    return b.end()-1;
  }

  void add(int pos, int v) {
    deque<B>::iterator it = find(pos);
    it->add(pos, v);
    if (it->a.size() >= MAXR * 2) {
      B p = it->split();
      b.insert(it+1, p);
    }
  }

  ll query(int x, int y) {
    deque<B>::iterator a = find(x), b = find(y);
    if (a == b) return a->sum(x,y);
    ll s = a->possum(x) + b->presum(y);
    while (++a != b)
      s += a->s;
    return s;
  }
};

ostream& operator<<(ostream& stream, const RMQ rmq ) {
  for (auto i : rmq.b) stream << i;
  return stream;
}

int main() {
  std::ios::sync_with_stdio(false); cin.tie(0);

  int N;
  cin >> N;

  RMQ rmq;

  int v;
  rep(i,N) cin >> v, rmq.add(i, v);

  int Q;
  for (cin >> Q; Q--; ) {
    char c;
    int x, y;
    cin >> c >> x >> y;
    if (c == 'I') rmq.add(x, y);
    else cout << rmq.query(x-1, y-1) << endl;
  }

  return 0;
}
