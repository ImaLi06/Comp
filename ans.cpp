#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define MAXN 200000
#define MOD 1000000007
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

void solve() {
  int n;
  cin >> n;
  vector<int> a(n);
  vector<pair<int, int>> b;
  string ans = "";
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    b.push_back({a[i], i});
    ans += '1';
  }

  sort(b.rbegin(), b.rend());
  if (b[0].fi == -1) {
    for (int i = 0; i < n - 1; i++)
      cout << 0;
    cout << 1 << "\n";
    return;
  }

  int acn = 1;
  for (int i = 1; i < n; i++) {
    if (a[i] == a[i - 1] && a[i] > 0)
      acn++;
    else
      acn = 1;

    if (acn > 2) {
      cout << "-1\n";
      return;
    }
  }

  for (int i = 0; i < n; i++) {
    int ind = b[i].se;
    if (ans[ind] == '0' || a[ind] <= 0)
      continue;

    int co = b[i].fi;
    if (ind == n - 1 || (ind < n - 1 && a[ind] != a[ind + 1])) {
      for (int i = ind; i < n && co >= 0; i++, co--) {
        if ((a[i] != co && a[i] != -1) || ans[i] == '0' ||
            (co == 0 && a[i] > 0)) {
          cout << "-1\n";
          return;
        }
        if (co > 0)
          ans[i] = '0';
      }
    }

    co = b[i].fi;
    if (ind == 0 || (ind > 0 && a[ind] != a[ind - 1])) {
      for (int i = ind; i >= 0 && co >= 0; i--, co--) {
        if ((a[i] != co && a[i] != -1) || (ans[i] == '0' && i != ind) ||
            (co == 0 && a[i] > 0)) {
          cout << "-1\n";
          return;
        }
        if (co > 0)
          ans[i] = '0';
      }
    }
  }

  for (int i = 0; i < n; i++) {
    if (a[i] == -1)
      continue;
    bool l = false;
    bool r = false;

    if (i - a[i] >= 0 && ans[i - a[i]] == '1')
      l = true;
    if (i + a[i] < n && ans[i + a[i]] == '1')
      r = true;

    if (!l && !r) {
      cout << -1 << "\n";
      return;
    }
  }

  cout << ans << "\n";
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int tt = 1;
  cin >> tt;
  while (tt--)
    solve();
}
