#include<bits/stdc++.h>
using namespace std;
#define  ll long long
#define  all(v) ((v).begin()),((v).end())
#define  rall(v) ((v).rbegin()),((v).rend())
#define Fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define files  freopen("closing.in", "r", stdin); freopen("closing.out", "w", stdout);
const int N = 2e5 + 5, mod = 1e9 + 7, base = 31;

ll get_substr(int i, int j, const vector<ll>& h,
    const vector<ll>& pw) {//gets substr in range[i,j]
    return (h[j] - (h[i] * pw[j - i]) % mod + mod) % mod;
}
void solve() {
    string s;
    cin >> s;
    int n = s.size();
    s = ' ' + s;
    vector<ll>h(n + 5), pw(n + 5);
    pw[0] = 1;
    for (int i = 1; i <= n; i++) {
        h[i] = (h[i - 1] * base) % mod + (s[i]);
        h[i] %= mod;
        pw[i] = (pw[i - 1] * base) % mod;
    }
    int res = n;
    for (int i = 1; i <= n; i++) {
        int cur = h[i];
        bool valid = 1;
        if (n % i)
            continue;
        for (int j = i * 2; j <= n; j += i) {
            int cur2 = get_substr(j - i, j, h, pw);
            valid &= (cur == cur2);
        }
        if (valid)
            res = min(res, i);
    }
    cout << res << '\n';
}
int main() {
    Fast;
    int t = 1;
    cin >> t;
    for (int i = 1; i <= t; i++) {
        solve();
        if (i < t)
            cout << '\n';
    }
    return 0;
}
