#include <bits/stdc++.h>

using namespace std;

#define rep(i,n) for (int (i)=0; (i)<(n); ++(i))
#define all(x) (x).begin(),(x).end()
#define dbg(x) cerr << #x << " = " << x << endl
#define sz(x) (int)((x).size())
#define ms(m,v) memset((m), (v), sizeof (m))
#define mp make_pair
#define pb push_back

map<string, int> m;
int dano[] = {0, 200, 300, 400, 100};
int tab[][5] = {
  {0},
  {0, 20, 30, 50},
  {0, 10, 25, 40},
  {0, 25, 55, 70},
  {0, 18, 38, 60}
};

void init() {
  m["fire"] = 1;
  m["water"] = 2;
  m["earth"] = 3;
  m["air"] = 4;
}

bool inside(int x,int y,int w,int h, int cx, int cy) {
  if (x <= cx && cx <= x + w)
    if (y <= cy && cy <= y + h)
      return true;
  return false;
}

int d(int cx, int cy, int xx, int yy, int r) {
  return (xx-cx)*(xx-cx)+(yy-cy)*(yy-cy)<=r*r;
}

bool ok(int x, int y, int w, int h, int cx, int cy, int r) {
  if (inside(x,y,w,h,cx,cy)) return true;

  int xx = 0;
  if (cx < x) xx = x;
  else if (cx > x + w) xx = x + w;
  else xx = cx;
  int yy = 0;
  if (cy < y) yy = y;
  else if (cy > y + h) yy = y + h;
  else yy = cy;

  if (d(xx,yy,cx,cy,r)) return true;
  return false;
}


int main() {
  int t;
  init();
  for (cin >> t; t--;) {
    int x,y,w,h;
    cin >> x >> y >> w >> h;

    string magia;
    int n, cx, cy;
    cin >> magia >> n >> cx >> cy;

    assert(m[magia]!=0);

    int r = tab[m[magia]][n];
    if (m[magia] != 0 && ok(x,y,w,h,cx,cy,r))
      cout << dano[m[magia]] << endl;
    else
      puts("0");
  }
  return 0;
}
