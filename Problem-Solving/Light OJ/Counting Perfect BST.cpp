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
const int N = 2e6 + 5, mod = 1e8 + 7;;
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
vector<int>v;
void seive() {
    unordered_map<int, bool>mp;
    int c = 0;
    for (int i = 2; i <= 1e5; i++) {
        int x = i * i;
        while (x <= 1e10) {
            c++;
            mp[x] = 1;
            x *= i;
        }
    }

    for (auto i : mp)
        v.push_back(i.first);
    sort(all(v));
}
//formula used to compute number of BSTs with n nodes
int catalan(int n) {
    if (n <= 0)
        return 0;
    return mul(mul(fact[2 * n], inv[n + 1]), inv[n]);
}
void solve() {
    int l, r;
    cin >> l >> r;
    int a = lower_bound(all(v), l) - v.begin();
    int b = upper_bound(all(v), r) - v.begin();

    cout << catalan(b - a) << '\n';
}
signed main() {
    Fast;
    int t = 1;
    cin >> t;
    pre();
    seive();
    for (int i = 1; i <= t; i++) {
        cout << "Case " << i << ": ";
        solve();
    }
}