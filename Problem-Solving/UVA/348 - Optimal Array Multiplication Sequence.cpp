#include<bits/stdc++.h>

using namespace std;
#define  ll long long 
#define  all(v) ((v).begin()),((v).end())
#define  rall(v) ((v).rbegin()),((v).rend())
#define Fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define files  freopen("closing.in", "r", stdin); freopen("closing.out", "w", stdout);
int countbit(ll n) { return (n > 1 ? (n & 1) + countbit(n >> 1) : n); }
ll gcd(ll x, ll y) { if (!y)return x; return gcd(y, x % y); }
ll lcm(ll x, ll y) { return x * y / gcd(x, y); }
const int dx[] = { -1,0,1,0,1,-1,1,-1 };
const int dy[] = { 0,1,0,-1,1,-1,-1,1 };
const int di[] = { 'U','R','D','L' };
const int N = 11, mod = 1e9 + 7;
ll dp[N][N], l[N], r[N], dir[N][N];
int n;
ll f(int i, int j) {
    if (j == i)
        return 0;
    ll& ret = dp[i][j];
    if (~ret)
        return ret;
    ret = 1e15;
    for (int k = i; k <= j; k++) {
        ll   best = f(i, k) + f(k + 1, j) + (l[i] * r[j] * r[k]);
        if (best < ret) {
            ret = best;
            dir[i][j] = k;
        }
    }
    return ret;
}
void print(int i, int j) {
    if (i == j)
        return void(cout << "A" << i);
    cout << "(";
    print(i, dir[i][j]);
    cout << " x ";
    print(dir[i][j] + 1, j);
    cout << ")";

}
void solve() {
    memset(dp, -1, sizeof dp);
    for (int i = 1; i <= n; i++)
        cin >> l[i] >> r[i];
    f(1, n);
    print(1, n);
    cout << '\n';
}
int main() {
    Fast;
    int t = 1;
    //cin >> t;
    for (int i = 1; cin >> n and n; i++) {
        cout << "Case " << i << ": ";
        solve();
    }
}
