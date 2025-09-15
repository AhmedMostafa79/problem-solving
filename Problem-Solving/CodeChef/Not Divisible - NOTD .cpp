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
using cd = complex<double>;
const double PI = acos(-1);
#define int ll
void fft(vector<cd>& a, bool invert) {
    int n = a.size();

    for (int i = 1, j = 0; i < n; i++) {
        int bit = n >> 1;
        for (; j & bit; bit >>= 1)
            j ^= bit;
        j ^= bit;

        if (i < j)
            swap(a[i], a[j]);
    }

    for (int len = 2; len <= n; len <<= 1) {
        double ang = 2 * PI / len * (invert ? -1 : 1);
        cd wlen(cos(ang), sin(ang));
        for (int i = 0; i < n; i += len) {
            cd w(1);
            for (int j = 0; j < len / 2; j++) {
                cd u = a[i + j], v = a[i + j + len / 2] * w;
                a[i + j] = u + v;
                a[i + j + len / 2] = u - v;
                w *= wlen;
            }
        }
    }

    if (invert) {
        for (cd& x : a)
            x /= n;
    }
}

vector<int> multiply(vector<int> const& a, vector<int> const& b) {
    vector<cd> fa(a.begin(), a.end()), fb(b.begin(), b.end());
    int n = 1;
    while (n < (int)a.size() + b.size())
        n <<= 1;
    fa.resize(n);
    fb.resize(n);

    fft(fa, false);
    fft(fb, false);
    for (int i = 0; i < n; i++)
        fa[i] *= fb[i];
    fft(fa, true);

    vector<int> result(n);
    for (int i = 0; i < n; i++)
        result[i] = round(fa[i].real());
    return result;
}
const int N = 2e5 + 5;
vector<int> divs[N];
void pre() {
    for (int i = 1; i < N; i++) {
        for (int j = i; j < N; j += i) {
            divs[j].push_back(i);
        }
    }
}
void solve() {
    int n;
    cin >> n;
    vector<int>v(n);
    for (auto& i : v)
        cin >> i;
    int sh = *max_element(all(v));
    vector<int>f1(sh + 1), f2(sh + 1);
    for (int i = 0; i < n; i++)
        f1[v[i]]++, f2[sh - v[i]]++;
    vector<int>ans = multiply(f1, f2);
    vector<bool>valid(sh + 1);
    for (int i = 1; i <= sh; i++) {
        if (ans[i + sh]) {
            //cout << i << " ";
            for (auto j : divs[i])
                valid[j] = 1;
        }
        //cout << '\n';
    }
    //cout << "\n\n";
    for (int i = 1; i <= sh; i++)
        if (!valid[i])
            return void(cout << i << '\n');
}
signed main() {
    Fast;
    int t = 1;
    cin >> t;
    pre();
    for (int i = 1; i <= t; i++) {
        solve();
    }
}