/*
    Main idea 
    -FFT
*/

#include <bits/stdc++.h>
using namespace std;
#define ll long long
using cd = complex<double>;
const double PI = acos(-1);
#define int ll

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
string string_multiply(const string& s1, const string& s2) {
    int n = s1.size(), m = s2.size();;
    vector<int>p1(n), p2(m);
    for (int i = 0; i < n; i++) {//e.g. s1= 254--> 4+5x+2x^2  ..x=10
        p1[n - i - 1] = s1[i] - '0';
    }
    for (int i = 0; i < m; i++) {
        p2[m - i - 1] = s2[i] - '0';
    }

    vector<int>ans = multiply(p1, p2);

    for (int i = 0; i + 1 < ans.size(); i++) {
        ans[i + 1] += ans[i] / 10;
        ans[i] %= 10;
    }
    string ret = to_string(ans.back());
    for (int i = ans.size() - 2; i >= 0; i--) {
        ret += (char)(ans[i] + '0');
    }
    for (int i = 0; i < ret.size(); i++) {
        if (ret[i] != '0')//remove heading 0s
            return ret.substr(i);
    }
    return "0";//multiplication=0
}
void solve() {
    string a, b;
    cin >> a >> b;
    cout << string_multiply(a, b) << '\n';

}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    cin >> t;
    while (t--) solve();
}