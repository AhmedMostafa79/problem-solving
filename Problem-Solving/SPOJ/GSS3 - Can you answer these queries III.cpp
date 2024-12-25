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
vector<int>a;
int n, q;
struct node {
    ll sum, pref, suf, mx;
    node() {
        suf = pref = mx = -1e15;
        sum = 0;
    }
    node(ll x) {
        sum = mx = suf = pref = x;
    }
    void change(ll x) {
        sum = mx = suf = pref = x;
    }
};
vector<node>seg;
node merge(const node& c1,const node& c2) {
    node temp = node();
    temp.sum = c1.sum + c2.sum;
    temp.pref = max(c1.pref, c1.sum + c2.pref);
    temp.suf = max(c2.suf, c2.sum + c1.suf);
    temp.mx = max({ c1.mx,c2.mx,c1.suf + c2.pref });
    return temp;
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
void update(int l, int r, int i, int idx, int v) {
    if ( l==r) {
        seg[i].change(v);
        return;
    }
    int mid = l + r >> 1;
    int c1 = i * 2 + 1;
    int c2 = i * 2 + 2;
    if (mid<idx)
        update(mid + 1, r, c2, idx, v);
    else
        update(l, mid, c1, idx, v);
    seg[i] = merge(seg[c1], seg[c2]);
}
node get(int l, int r, int i, int lq, int rq) {
    if (rq<l or lq>r)
        return node();
    if ( lq<=l and r<=rq)
        return seg[i];
    int mid = l + r >> 1;
    int c1 = i * 2 + 1;
    int c2 = i * 2 + 2;
    node L = get(l, mid, c1, lq, rq);
    node R = get(mid + 1, r, c2, lq, rq);
    return merge(L, R);
}
ll res(int l,int r) {
    return get(0, n - 1, 0, l, r).mx;
}
void solve() {
    Fast;
    cin >> n;
    a = vector<int>(n);
    int sz = 1;
    while (sz < n)
        sz *= 2;
    seg.assign(sz*2+2,node());
    for (auto& i : a)
        cin >> i;
    build(0, n - 1, 0);
    cin>>q;
    while (q--) {
        int t;
        cin>>t;
        if(t==0){
            int i, v;
            cin >> i >> v;
            i--;
            update(0, n - 1, 0, i, v);
        }
        else {
            int l,r;
            cin>>l>>r;
            l--,r--;
            cout << res(l,r) << '\n';
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