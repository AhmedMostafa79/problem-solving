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
int n;
struct node {
    int   val, type, pos, l, r;
    /* node() {
         l = r =  val = pos = 0;
     }*/
};
vector<int>seg;
vector<node>table;
bool cmp(node t1, node t2) {
    if (t1.val != t2.val)
        return t1.val > t2.val;
    return t1.type > t2.type;
}
void update(int l, int r, int i, int idx, int v) {
    if (l == r) {
        seg[i] += v;
        return;
    }
    int mid = l + r >> 1;
    int c1 = i * 2 + 1;
    int c2 = i * 2 + 2;
    if (idx <= mid)// in Left sub-tree
        update(l, mid, c1, idx, v);
    else
        update(mid + 1, r, c2, idx, v);
    seg[i] = seg[c1] + seg[c2];
}
int  get(int l, int r, int i, int lq, int rq) {
    if (lq > r or rq < l or r < l) {
        return 0;
    }
    if (lq <= l and r <= rq)
        return seg[i];
    int mid = l + r >> 1;
    int c1 = i * 2 + 1;
    int c2 = i * 2 + 2;
    int L = get(l, mid, c1, lq, rq);
    int R = get(mid + 1, r, c2, lq, rq);
    return L + R;
}
int get(int l, int r) {
    return get(0, n - 1, 0, l, r);
}
void solve() {
    Fast;
    cin >> n;
    seg.resize(n * 4);
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        node t;
        t.val = x;
        t.pos = i;
        t.type = 1;
        table.push_back(t);
    }
    int q;
    cin >> q;
    for (int i = 0; i < q; i++) {
        int l, r, val;
        cin >> l >> r >> val;
        node t;
        t.l = l;
        t.r = r;
        t.val = val;
        t.type = 2;
        t.pos = i;
        table.push_back(t);
    }
    vector<int>res(q);
    sort(all(table), cmp);
    for (auto i : table) {
        if (i.type == 1) {
            update(0, n - 1, 0, i.pos, 1);
        }
        else {
            int ans = get(0, n - 1, 0, i.l - 1, i.r - 1);
            res[i.pos] = ans;
        }
    }
    for (auto i : res)
        cout << i << "\n";
    cout << '\n';
}
int main() {
    Fast;
    int t = 1;
    //cin >> t;
    while (t--) {
        solve();
    }
}