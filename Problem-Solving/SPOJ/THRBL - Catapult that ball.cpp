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
struct node {
    ll  val;
    node(int x = 0) {
        val = x;
    }
};
int n;
node T[N][23];
vector<int>a;
node merge(node l, node r) {
    node t = node();
    t.val = max(l.val, r.val);
    return t;
}
void table() {
    for (int i = 0; i < n; i++)
        T[i][0] = node(a[i]);
    for (int pw = 1; (1 << pw) <= n; pw++) {
        for (int i = 0; i + (1 << pw) <= n; i++) {
            int nxt = 1 << (pw - 1);
            T[i][pw] = merge(T[i][pw - 1], T[i + nxt][pw - 1]);
        }
    }
}
ll get1(int l, int r) {
    int sz = r - l + 1;
    node ret = node();
    int lg = log2(sz);
    for (int pw = lg; pw >= 0; pw--) {
        if (l + (1 << pw) - 1 <= r) {
            ret = merge(ret, T[l][pw]);
            l += (1 << pw);
        }
    }
    return ret.val;
}
ll get2(int l, int r) {//time O(1)
    int sz = r - l + 1;
    int lg = log2(sz);
    r = r - (1 << lg) + 1;
    return merge(T[l][lg], T[r][lg]).val;
}

void solve() {
    Fast;
    int q;
    cin >> n >> q;
    a = vector<int>(n);
    for (auto& i : a)
        cin >> i;
    table();
    int res = 0;
    while (q--) {
        int l, r;
        cin >> l >> r;
        if (l == r or get2(l - 1, r - 2) <= a[l - 1])
            res++;
    }
    cout << res << '\n';
}
int main() {
    Fast;
    int t = 1;
    //cin >> t;
    while (t--) {
        solve();
    }
}