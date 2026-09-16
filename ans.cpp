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
int freq[MAXN + 1];
void solve() {
  int n;
  cin >> n;
  vector<ll> a(n);
  for (int i = 0; i < n; i++)
    cin >> a[i];
  for (int i = 0; i < n; i++)
    freq[a[i]]++;
  for (int i = MAXN; i >= 1; i--) {
    int cnt = 0;
    for (int j = i; j <= MAXN; j += i) {
      cnt += freq[j];
      if (cnt > 1) {
        cout << i;
        return;
      }
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
