#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;
#define  ll long long
#define  all(v) ((v).begin()),((v).end())
#define  rall(v) ((v).rbegin()),((v).rend())
#define Fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define close(n) return cout<<n,0;

const int dx[] = { -1,0,1,0,1,-1,1,-1 };
const int dy[] = { 0,-1,0,1,1,-1,-1,1 };
const int di[] = { 'U','R','D','L' };
int countbit(ll n) { return (n > 1 ? (n & 1) + countbit(n >> 1) : n); }
ll gcd(ll x, ll y) { if (!y)return x; return gcd(y, x % y); }
ll lcm(ll x, ll y) { return x * y / gcd(x, y); }

#define int ll

ostream& operator<<(ostream& out, vector<int>& v) {
    for (auto& i : v)
        out << i << " ";
    return out;
}istream& operator>>(istream& in, vector<int>& v) {
    for (auto& i : v)
        in >> i;
    return in;
}
const int mod = 1e8 + 7;
ll fp(ll x, ll p) {
    ll res = 1;
    while (p) {
        if (p & 1)
            res = res % mod * x % mod % mod;
        x = x % mod * x % mod % mod;
        p /= 2;
    }
    return res;
}
void solve() {
    int n;
    cin >> n;
    vector<int>v(n);
    cin >> v;
    ll sum = accumulate(all(v), 0ll) % mod;
    sum = fp(2, n - 1) * sum % mod;
    cout << sum << '\n';
}
signed main() {
    Fast;
    int t = 1;
    cin >> t;
    for (int i = 1; i <= t; i++) {
        cout << "Case " << i << ": ";
        solve();
    }
}