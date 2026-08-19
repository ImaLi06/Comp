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
  ll n, m, k;
  cin >> n >> m >> k;

  ll mcmm = (m * n) / gcd(m, n);

  ll l = 1;
  ll r = 1000000000000000000;
  ll ans = 1;
  while (l <= r) {
    ll mid = (l + r) / 2;
    ll cnt = (mid / n) + (mid / m) - 2 * (mid / mcmm);
    if (cnt < k)
      l = mid + 1;
    else {
      r = mid - 1;
      ans = mid;
    }
  }

  cout << ans;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int tt = 1;
  // cin >> tt;
  while (tt--)
    solve();
}
