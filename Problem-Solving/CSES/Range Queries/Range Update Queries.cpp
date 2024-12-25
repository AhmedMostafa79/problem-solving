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
const int N = 1e5 + 5, mod = 1e9 + 7;;
vector<int>a;
struct node {
    ll val, lazy;
    bool is_lazy;
    node(ll x = 0) {
        val = x;
        lazy = 0;
        is_lazy = 0;
    }
    void change(int l, int r, ll x) {
        val += (r - l + 1) * 1ll * x;
        lazy += x;
        is_lazy = 1;
    }
};
vector<node>seg;
node merge(node c1, node c2) {
    node t = node();
    t.val = c1.val + c2.val;
    return t;
}
void propagate(int l, int r, int i) {
    if (!seg[i].is_lazy or l == r)
        return;
    int mid = l + r >> 1;
    seg[i * 2 + 1].change(l, mid, seg[i].lazy);
    seg[i * 2 + 2].change(mid + 1, r, seg[i].lazy);
    seg[i].lazy = 0;
    seg[i].is_lazy = 0;
}
void build(int l, int r, int i) {
    if (l == r) {
        if (l < a.size())
            seg[i] = node(a[l]);
        return;
    }
    int mid = l + r >> 1;
    build(l, mid, i * 2 + 1);
    build(mid + 1, r, i * 2 + 2);
    seg[i] = merge(seg[i * 2 + 1], seg[i * 2 + 2]);

}

void update(int l, int r, int i, int lq, int rq, int v) {
    propagate(l, r, i);
    if (l > rq or r < lq)
        return;
    if (lq <= l and r <= rq) {
        seg[i].change(l, r, v);
        return;
    }
    int mid = l + r >> 1;
    update(l, mid, i * 2 + 1, lq, rq, v);
    update(mid + 1, r, i * 2 + 2, lq, rq, v);
    seg[i] = merge(seg[i * 2 + 1], seg[i * 2 + 2]);
}
node get(int l, int r, int i, int lq, int rq) {
    propagate(l, r, i);
    if (l > rq or r < lq)
        return node();
    if (lq <= l and r <= rq) {
        return seg[i];
    }
    int mid = l + r >> 1;
    node L = get(l, mid, i * 2 + 1, lq, rq);
    node R = get(mid + 1, r, i * 2 + 2, lq, rq);
    return merge(L, R);
}
void update(int l, int r, int v) {
    return update(0, a.size() - 1, 0, l, r, v);
}
ll get(int i) {
    return get(0, a.size() - 1, 0, i, i).val;
}
void solve() {
    Fast;
    int n, q;
    cin >> n >> q;
    a = vector<int>(n);
    seg.assign(n * 4, node());
    for (auto& i : a)
        cin >> i;
    build(0, n - 1, 0);
    while (q--) {
        int t;
        cin >> t;
        if (t == 1) {
            int l, r, v;
            cin >> l >> r >> v;
            update(l - 1, r - 1, v);
        }
        else {
            int i;
            cin >> i;
            cout << get(i - 1) << '\n';
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