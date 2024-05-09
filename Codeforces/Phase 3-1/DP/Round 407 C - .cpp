#include <bits/stdc++.h>
using namespace std;
#define  ll long long 
#define  all(v) ((v).begin()),((v).end())
#define  rall(v) ((v).rbegin()),((v).rend())
#define Fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define close(n) return cout<<n,0;
const int dy[] = { -1,0,1,0,1,-1,1,-1 };
const int dx[] = { 0,1,0,-1,1,-1,-1,1 };
const int di[] = { 'U','R','D','L' };
int countbit(ll n) { return (n > 1 ? (n & 1) + countbit(n >> 1) : n); }
ll gcd(ll x, ll y) { if (!y)return x; return gcd(y, x % y); }
ll lcm(ll x, ll y) { return x * y / gcd(x, y); }
const int N = 4e4 + 3, mod = 1e9 + 7;
void solve() {
    int n;
    cin >> n;
    vector<int>dif(n + 1), a(n + 1);
    for (int x, i = 1; i <= n; i++) {
        cin >> a[i];
        if (i > 1)
            dif[i] = abs(a[i] - a[i - 1]);
    }
    vector<ll>dp[2]{};
    dp[0].resize(n + 1);
    dp[1].resize(n + 1);
    ll res = 0;
    for (int i = 1; i <= n; i++) {
        dp[0][i] = max(dif[i], dp[1][i - 1] + dif[i]);
        dp[1][i] = max(-dif[i], dp[0][i - 1] - dif[i]);
        res = max({ res,dp[0][i], dp[1][i] });
    }
    cout << res << '\n';

}
int main()
{
    Fast;
    int T = 1;
    //cin >> T;
    for (int i = 1; T--; i++) {
        //cout << "Case " << i << ":\n";
        solve();
    }
    return 0;
}