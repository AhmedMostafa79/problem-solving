#include <bits/stdc++.h>
using namespace std;
#define  ll long long 
#define  all(v) ((v).begin()),((v).end())
#define  rall(v) ((v).rbegin()),((v).rend())
#define Fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define close(n) return cout<<n,0;
#define files  freopen("moocast.in", "r", stdin); freopen("moocast.out", "w", stdout);
const int dx[] = { -1,0,1,0,1,-1,1,-1 };
const int dy[] = { 0,1,0,-1,1,-1,-1,1 };
const int di[] = { 'U','R','D','L' };
int countbit(ll n) { return (n > 1 ? (n & 1) + countbit(n >> 1) : n); }
ll gcd(ll x, ll y) { if (!y)return x; return gcd(y, x % y); }
ll lcm(ll x, ll y) { return x * y / gcd(x, y); }
const int N = 1e6 + 3, mod = 1e9 + 7;
template<typename T = int>class SegmentTree {
    struct  Node {
        int l, r, sum;
        Node(ll val = 0) {
            sum = 0;
            l = (val == 1);
            r = (val == 2);
        }
        void change(ll val = 0) {
            sum = 0;
            l = (val == 1);
            r = (val == 2);
        }
    };
    vector<Node>tree;
    int size;
    Node merge(Node a, Node b) {
        Node temp;
        int x = min(a.l, b.r);
        temp.sum = a.sum + b.sum + x;
        a.l -= x;
        b.r -= x;
        temp.l = a.l + b.l;
        temp.r = a.r + b.r;
        return temp;
    }
    void build(int l, int r, int i, const vector<T>& values) {
        if (l == r) {
            if (l < values.size())
                tree[i] = Node(values[l]);
            return;
        }
        int mid = (l + r) / 2;
        build(l, mid, i * 2 + 1, values);
        build(mid + 1, r, i * 2 + 2, values);
        tree[i] = merge(tree[i * 2 + 1], tree[i * 2 + 2]);
    }

    void update(int l, int r, int i, int idx, T val) {
        if (l == r) {
            tree[i].change(val);
            return;
        }
        int mid = (l + r) / 2;
        if (idx <= mid)//go left
            update(l, mid, i * 2 + 1, idx, val);
        else
            update(mid + 1, r, i * 2 + 2, idx, val);
        tree[i] = merge(tree[i * 2 + 1], tree[i * 2 + 2]);
    }
    Node query(int l, int r, int i, int lq, int rq) {
        if (rq < l or r < lq)
            return Node();
        if (lq <= l and r <= rq)
            return tree[i];
        int mid = (l + r) / 2;
        Node ret_l = query(l, mid, i * 2 + 1, lq, rq);
        Node ret_r = query(mid + 1, r, i * 2 + 2, lq, rq);
        return merge(ret_l, ret_r);
    }
public:
    SegmentTree(int n) {
        size = 1;
        while (size < n)
            size *= 2;
        tree = vector<Node>(2 * size, Node());
    }
    void init(const vector<T>& v) {
        build(0, size - 1, 0, v);
    }
    ll query(int lq, int rq) {
        return query(0, size - 1, 0, lq, rq).sum;
    }
    void update(int i, int val) {
        update(0, size - 1, 0, i, val);
    }
};

void solve() {
    string s;
    cin >> s;
    SegmentTree<int>seg((int)s.size());

    int m;
    cin >> m;
    for (int i = 0; i < s.size(); i++) {
        int c = (s[i] == '(' ? 1 : 2);
        seg.update(i, c);
    }

    while (m--) {
        int l, r;
        cin >> l >> r;
        l--, r--;
        cout << seg.query(l, r) * 2 << '\n';
    }


}
int main() {
    Fast;
    int T = 1;
    //cin >> T;
    for (int i = 1; i <= T; i++) {
        //cout << "Case " << i << ":\n";
        solve();
        //if (T)
            //cout << '\n';
    }
}