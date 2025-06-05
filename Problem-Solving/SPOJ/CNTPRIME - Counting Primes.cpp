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
        ll val, lazy;
        bool is_lazy;
        Node(ll v = 0) :val(v) {
            lazy = is_lazy = 0;
        }
        void change(ll val, int l, int r) {
            this->val = val * (r - l + 1);//value of  current node;
            lazy = val;//carry of current node that needs propagation
            is_lazy = 1;
        }
    };

    vector<Node>tree;
    int size;
    Node merge(const Node& a, const Node& b) {
        return Node(a.val + b.val);
    }
    void propagate(int i, int l, int r) {
        if (!tree[i].is_lazy or l == r)//no carry or is_leaf
            return;
        int mid = (l + r) / 2;
        tree[i * 2 + 1].change(tree[i].lazy, l, mid);
        tree[i * 2 + 2].change(tree[i].lazy, mid + 1, r);
        tree[i].lazy = 0;
        tree[i].is_lazy = 0;
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

    void update(int l, int r, int i, int lq, int rq, T val) {
        propagate(i, l, r);
        if (lq <= l and r <= rq) {
            tree[i].change(val, l, r);
            return;
        }
        if (rq < l or r < lq)
            return;
        int mid = (l + r) / 2;

        update(l, mid, i * 2 + 1, lq, rq, val);
        update(mid + 1, r, i * 2 + 2, lq, rq, val);
        tree[i] = merge(tree[i * 2 + 1], tree[i * 2 + 2]);
    }
    Node query(int l, int r, int i, int lq, int rq) {
        propagate(i, l, r);
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
        return query(0, size - 1, 0, lq, rq).val;
    }
    void update(int l, int r, int val) {
        update(0, size - 1, 0, l, r, val);
    }
};
bool isprime[N];
void seive(int n) {
    memset(isprime, 1, sizeof isprime);
    isprime[1] = 0;
    for (int i = 2; i * i <= n; i++) {
        if (!isprime[i])
            continue;
        for (int j = i * 2; j <= n; j += i)
            isprime[j] = 0;
    }

}
void solve() {
    int n, m;
    cin >> n >> m;
    vector<int>v(n);
    for (auto& i : v) {
        cin >> i;
        i = isprime[i];
    }
    SegmentTree<int>seg(n);
    seg.init(v);
    while (m--) {
        int t, l, r;
        cin >> t >> l >> r;
        l--, r--;
        if (t == 0) {
            int x;
            cin >> x;
            seg.update(l, r, isprime[x]);
        }
        else {
            cout << seg.query(l, r) << '\n';
        }
    }
}
int main() {
    Fast;
    int T = 1;
    cin >> T;
    seive(1e6);
    for (int i = 1; i <= T; i++) {
        cout << "Case " << i << ":\n";
        solve();
        if (T)
            cout << '\n';
    }
}