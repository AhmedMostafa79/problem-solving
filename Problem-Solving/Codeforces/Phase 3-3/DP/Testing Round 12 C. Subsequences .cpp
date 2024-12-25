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
const ll N = 80 + 1, MOD = 998244353;
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
void solve() {
    int n, k;
    cin >> n >> k;
    vector<int>v(n);
    for (auto& i : v)
        cin >> i;
    k++;
    vector<Segment_Tree<ll>>seg(k + 1, Segment_Tree<ll>(n));
    vector<vector<ll>>dp(n + 1, vector<ll>(k + 1));
    for (int i = 0; i < n; i++) {
        dp[i][1] = 1;//each a[i] has 1 subsequence of len 1
        for (int j = 2; j <= k; j++) {
            dp[i][j] = seg[j - 1].query(1, v[i] - 1);
        }
        for (int j = 1; j <= k; j++) {
            seg[j].update(v[i], dp[i][j]);//a subseq of len j = subseq of len j-1 for all v[i] > v[j]
        }
    }
    ll res = 0;
    // as we calculated all k for each value v[i],
    // so we need to accumulate all subseq of len k
    for (int i = 0; i < n; i++) {
        res += dp[i][k];
    }
    cout << res << '\n';
}
int main() {
    Fast;
    int t = 1;
    //cin >> t;
    for (int i = 1; i <= t; i++) {
        //cout << "Case " << i << ": ";
        solve();
        cout << "\n";

    }
}