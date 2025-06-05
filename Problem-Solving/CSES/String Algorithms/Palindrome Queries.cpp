#include<bits/stdc++.h>
using namespace std;
#define  ll long long
#define  all(v) ((v).begin()),((v).end())
#define  rall(v) ((v).rbegin()),((v).rend())
#define Fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define files  freopen("closing.in", "r", stdin); freopen("closing.out", "w", stdout);
const int N = 2e5 + 5, mod = 1e9 + 7, base = 31;
vector<ll>pw(N);
template<typename T = int, int Mode = 0>
struct Segment_Tree {

    struct Node {
        ll val;
        int len;

        Node(ll V = 0, int L = 0) : val(V), len(L) {}

        Node operator = (const T rhs) {
            val = rhs;
            len = 1;
            return *this;
        }
    };

    int size;
    Node DEFAULT;
    vector<Node> tree;

    void initialize(int n) {
        size = 1, DEFAULT = Node(0, 0);
        while (size < n) size *= 2;
        tree = vector<Node>(2 * size, DEFAULT);
    }

    Segment_Tree(int n) {
        initialize(n);
    }
    Node operation(Node a, Node b) {
        ll combinedHash = (a.val * powMod(base, b.len, mod) + b.val) % mod;
        return Node(combinedHash, a.len + b.len);
    }

    ll powMod(ll base, ll exp, ll mod) {
        ll res = 1;
        while (exp > 0) {
            if (exp & 1) res = (res * base) % mod;
            base = (base * base) % mod;
            exp >>= 1;
        }
        return res;
    }

    // If Mode is 1, the array is 1-based; else it is 0-based
    void build(vector<T>& nums, int idx, int lx, int rx) {
        if (Mode ? lx >= nums.size() : lx > nums.size()) return;
        if (rx == lx) tree[idx] = Node(nums[lx - !Mode], 1); // Single char hash
        else {
            int m = (rx + lx) / 2;
            build(nums, 2 * idx, lx, m);
            build(nums, 2 * idx + 1, m + 1, rx);
            tree[idx] = operation(tree[2 * idx], tree[2 * idx + 1]);
        }
    }

    void build(vector<T>& nums) {
        build(nums, 1, 1, size);
    }

    void update(int i, T v, int idx, int lx, int rx) {
        if (rx == lx) tree[idx] = Node(v, 1);
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


ll get_substr(int i, int j, const vector<ll>& h,
    const vector<ll>& pw) {//gets substr in range[i,j]
    return (h[j] - (h[i] * pw[j - i]) % mod + mod) % mod;
}

int n, m;
void compute_pref(const string& s, vector<ll>& v) {
    for (int i = 1; i <= n; i++) {
        v[i] = (v[i - 1] * base) % mod + (s[i - 1] - 'a');
        v[i] %= mod;
    }
}
void pre(vector<ll>& pw) {
    pw[0] = 1;
    for (int i = 1; i < N; i++) {
        pw[i] = (pw[i - 1] * base) % mod;

    }
};

void solve() {
    cin >> n >> m;
    string s;
    cin >> s;
    //s = ' ' + s;
    vector<ll> pref(n + 1),
        suff(n + 1);
    pre(pw);
    string s2 = s;
    reverse(all(s2));
    Segment_Tree<ll, 1>seg1(n + 1), seg2(n + 1);
    for (int i = 1; i <= n; i++) {
        seg1.update(i, s[i - 1] - 'a');
        seg2.update(i, s2[i - 1] - 'a');
    }
    auto  get_query = [&](int i, int j, Segment_Tree<ll, 1>& seg) {
        ll l = seg.query(1ll, i);
        ll r = seg.query(1ll, j);
        ll res = ((r - l * pw[j - i]) % mod + mod) % mod;
        return res;
        };
    while (m--) {
        int t;
        cin >> t;
        if (t == 1) {
            int i;
            char c;
            cin >> i >> c;
            seg1.update(i, c - 'a');
            seg2.update(n - i + 1, c - 'a');
        }
        else {
            int i, j;
            cin >> i >> j;
            int h1 = get_query(i, j, seg1);
            int h2 = get_query(n - j + 1, n - i + 1, seg2);
            if (h1 == h2)
                cout << "YES\n";
            else cout << "NO\n";
        }
    }
}
int main() {
    Fast;
    int t = 1;
    // cin >> t;
    for (int i = 1; i <= t; i++) {
        solve();
    }
    return 0;
}
