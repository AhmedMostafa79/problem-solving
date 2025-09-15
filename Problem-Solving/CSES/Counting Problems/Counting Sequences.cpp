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
const int N = 1e6 + 5, mod = 1e9 + 7;;
int mul(int a, int b) {
    return a % mod * (b % mod) % mod;
}
int fp(int n, int p) {
    int ret = 1;
    while (p) {
        if (p & 1)
            ret = mul(ret, n);
        n = mul(n, n);
        p /= 2;
    }
    return ret;
}
vector<int>inv(N), fact(N);
void pre() {
    fact[0] = 1;
    for (int i = 1; i < N; i++) {
        fact[i] = mul(fact[i - 1], i);
    }
    inv[N - 1] = fp(fact[N - 1], mod - 2);
    for (int i = N - 2; i >= 0; i--) {
        inv[i] = mul(inv[i + 1], i + 1);
    }
}

ll C(int n, int r) {
    if (r > n)
        return 0;
    return mul(mul(fact[n], inv[r]), inv[n - r]);
}
void solve() {
    int n, k;;
    cin >> n >> k;
    ll res = 0;
    for (int i = 0; i < k; i++) {
        res += (i & 1 ? -1 : 1) * mul(C(k, i), fp(k - i, n));

        res = (res + mod) % mod;
    }
    cout << res << "\n";
}
signed main() {
    Fast;
    int t = 1;
    //cin >> t;
    pre();
    for (int i = 1; i <= t; i++) {
        //cout << "Case " << i << ": ";
        solve();
    }
}