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

#define myrand(minimum) (minimum + rand() % 0xffff)

#define max(x, y) (x > y ? x : y)

struct Treap {

  struct Node {
    int h, size, pri;
    int maxh;
    Node *l, *r;

    Node (int h, int size=1, int pri=rand()) : h(h), size(size), pri(pri) {
      l = r = NULL;
      maxh = h;
    }

    void update() {
      maxh = h;
      size = 1;
      if (l != NULL) maxh = max(maxh, l->maxh), size += l->size;
      if (r != NULL) maxh = max(maxh, r->maxh), size += r->size;
    }
  };

  typedef Node* pNode;



  pNode tree;

  Treap(int n=0, int *v=NULL) : tree(NULL) {
    if (n > 0) build(tree, v, 0, n-1);
  }

  void build(pNode &t, int v[], int a, int b, int minpri=0) {
    if (a>b) return;

    int m = (a+b)/2;
    t = new Node(v[m], (b-a+1), myrand(minpri));
    build(t->l, v,   a, m-1, t->pri + 1);
    build(t->r, v, m+1, b, t->pri + 1);
    t->update();
  }

  void rotateR(pNode &t) {
    pNode aux = t->l;
    t->l = aux->r;
    aux->r = t;
    t = aux;
    t->r->update();
    t->update();
  }

  void rotateL(pNode &t) {
    pNode aux = t->r;
    t->r = aux->l;
    aux->l = t;
    t = aux;
    t->l->update();
    t->update();
  }

  void insert(int h, int p) { insert(h, p, tree); }

  void insert(int h, int p, pNode &t) {
    if (t == NULL) t = new Node(h);
    else {
      if (lsize(t) <= p) {
        insert(h, p - lsize(t), t->r);
        if (t->pri > t->r->pri) rotateL(t);
      } else {
        insert(h, p, t->l);
        if (t->pri > t->l->pri) rotateR(t);
      }
    }
    t->update();
  }

  int geth(int p) { return geth(p, tree); }

  int lsize(pNode &t) {
    return t == NULL ? 0 : 1 + (t->l == NULL ? 0 : t->l->size);
  }

  int geth(int p, pNode &t) {
    if (p <= 0 || t == NULL) return 0;
    int x = lsize(t);
    if (x < p) return geth(p-x, t->r);
    if (x == p) return t->h;
    return geth(p, t->l);
  }

  int get(int p, int H) {
    return get(p, H, tree);
  }

  int get(int p, int H, pNode &t) {
    if (p <= 0 || t == NULL || t->maxh <= H) return 0;
    int x = lsize(t);
    int idx = get(p - x, H, t->r);
    if (idx) return x + idx;
    if (t->h > H && x <= p) return x;
    return get(p, H, t->l);
  }
};

const int MAXN = 6 * 100100;

int N;
int A[MAXN];
int Q;
int T, I, X;

void p(Treap &t) {
  for (int i = 1; i <= 3*N; ++i) cout << t.geth(i) << " ";
  cout << endl;
}

int main() {
  srand(time(NULL));

  scanf("%d", &N);
  for (int i = 0; i < N; ++i) scanf("%d", &A[i]);

  Treap t(N, A);

  scanf("%d", &Q);
  while (Q--) {
    scanf("%d %d %d", &T, &I, &X);
    if (T == 0) {
      t.insert(X, I);
    } else {
      int H = t.geth(I) + X;
      printf("%d\n", t.get(I, H));
    }
  }
  return 0;
}
