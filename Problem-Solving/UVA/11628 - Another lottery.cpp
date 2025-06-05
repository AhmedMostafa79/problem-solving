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
const int N = 2e5 + 5, mod = 1e9 + 7, base = 31;

int n, m;
void solve() {
    vector<vector<int>>v(n + 1, vector<int>(m + 1));
    for (int i = 1; i <= n; i++) {

        for (int j = 1; j <= m; j++) {
            cin >> v[i][j];
        }
    }
    ll ttl = 0;
    for (int i = 1; i <= n; i++)
        ttl += v[i][m];
    for (int i = 1; i <= n; i++) {
        ll gc = gcd(ttl, v[i][m]);
        cout << v[i][m] / gc << " / " << ttl / gc << '\n';
    }

}
int main() {
    Fast;
    int t = 1;
    //cin >> t;
    for (int i = 1; cin >> n >> m and (n and m); i++) {
        solve();
        //if (i < t)
            //cout << '\n';
    }
    return 0;
}
