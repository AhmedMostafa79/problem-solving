/*
atcoder contest 294 G - Distance Queries on a Tree

        Category: Data Structures

        Keys: Tree Flattening, Segment Tree
*/

#include<bits/stdc++.h>
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
const ll N = 2e5 + 5, MOD = 998244353, LOG = 20;
template < typename T = int, int Mode = 0 > struct Segment_Tree {

    struct Node {

        ll val;

        Node(ll V = 0) : val(V) {}

        Node operator = (const T rhs) {
            val = rhs;
            return *this;
        }

    };

    int size;
    Node DEFAULT;
    vector < Node > tree;

    void intial(int n) {
        size = 1, DEFAULT = 0;
        while (size < n) size *= 2;
        tree = vector < Node >(2 * size, DEFAULT);
    }

    Segment_Tree(int n) {
        intial(n);
    }

    // Main operation to do

    Node operation(Node a, Node b) {
        return Node(a.val + b.val);
    }

    // If Mode is 1 so the array is 1-based else the array is 0-based

    void build(vector < T >& nums, int idx, int lx, int rx) {
        if (Mode ? lx >= sz(nums) : lx > sz(nums)) return;
        if (rx == lx) tree[idx] = nums[lx - !Mode];
        else {
            int m = (rx + lx) / 2;
            build(nums, 2 * idx, lx, m);
            build(nums, 2 * idx + 1, m + 1, rx);
            tree[idx] = operation(tree[2 * idx], tree[2 * idx + 1]);
        }
    }

    void build(vector < T >& nums) {
        build(nums, 1, 1, size);
    }

    void update(int i, T v, int idx, int lx, int rx) {
        if (rx == lx) tree[idx] = v;
        else {
            int m = (rx + lx) / 2;
            if (i <= m) update(i, v, 2 * idx, lx, m);
            else update(i, v, 2 * idx + 1, m + 1, rx);
            tree[idx] = operation(tree[2 * idx], tree[2 * idx + 1]);
        }
    }

    void update(int i, T v) {
        update(i, v, 1, 1, size);
    }

    Node query(int l, int r, int idx, int lx, int rx) {
        if (lx > r || l > rx) return DEFAULT;
        if (lx >= l && rx <= r) return tree[idx];
        int m = (lx + rx) / 2;
        return operation(query(l, r, 2 * idx, lx, m), query(l, r, 2 * idx + 1, m + 1, rx));
    }

    ll query(int l, int r) {
        return query(l, r, 1, 1, size).val;
    }

};

vector<vector<int>>adj;
int st[N], en[N], timer, depth[N];
int anc[N][LOG];
void dfs(int i, int p) {
    st[i] = ++timer;
    depth[i] = depth[p] + 1;
    anc[i][0] = p;
    for (int j = 1; j < LOG; j++) {
        int up = anc[i][j - 1];
        anc[i][j] = anc[up][j - 1];
    }
    for (auto j : adj[i]) {
        if (p != j) {
            dfs(j, i);
        }
    }
    en[i] = ++timer;
}
int kth_ancestor(int u, int k) {
    if (depth[u] < k) return -1;
    for (int bit = 0; bit < LOG; bit++)
        if (k & (1 << bit))
            u = anc[u][bit];
    return u;
}

int get_lca(int u, int v) {
    if (depth[u] < depth[v])
        swap(u, v);

    u = kth_ancestor(u, depth[u] - depth[v]);
    if (u == v) return u;

    for (int bit = LOG - 1; bit >= 0; bit--)
        if (anc[u][bit] != anc[v][bit])
            u = anc[u][bit], v = anc[v][bit];

    return anc[u][0];
}
void solve() {
    int n, m;
    cin >> n;

    vector<ll>w(n + 1);

    adj = vector<vector<int>>(n + 1, vector<int>());
    vector<pair<pair<int, int>, int>>edg(n + 1);
    for (int i = 1; i < n; i++) {
        int x, y, w;
        cin >> x >> y >> w;
        edg[i] = { {x,y} ,w };
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    dfs(1, 0);
    //we will re assign weights of edges to children
    // as each child has only single parent,means single weight,
    // if we reverse the operation, so the w[i] will be overitten
    for (int i = 1; i < n; i++) {
        int x = edg[i].first.first, y = edg[i].first.second;
        if (depth[x] < depth[y])
            w[y] = edg[i].second;
        else
            w[x] = edg[i].second;
    }
    Segment_Tree<ll>seg(n * 2);

    for (int i = 1; i <= n; i++) {
        seg.update(st[i], w[i]);
        seg.update(en[i], -w[i]);
    }

    cout << "\n\n";
    cin >> m;
    while (m--) {
        int t;
        cin >> t;
        if (t == 1) {
            int i, v;
            cin >> i >> v;
            int x = edg[i].first.first, y = edg[i].first.second;
            if (depth[x] < depth[y])
                i = y;
            else
                i = x;
            w[i] = v;
            seg.update(st[i], v);
            seg.update(en[i], -v);
        }
        else {
            int u, v;
            cin >> u >> v;
            if (u == v) { cout << 0 << '\n'; continue; }

            int lc = get_lca(u, v);
            ll ret = seg.query(st[lc], st[u]) +
                seg.query(st[lc], st[v]) - w[lc] * 2;
            cout << ret << '\n';
        }
    }
}
int main() {
    Fast;
    int t = 1;
    //cin >> t;
    for (int i = 1; i <= t; i++) {
        //cout << "Case " << i << ": ";
        solve();
    }
}