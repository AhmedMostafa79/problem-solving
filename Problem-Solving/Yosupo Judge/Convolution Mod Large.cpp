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
const int  mod = 1e9 + 7;
typedef complex<double> C;
typedef vector<double> vd;
int clz_portable(unsigned int x) {
    if (x == 0) return 32;
    int n = 0;
    while ((x & 0x80000000) == 0) { n++; x <<= 1; }
    return n;
}
void fft(vector<C>& a) {
    int n = sz(a), L = 31 - clz_portable(n);
    static vector<complex<long double>> R(2, 1);
    static vector<C> rt(2, 1);  // (^ 10% faster if double)
    for (static int k = 2; k < n; k *= 2) {
        R.resize(n); rt.resize(n);
        auto x = polar(1.0L, acos(-1.0L) / k);
        rep(i, k, 2 * k) rt[i] = R[i] = i & 1 ? R[i / 2] * x : R[i / 2];
    }
    vector<int> rev(n);
    rep(i, 0, n) rev[i] = (rev[i / 2] | (i & 1) << L) / 2;
    rep(i, 0, n) if (i < rev[i]) swap(a[i], a[rev[i]]);
    for (int k = 1; k < n; k *= 2)
        for (int i = 0; i < n; i += 2 * k) rep(j, 0, k) {
            // C z = rt[j+k] * a[i+j+k]; // (25% faster if hand-rolled)  /// include-line
            auto x = (double*)&rt[j + k], y = (double*)&a[i + j + k];        /// exclude-line
            C z(x[0] * y[0] - x[1] * y[1], x[0] * y[1] + x[1] * y[0]);           /// exclude-line
            a[i + j + k] = a[i + j] - z;
            a[i + j] += z;
        }
}

template<int M> vector<int> convMod(const vector<int>& a, const vector<int>& b) {
    if (a.empty() || b.empty()) return {};
    vector<int> res(sz(a) + sz(b) - 1);
    int B = 32 - clz_portable(sz(res)), n = 1 << B, cut = (int)(sqrt(M));
    vector<C> L(n), R(n), outs(n), outl(n);
    rep(i, 0, sz(a)) L[i] = C((int)a[i] / cut, (int)a[i] % cut);
    rep(i, 0, sz(b)) R[i] = C((int)b[i] / cut, (int)b[i] % cut);
    fft(L), fft(R);
    rep(i, 0, n) {
        int j = -i & (n - 1);
        outl[j] = (L[i] + conj(L[j])) * R[i] / (2.0 * n);
        outs[j] = (L[i] - conj(L[j])) * R[i] / (2.0 * n) / 1i;
    }
    fft(outl), fft(outs);
    rep(i, 0, sz(res)) {
        ll av = (ll)(real(outl[i]) + .5), cv = (ll)(imag(outs[i]) + .5);
        ll bv = (ll)(imag(outl[i]) + .5) + (ll)(real(outs[i]) + .5);
        res[i] = ((av % M * cut + bv) % M * cut + cv) % M;
    }
    return res;
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

    vector<int>ans = convMod<mod>(a, b);
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