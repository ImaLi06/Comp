#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define MAXN 1000000
#define MOD 9302023
#define INF 1e9
#define fi first
#define se second
#define print(v)                                                               \
  for (auto &x : v)                                                            \
    cout << x << ' ';                                                          \
  cout << '\n'
#define printm(m)                                                              \
  for (auto &row : m) {                                                        \
    for (auto &x : row)                                                        \
      cout << x << ' ';                                                        \
    cout << '\n';                                                              \
  }
struct Node {
  ll cval;
  ll oval;
};
struct LNode {
  ll t;
  ll val;
};
typedef Node tn;     // segment-tree node type
typedef LNode tl;    // lazy type
#define NEUT {0, 0}  // operation neutral
#define CLEAR {0, 0} // cleared lazy node
tn oper(tn a, tn b) { return {a.cval + b.cval, a.oval + b.oval}; }
void acum(tl &a, tl v) { a = v; }
tn calc(int s, int e, tn a, tl v) {
  if (v.t == 1)
    a.cval = 0;
  else if (v.t == 2)
    a.cval = a.oval;
  else if (v.t == 3)
    a.cval = v.val;
  return a;
}
struct STree {
  vector<tn> st;
  vector<tl> lazy;
  int n;
  STree(int n) : st(4 * n + 5, NEUT), lazy(4 * n + 5, CLEAR), n(n) {}
  void init(int k, int s, int e, vector<tn> &a) {
    if (e - s == 1)
      st[k] = a[s];
    else {
      int m = (s + e) / 2;
      init(2 * k, s, m, a);
      init(2 * k + 1, m, e, a);
      st[k] = oper(st[2 * k], st[2 * k + 1]);
    }
  }
  void push(int k, int s, int e) {
    if (lazy[k].t == 0)
      return;
    st[k] = calc(s, e, st[k], lazy[k]);
    if (e - s != 1) {
      acum(lazy[2 * k], lazy[k]);
      acum(lazy[2 * k + 1], lazy[k]);
    }
    lazy[k] = CLEAR;
  }
  void upd(int k, int s, int e, int a, int b, tl v) {
    push(k, s, e);
    if (e <= a || b <= s)
      return;
    if (a <= s && e <= b) {
      acum(lazy[k], v);
      push(k, s, e);
      return;
    }
    int m = (s + e) / 2;
    upd(2 * k, s, m, a, b, v), upd(2 * k + 1, m, e, a, b, v);
    st[k] = oper(st[2 * k], st[2 * k + 1]);
  }
  tn query(int k, int s, int e, int a, int b) {
    if (e <= a || b <= s)
      return NEUT;
    push(k, s, e);
    if (a <= s && e <= b)
      return st[k];
    int m = (s + e) / 2;
    return oper(query(2 * k, s, m, a, b), query(2 * k + 1, m, e, a, b));
  }
  int search(int k, int s, int e, ll acc, ll obj) {
    if (s + 1 == e)
      return s;
    push(k, s, e);
    int m = (s + e) / 2;
    push(k * 2, s, m);
    if (acc + st[k * 2].cval > obj) {
      return search(k * 2, s, m, acc, obj);
    }
    push(k * 2 + 1, m, e);
    return search(k * 2 + 1, m, e, acc + st[k * 2].cval, obj);
  }
  void upd(int a, int b, tl v) { upd(1, 0, n, a, b, v); }
  tn query(int a, int b) { return query(1, 0, n, a, b); }
  void init(vector<tn> &a) { init(1, 0, n, a); }
  int search(ll obj) { return search(1, 0, n, 0, obj); }
};
void solve() {
  ll n, m;
  cin >> n >> m;
  vector<ll> a(n);
  for (int i = 0; i < n; i++)
    cin >> a[i];
  vector<Node> base;
  for (int i = 0; i < n; i++)
    base.push_back({a[i], a[i]});
  vector<ll> pref = a;
  for (int i = 1; i < n; i++)
    pref[i] = pref[i - 1] + a[i];
  STree st(n);
  st.init(base);
  while (m--) {
    int t;
    cin >> t;
    if (t == 1) {
      ll b, v;
      cin >> b >> v;
      Node sum = st.query(0, b);
      int limit = st.search(sum.cval - v);
      if (sum.cval - v < 0) {
        st.upd(0, b, {1, 0});
        continue;
      }
      Node subsum = {0, 0};
      if (limit + 1 < b) {
        subsum = st.query(limit + 1, b);
        st.upd(limit + 1, b, {1, 0});
      }
      ll nval = st.query(limit, limit + 1).cval - v + subsum.cval;
      st.upd(limit, limit + 1, {3, nval});
    } else {
      int l, r;
      cin >> l >> r;
      ll summ = st.query(l - 1, r).cval;
      ll oris = pref[r - 1] - (l - 2 >= 0 ? pref[l - 2] : 0);
      cout << oris - summ << "\n";
      st.upd(l - 1, r, {2, 0});
    }
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int tt = 1;
  // cin >> tt;
  while (tt--)
    solve();
}
