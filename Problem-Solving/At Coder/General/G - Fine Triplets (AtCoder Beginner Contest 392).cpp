/*
    main idea..
       -fft
       -as B-A=C-B--> 2B=A+C..holds for all valid triplets A<B<C
       -so res+=ans[v[i]+v[i]]

*/
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
using cd = complex<double>;
const double PI = acos(-1);

void fft(vector<cd>& a, bool invert) {
    int n = a.size();
    if (n == 1) return;

    vector<cd> even(n / 2), odd(n / 2);
    for (int i = 0; 2 * i < n; i++) {
        even[i] = a[2 * i];
        odd[i] = a[2 * i + 1];
    }
    fft(even, invert);
    fft(odd, invert);

    double ang = 2 * PI / n * (invert ? -1 : 1);
    cd w(1), wn(cos(ang), sin(ang));
    for (int i = 0; 2 * i < n; i++) {
        a[i] = even[i] + w * odd[i];
        a[i + n / 2] = even[i] - w * odd[i];
        if (invert) {
            a[i] /= 2;
            a[i + n / 2] /= 2;
        }
        w *= wn;
    }
}

vector<int> multiply(vector<int> const& a, vector<int> const& b) {
    vector<cd> fa(a.begin(), a.end()), fb(b.begin(), b.end());
    int n = 1;
    while (n < (int)a.size() + (int)b.size())
        n <<= 1;
    fa.resize(n);
    fb.resize(n);

    fft(fa, false);
    fft(fb, false);
    for (int i = 0; i < n; i++)
        fa[i] *= fb[i];
    fft(fa, true);

    vector<int> result(n);
    for (int i = 0; i < n; i++) {
        // Add epsilon before rounding to handle floating-point errors
        result[i] = (int)round(fa[i].real() + 1e-9);
    }
    // Resize to only necessary terms (degree a.size() + b.size() - 2)
    result.resize(a.size() + b.size() - 1);
    return result;
}


void solve() {
    int n;
    cin >> n;
    vector<int>v(n);
    for (auto& i : v)
        cin >> i;
    vector<int>p1(*max_element(all(v)) + 1);
    int sh = p1.size() - 1;
    for (auto i : v)
        p1[i] = 1;

    vector<int>ans = multiply(p1, p1);
    int res = 0;
    for (auto i : v) {
        ans[i + i] -= 1;//overcounting v[i]+v[i]
        ans[i + i] /= 2;//for overcounting v[i]+v[j], v[j]+v[i]
    }

    for (auto i : v) {
        res += min(i - 1, max(0ll, ans[i + i]));
    }
    cout << res << '\n';
}
signed main() {
    Fast;
    int t = 1;
    //cin >> t;
    for (int i = 1; i <= t; i++) {
        solve();
    }
}