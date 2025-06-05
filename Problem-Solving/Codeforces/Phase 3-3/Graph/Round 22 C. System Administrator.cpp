#include<bits/stdc++.h>
#include <unordered_set>
using namespace std;
#define  ll long long
#define  all(v) ((v).begin()),((v).end())
#define  rall(v) ((v).rbegin()),((v).rend())
#define Fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define files  freopen("closing.in", "r", stdin); freopen("closing.out", "w", stdout);
int countbit(ll n) { return (n > 1 ? (n & 1) + countbit(n >> 1) : n); }
ll gcd(ll x, ll y) { if (!y)return x; return gcd(y, x % y); }
ll lcm(ll x, ll y) { return x * y / gcd(x, y); }
const int dx[] = { 1,-1,0,0 };
const int dy[] = { 0,0,1,-1 };
const int N = 1 << 11, mod = 1e9 + 7, base = 31;

void solve() {
    int n, m, v, u;
    cin >> n >> m >> v;
    u = (v == 2 ? 3 : 2);
    int max_edges = (n - 1) * (n - 2) / 2 + 1;
    int min_edges = n - 1;
    if (m < min_edges or max_edges < m)
        return void(cout << -1);
    //1->v->u
    // so when we cut v we can't reach u
    m -= 2;
    cout << (v == 1 ? 3 : 1) << ' ' << v << '\n';
    cout << v << " " << u << '\n';
    for (int i = 1; i <= n and m > 0; i++) {
        if (i == u)
            continue;
        for (int j = i + 1; j <= n and m; j++) {
            if (j == u or (i == 1 and j == v))
                continue;
            if (i == 1 and v == 1 and j == 3)
                continue;
            cout << i << " " << j << '\n';
            m--;
        }
    }

}
int main() {
    Fast;
    int t = 1;
    //cin >> t;
    for (int i = 1; i <= t; i++) {
        solve();
        //if (i < t)
            //cout << '\n';
    }
    return 0;
}
