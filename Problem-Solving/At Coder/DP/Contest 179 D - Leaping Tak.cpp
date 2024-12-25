#include<bits/stdc++.h>
using namespace std;
#define  ll long long
#define  all(v) ((v).begin()),((v).end())
#define  rall(v) ((v).rbegin()),((v).rend())
#define Fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define close(n) return cout<<n,0;
#define files  freopen("closing.in", "r", stdin); freopen("closing.out", "w", stdout);
const int dx[] = { -1,0,1,0,1,-1,1,-1 };
const int dy[] = { 0,-1,0,1,1,-1,-1,1 };
const int di[] = { 'U','R','D','L' };
int countbit(ll n) { return (n > 1 ? (n & 1) + countbit(n >> 1) : n); }
ll gcd(ll x, ll y) { if (!y)return x; return gcd(y, x % y); }
ll lcm(ll x, ll y) { return x * y / gcd(x, y); }
const ll N = 80 + 1, MOD = 998244353;

void solve() {
    int n, k;
    cin >> n >> k;
    vector<pair<int, int>>v(k + 1);
    for (int i = 1; i <= k; i++)
        cin >> v[i].first >> v[i].second;
    ll* dp = new ll[n + 1]{};
    dp[1] = 1;
    for (int i = 2; i <= n; i++) {
        ll cur = 0;
        for (int j = 1; j <= k; j++) {
            if (v[j].first >= i)//means whole the segment j-i<1
                continue;
            int l = max(1, i - v[j].second);
            int r = i - v[j].first;
            cur += dp[r] - dp[l - 1];
        }
        cur %= MOD;
        if (cur < 0)
            cur += MOD;
        dp[i] = (cur + dp[i - 1]) % MOD;
    }
    ll res = dp[n] - dp[n - 1];
    if (res < 0)
        res += MOD;
    cout << res << '\n';
}
int main() {
    Fast;
    int t = 1;
    //cin >> t;
    for (int i = 1; i <= t; i++) {
        //cout << "Case " << i << ": ";
        solve();
        cout << "\n";

    }
}