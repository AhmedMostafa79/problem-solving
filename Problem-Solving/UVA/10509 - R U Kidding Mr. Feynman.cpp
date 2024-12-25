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
const int N = 2e5 + 5, mod = 1e9 + 7;

void solve() {
    double  n;
    while (cin >> n and n) {
        double cb = floor(cbrt(n));
        double a = cb * cb * cb;
        double d = n - a;
        //cout << cb << " " << a << ' ' << d << "\n";
        double res = cb + d / (3 * (cb * cb));
        cout << fixed << setprecision(4) << res << '\n';
    }
}
int main() {
    Fast;
    int t = 1;
    //cin >> t;
    for (int i = 1; i <= t; i++) {
        //cout << "Case " << i << ": ";
        solve();
    }
}