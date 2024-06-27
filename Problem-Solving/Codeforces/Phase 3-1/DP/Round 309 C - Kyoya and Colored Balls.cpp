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
int n, a[1002], dp[1002][1002];
void solve() {
    cin >> n;
    dp[0][0] = 1;
    for (int i = 1; i < 1002; i++) {//creating pascale triangle as nCr = pascal[n][r];
        dp[i][0] = 1;
        for (int j = 1; j <= i; j++) {
            dp[i][j] += (dp[i - 1][j] + dp[i - 1][j - 1]) % mod;
        }
    }
    int x, sum = 0;
    ll res = 1;
    while (n--) {//res*=presum[i] C ri 
        cin >> x;
        sum += x;
        res = res * dp[sum - 1][x - 1];
        res %= mod;
    }
    cout << res;
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