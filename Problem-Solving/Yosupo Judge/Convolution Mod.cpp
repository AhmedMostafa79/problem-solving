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
#define rep(aa, bb, cc) for(int aa = bb; aa < cc;aa++)
#define sz(a) (int)a.size()
const int mod = 998244353, root = 3;
ll modpow(ll b, ll e) {
    ll ans = 1;
    for (; e; b = b * b % mod, e /= 2)
        if (e & 1) ans = ans * b % mod;
    return ans;
}

// Primitive Root of the mod of form 2^a * b + 1
//just run it to get primitive root of mod 
int generator() {
    vector<int> fact;
    int phi = mod - 1, n = phi;
    for (int i = 2; i * i <= n; ++i)
        if (n % i == 0) {
            fact.push_back(i);
            while (n % i == 0)
                n /= i;
        }
    if (n > 1)
        fact.push_back(n);

    for (int res = 2; res <= mod; ++res) {
        bool ok = true;
        for (size_t i = 0; i < fact.size() && ok; ++i)
            ok &= modpow(res, phi / fact[i]) != 1;
        if (ok)  return res;
    }
    return -1;
}
int modpow(int b, int e, int m) {
    int ans = 1;
    for (; e; b = (ll)b * b % m, e /= 2)
        if (e & 1) ans = (ll)ans * b % m;
    return ans;
}
int clz_portable(unsigned int x) {
    if (x == 0) return 32;
    int n = 0;
    while ((x & 0x80000000) == 0) { n++; x <<= 1; }
    return n;
}
void ntt(vector<int>& a) {
    int n = (int)a.size(), L = 31 - clz_portable(n);
    vector<int> rt(2, 1); // erase the static if you want to use two moduli;
    for (int k = 2, s = 2; k < n; k *= 2, s++) { // erase the static if you want to use two moduli;
        rt.resize(n);
        int z[] = { 1, modpow(root, mod >> s, mod) };
        for (int i = k; i < 2 * k; ++i) rt[i] = (ll)rt[i / 2] * z[i & 1] % mod;
    }
    vector<int> rev(n);
    for (int i = 0; i < n; ++i) rev[i] = (rev[i / 2] | (i & 1) << L) / 2;
    for (int i = 0; i < n; ++i) if (i < rev[i]) swap(a[i], a[rev[i]]);
    for (int k = 1; k < n; k *= 2) {
        for (int i = 0; i < n; i += 2 * k) {
            for (int j = 0; j < k; ++j) {
                int z = (ll)rt[j + k] * a[i + j + k] % mod, & ai = a[i + j];
                a[i + j + k] = ai - z + (z > ai ? mod : 0);
                ai += (ai + z >= mod ? z - mod : z);
            }
        }
    }
}
vector<int> conv(const vector<int>& a, const vector<int>& b) {
    if (a.empty() || b.empty()) return {};
    int s = (int)a.size() + (int)b.size() - 1, B = 32 - clz_portable(s), n = 1 << B;
    int inv = modpow(n, mod - 2, mod);
    vector<int> L(a), R(b), out(n);
    L.resize(n), R.resize(n);
    ntt(L), ntt(R);
    for (int i = 0; i < n; ++i) out[-i & (n - 1)] = (ll)L[i] * R[i] % mod * inv % mod;
    ntt(out);
    return { out.begin(), out.begin() + s };
}
ostream& operator<<(ostream& out, vector<int>& v) {
    for (auto i : v)
        out << i << ' ';
    return out;
}
istream& operator>>(istream& in, vector<int>& v) {
    for (auto& i : v)
        in >> i;
    return in;
}
void solve() {
    int n, m;
    cin >> n >> m;
    vector<int>a(n), b(m);
    cin >> a >> b;

    vector<int>ans = conv(a, b);
    cout << ans << '\n';
}

signed main() {
    Fast;
    int t = 1;
    //cin >> t;
    for (int i = 1; i <= t; i++) {
        solve();
    }
}