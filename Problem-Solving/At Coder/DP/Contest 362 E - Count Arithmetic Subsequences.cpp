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
int dp[N][N][N]{};//rock,scissor,paper=3, 1, 2
int n, ar[100];
int f(int i, int j, int l) {
    if (l == 2)
        return 1;
    int& ret = dp[i][j][l];
    if (~ret)
        return ret;
    ret = 0;
    for (int k = j + 1; k < n; k++) {
        if (ar[k] - ar[j] == ar[j] - ar[i])
            ret = (ret % MOD + (f(j, k, l - 1))) % MOD;
    }
    return ret;
}
void solve() {
    memset(dp, -1, sizeof dp);
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> ar[i];
    int res[N]{};
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            for (int k = 2; k <= n; k++) {
                res[k] = (res[k] + (f(i, j, k))) % MOD;
            }
        }
    }
    res[1] = n;
    for (int i = 1; i <= n; i++)
        cout << res[i] << " ";
    cout << '\n';
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