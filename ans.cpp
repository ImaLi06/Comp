#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define MAXN 10000000
#define MOD 1000000007
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

void solve() {
  ll p, q;
  cin >> p >> q;
  ll tot = p + 2 * q;

  for (ll i = 1; i * i <= tot; i++) {
    ll res = tot - i;
    ll mul = i * 2 + 1;
    ll rr = res / mul;

    ll dif = abs(rr - i);

    if (rr + i + rr * i * 2 == tot && dif <= p) {
      cout << rr << " " << i << "\n";
      return;
    }
  }

  cout << "-1\n";
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int tt = 1;
  cin >> tt;
  while (tt--)
    solve();
}
