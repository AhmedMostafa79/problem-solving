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
int n, q;
struct node {
    ll val, lazy;
    bool is_lazy;
    node(ll x = 1e15) {
        val = x;
        lazy = 0;
        is_lazy = 0;
    }
    void change(int l, int r, ll x) {
        val = x;//increase x to all range(l,r) values
        lazy = x;
        is_lazy = 1;
    }
};
vector<node>seg;
node merge(const node& c1, const node& c2) {
    node temp = node();
    temp.val = min(c1.val, c2.val);
    return temp;
}
void propagate(int l, int r, int i) {
    if (!seg[i].is_lazy or l == r)
        return;
    int c1 = i * 2 + 1;
    int c2 = i * 2 + 2;
    int mid = l + r >> 1;
    seg[c1].change(l, mid, seg[i].lazy);
    seg[c2].change(mid + 1, r, seg[i].lazy);
    seg[i].lazy = 0;
    seg[i].is_lazy = 0;
}
void build(int l, int r, int i) {
    if (l == r) {
        if (l < n)
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
void update(int l, int r, int i, int lq, int rq, int v) {
    propagate(l, r, i);
    if (lq <= l and r <= rq) {
        seg[i].change(l, r, v);
        return;
    }
    if (rq<l or lq>r)
        return;
    int mid = l + r >> 1;
    int c1 = i * 2 + 1;
    int c2 = i * 2 + 2;
    update(l, mid, c1, lq, rq, v);
    update(mid + 1, r, c2, lq, rq, v);
    seg[i] = merge(seg[c1], seg[c2]);
}
node get(int l, int r, int i, int lq, int rq) {
    propagate(l, r, i);
    if (lq <= l and r <= rq)
        return seg[i];
    if (rq<l or lq>r)
        return node();
    int mid = l + r >> 1;
    int c1 = i * 2 + 1;
    int c2 = i * 2 + 2;
    node L = get(l, mid, c1, lq, rq);
    node R = get(mid + 1, r, c2, lq, rq);
    return merge(L, R);
}
ll get(int l, int r) {
    return get(0, n - 1, 0, l, r).val;
}
void solve() {
    Fast;
    cin >> n >> q;
    a = vector<int>(n);
    int sz = 1;
    while (sz < n)
        sz *= 2;
    seg = vector<node>(sz * 2);
    //for (auto& i : a)
        //cin >> i;
    build(0, n - 1, 0);
    while (q--) {
        int t;
        cin >> t;
        if (t == 1) {
            int l, r, v;
            cin >> l >> r >> v;
            update(0, n - 1, 0, l, r - 1, v);
        }
        else {
            int l, r;
            cin >> l >> r;
            cout << get(l, r - 1) << '\n';
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