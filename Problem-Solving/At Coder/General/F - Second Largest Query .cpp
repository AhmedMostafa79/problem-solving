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
const int N = 1e5 + 5;
struct node {
    int mx1, mx2, mx1_freq, mx2_freq;
    node() : mx1(INT_MIN), mx2(INT_MIN), mx1_freq(0), mx2_freq(0) {}
    node(int x) : mx1(x), mx2(0), mx1_freq(1), mx2_freq(0) {}
};
node merge(node c1, node c2) {
    node t = node();
    if (c1.mx1 > c2.mx1) {
        t.mx1 = c1.mx1;
        t.mx2 = max(c1.mx2, c2.mx1);
        t.mx1_freq = c1.mx1_freq;
        t.mx2_freq = t.mx2 == c1.mx2 ? c1.mx2_freq : c2.mx1_freq;
        if (c1.mx2 == c2.mx1)
            t.mx2_freq = c1.mx2_freq + c2.mx1_freq;

    }
    else if (c1.mx1 < c2.mx1) {
        t.mx1_freq = c2.mx1_freq;
        t.mx1 = c2.mx1;
        t.mx2 = max(c1.mx1, c2.mx2);
        t.mx2_freq = t.mx2 == c1.mx1 ? c1.mx1_freq : c2.mx2_freq;
        if (c1.mx1 == c2.mx2)
            t.mx2_freq = c1.mx1_freq + c2.mx2_freq;
    }
    else {
        t.mx1 = c1.mx1;
        t.mx2 = max(c1.mx2, c2.mx2);
        t.mx1_freq = c1.mx1_freq + c2.mx1_freq;
        t.mx2_freq = t.mx2 == c1.mx2 ? c1.mx2_freq : c2.mx2_freq;
        if (c1.mx2 == c2.mx2)
            t.mx2_freq = c1.mx2_freq + c2.mx2_freq;
    }
    return t;
}
vector<int>a;
vector<node>seg;
void build(int l, int r, int i) {
    if (r == l) {
        seg[i] = node(a[l]);
        return;
    }
    int mid = l + r >> 1;
    int c1 = i * 2 + 1;
    int c2 = i * 2 + 2;
    build(l, mid, c1);
    build(mid + 1, r, c2);
    seg[i] = merge(seg[c1], seg[c2]);
}
void update(int l, int r, int i, int idx, int v) {
    if (l == r) {
        seg[i] = node(v);
        return;
    }
    int mid = l + r >> 1;
    int c1 = i * 2 + 1;
    int c2 = i * 2 + 2;
    if (idx <= mid)
        update(l, mid, c1, idx, v);
    else
        update(mid + 1, r, c2, idx, v);
    seg[i] = merge(seg[c1], seg[c2]);
}
node get(int l, int r, int i, int lq, int rq) {
    if (l > rq or r < lq)
        return node();
    if (lq <= l and r <= rq)
        return seg[i];
    int mid = l + r >> 1;
    int c1 = i * 2 + 1;
    int c2 = i * 2 + 2;
    node L = get(l, mid, c1, lq, rq);
    node R = get(mid + 1, r, c2, lq, rq);
    return merge(L, R);
}
int get(int l, int r, int n) {
    node res = get(0, n - 1, 0, l, r);
    //cout << res.mx1 << " " << res.mx2<<" "<<res.mx1_freq<<" "<<res.mx2_freq << '\n';
    return res.mx2_freq;
}
void solve() {
    Fast;
    int n, q;
    cin >> n >> q;
    a = vector<int>(n);
    for (auto& i : a)
        cin >> i;
    seg = vector<node>(n * 4, node());
    build(0, n - 1, 0);
    while (q--) {
        int t;
        cin >> t;
        if (t == 1) {
            int i, v;
            cin >> i >> v;
            update(0, n - 1, 0, i - 1, v);
        }
        else {
            int l, r;
            cin >> l >> r;
            cout << get(l - 1, r - 1, n) << '\n';
        }
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