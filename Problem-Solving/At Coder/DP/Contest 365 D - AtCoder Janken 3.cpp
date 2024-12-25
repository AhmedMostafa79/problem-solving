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
ll dp[N][4]{}, n, beat[4] = { 0,3,1,2 };//rock,scissor,paper=3, 1, 2
string s;
int conv(char i) {
    if (i == 'R')
        i = 'A';
    else if (i == 'S')
        i = 'B';
    else i = 'C';
    return i - 'A' + 1;
}

void solve() {
    cin >> n >> s;
    dp[0][beat[conv(s[0])]] = 1;
    dp[0][conv(s[0])] = 0;
    for (int i = 1; i < n; i++) {
        for (int j = 1; j <= 3; j++) {//to ensure that s[i]!=s[i-1] 
            if (j != beat[conv(s[i])])
                dp[i][beat[conv(s[i])]] = max(dp[i][beat[conv(s[i])]], dp[i - 1][j] + 1);
            if (j != conv(s[i]))
                dp[i][conv(s[i])] = max(dp[i][conv(s[i])], dp[i - 1][j]);
        }
    }
    cout << max({ dp[n - 1][1], dp[n - 1][2], dp[n - 1][3] });
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