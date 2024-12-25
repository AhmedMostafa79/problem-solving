#include <bits/stdc++.h>
using namespace std;
#define  ll long long
#define  all(v) ((v).begin()),((v).end())
#define  rall(v) ((v).rbegin()),((v).rend())
#define Fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define files  freopen("closing.in", "r", stdin); freopen("closing.out", "w", stdout);
const int dx[] = { -1,0,1,0,1,-1,1,-1 };
const int dy[] = { 0,-1,0,1,1,-1,-1,1 };
const int di[] = { 'U','R','D','L' };
int countbit(ll n) { return (n > 1 ? (n & 1) + countbit(n >> 1) : n); }
ll gcd(ll x, ll y) { if (!y)return x; return gcd(y, x % y); }
ll lcm(ll x, ll y) { return x * y / gcd(x, y); }
const int N = 1e5 + 5;
struct node {
    int val;
    node() :val(0) {}
    node(int x) :val(x) {}
};
node merge(node c1, node c2) {
    node t = node();
    t.val = max(c1.val, c2.val);
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
int  get(int l, int r, int i, int lq, int rq, int val) {
    if (val > seg[i].val)
        return -1;
    if (l == r)
        return l + 1;
    int mid = l + r >> 1;
    int c1 = i * 2 + 1;
    int c2 = i * 2 + 2;
    if (seg[c1].val >= val) {
        return get(l, mid, c1, lq, rq, val);
    }
    //cout << c1 << " " << seg[c1].val<<'\n';
    return get(mid + 1, r, c2, lq, rq, val);
}
int get(int l, int r, int n, int val) {
    int res = get(0, n - 1, 0, l, r, val);
    return res;
}
void solve() {
    Fast;
    int n, q;
    cin >> n >> q;
    a = vector<int>(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    seg = vector<node>(n * 4, node());
    build(0, n - 1, 0);
    while (q--) {
        int i, v;
        cin >> v;
        int res = get(0, n - 1, n, v);
        cout << max(res, 0) << '\n';
        if (res > 0) {
            a[res - 1] -= v;
            //cout << a[res - 1] << '\n';
            update(0, n - 1, 0, res - 1, a[res - 1]);
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