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
const ll mod = 132120577, root = 5; // =
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
    int n, m;
    cin >> n >> m;
    vector<int>a(max(n, m)), b(max(n, m));
    for (int i = 0; i < n; i++)
        cin >> a[i];
    while (a.size() < m)//trailing 0s
        a.push_back(0);
    for (int j = max(0ll, n - m); j < max(n, m); j++) //heading 0s
        cin >> b[j];
    /*  for (auto i : a)
          cout << i << " ";
      cout << '\n';
      for (auto j : b)
          cout << j << " ";
      cout << '\n';*/
    m = max(m, n);
    n = max(n, m);
    vector<int>freq(n + 1), freq2(n + 1);
    int sh = n - 1;
    for (int i = 0; i < n; i++) {
        freq[i] = a[i];
        freq2[sh - i] = b[i];
    }
    vector<int>ans = multiply(freq, freq2);
    for (auto i : ans)
        if (i)
            cout << i << ' ';

}
signed  main() {
    Fast;
    int t = 1;

    //cin >> t;
    for (int i = 1; i <= t; i++) {
        solve();
    }
}