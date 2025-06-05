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
    return (h[j] - (h[i - 1] * pw[j - i + 1]) % mod + mod) % mod;
}


void solve() {
    int k, n;
    string s;
    cin >> k >> s;
    n = s.size();
    vector<ll>pref(n + 5), suf(n + 5), pw(n + 5);
    pw[0] = 1;
    for (int i = 1; i <= n; i++) {
        pref[i] = (pref[i - 1] * base) % mod + (s[i - 1] - 'a');
        pref[i] %= mod;
        pw[i] = pw[i - 1] * base % mod;
    }
    reverse(all(s));
    for (int i = 1; i <= n; i++) {
        suf[i] = (suf[i - 1] * base) % mod + (s[i - 1] - 'a');
        suf[i] %= mod;
    }
    int res = 0;
    for (int i = k; i <= n; i++) {
        int a = get_substr(i - k + 1, i, pref, pw);
        int b = get_substr(n - i + 1, n - (i - k), suf, pw);
        res += (a == b);
    }
    cout << res << '\n';
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
