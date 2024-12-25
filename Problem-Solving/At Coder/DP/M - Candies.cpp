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
const ll N = 2e5 + 5, MOD = 1e9 + 7;

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int>v(n);
    for (auto& i : v)
        cin >> i;
    vector<vector<int>>dp(n + 1, vector<int>(k + 1));
    sort(all(v));
    //base
    dp[n][0] = 1;
    for (int i = n - 1; i >= 0; i--) {
        for (int rem = 0; rem <= k; rem++) {
            //for (int lim = 0; lim <= v[i]; lim++) {

            int r = rem, l = rem - v[i] - 1;
            ll sum = dp[i + 1][r];
            if (l >= 0)
                sum = (sum - dp[i + 1][l] + MOD) % MOD;
            (dp[i][rem] += sum) %= MOD;
            //}
            if (rem)
                (dp[i][rem] += dp[i][rem - 1]) %= MOD;
        }
    }
    cout << dp[0][k] % MOD;//
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