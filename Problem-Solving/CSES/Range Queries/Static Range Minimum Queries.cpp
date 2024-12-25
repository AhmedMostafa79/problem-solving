#include <bits/stdc++.h>
using namespace std;
#define  ll long long
#define  all(v) ((v).begin()),((v).end())
#define  rall(v) ((v).rbegin()),((v).rend())
#define Fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define close(n) return cout<<n,0;
#define files  freopen("closing.in", "r", stdin); freopen("closing.out", "w", stdout);
const int dx[] = { -1,0,1,0,1,-1,1,-1 };
const int dy[] = { 0,-1,0,1,1,-1,-1,1 };
const int di[] = { 'U','R','D','L' };
int countbit(ll n) { return (n > 1 ? (n & 1) + countbit(n >> 1) : n); }
ll gcd(ll x, ll y) { if (!y)return x; return gcd(y, x % y); }
ll lcm(ll x, ll y) { return x * y / gcd(x, y); }
const int N = 2e5 + 5, mod = 1e9 + 7;
int T[N][23], n;
vector<int>a;
int merge(int a, int b) {
    return min(a, b);
}
void table() {
    for (int i = 0; i < n; i++) {
        T[i][0] = a[i];
    }
    for (int pw = 1; 1 << pw <= n; pw++) {
        for (int i = 0; i + (1 << pw) <= n; i++) {
            int nxt = 1 << (pw - 1);
            T[i][pw] = merge(T[i][pw - 1], T[i + nxt][pw - 1]);
        }
    }
}
int get(int l, int r) {//time O(1)
    int sz = r - l + 1;
    int lg = log2(sz);
    r = r - (1 << lg) + 1;
    return merge(T[l][lg], T[r][lg]);
}
void solve() {
    Fast;
    int q;
    cin >> n >> q;
    a = vector<int>(n);
    for (auto& i : a)
        cin >> i;
    table();
    while (q--) {
        int l, r;
        cin >> l >> r;
        cout << get(l - 1, r - 1) << '\n';
    }
}
int main() {
    Fast;
    int t = 1;
    //cin >> t;
    while (t--) {
        solve();
    }
}