#include<bits/stdc++.h>
using namespace std;
#define  ll long long
#define  all(v) ((v).begin()),((v).end())
#define  rall(v) ((v).rbegin()),((v).rend())
#define Fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define files  freopen("closing.in", "r", stdin); freopen("closing.out", "w", stdout);
const int N = 2e5 + 5, mod = 1e9 + 7, base = 31;
vector<ll>pref, suff, pw;
ll get_substr(int i, int j, const vector<ll>& h) {//gets substr in range[i,j]
    return (h[j] - (h[i - 1] * pw[j - i + 1]) % mod + mod) % mod;
}
int n;
bool check_pld(int i, int j) {
    int a = get_substr(i, j, pref);
    int b = get_substr(n - j + 1, n - i + 1, suff);
    return (a == b);
}

void solve() {
    string s;
    cin >> s;
    n = s.size();
    pref = suff = pw = vector<ll>(n + 5);
    vector<vector<ll>>dp(n + 5, vector<ll>(n + 5));
    pw[0] = 1;
    for (int i = 1; i <= n; i++) {
        pref[i] = (pref[i - 1] * base) % mod + (s[i - 1] - 'a');
        pref[i] %= mod;
        pw[i] = (pw[i - 1] * base) % mod;
    }
    reverse(all(s));
    for (int i = 1; i <= n; i++) {
        suff[i] = (suff[i - 1] * base) % mod + (s[i - 1] - 'a');
        suff[i] %= mod;
    }

    for (int i = 1; i <= n; i++)
        for (int j = i; j <= n; j++) {
            dp[i][j] += check_pld(i, j);
            dp[i][j] += dp[i][j - 1];
        }

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            dp[i][j] += dp[i - 1][j];

    auto get_pref2d = [&](int r1, int c1, int r2, int c2) {
        return dp[r2][c2] - dp[r2][c1 - 1] - dp[r1 - 1][c2] + dp[r1 - 1][c1 - 1];
        };

    int q;
    cin >> q;
    while (q--) {
        int l, r;
        cin >> l >> r;
        cout << get_pref2d(l, l, r, r) << '\n';
    }
}
int main() {
    Fast;
    int t = 1;
    //cin >> t;
    for (int i = 1; i <= t; i++) {
        solve();
        if (i < t)
            cout << '\n';
    }
    return 0;
}
