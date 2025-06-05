/*
    main idea..
        -Sparse Table
        -GCD
        -Binary search
*/
#include <bits/stdc++.h>
#include <unordered_map>
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
const int N = 2e5 + 5;
template <typename T = int  >struct Sparse_Table {
    struct Node {
        ll val;
        Node(ll v = 1e9) :val(v) {}
        Node operator = (const T& rhs) {
            val = rhs;
            return *this;
        }
    };
    int n, LOG;
    vector<vector<Node>>table;
    vector<int>Bin_Log;
    Node DEFAULT;
    Sparse_Table() {}
    Sparse_Table(const vector<T>& vec) {
        n = vec.size(), DEFAULT = 2e9, LOG = log2(n) + 1;
        table = vector<vector<Node>>(n + 10, vector<Node>(LOG));
        Bin_Log = vector<int>(n + 10);
        for (int i = 2; i <= n; i++) {
            Bin_Log[i] = Bin_Log[i / 2] + 1;
        }
        for (int i = 0; i < n; i++)
            table[i][0] = vec[i];
        Build_Table();
    }
    void init(const vector<T>& vec) {
        n = vec.size(), DEFAULT = 2e9, LOG = log2(n) + 1;
        table = vector<vector<Node>>(n + 10, vector<Node>(LOG));
        Bin_Log = vector<int>(n + 10);
        for (int i = 2; i <= n; i++) {
            Bin_Log[i] = Bin_Log[i / 2] + 1;
        }
        for (int i = 0; i < n; i++)
            table[i][0] = vec[i];
        Build_Table();
    }
    Node Merge(const Node& a, const Node& b) {
        return gcd(a.val, b.val);//returns max val
    }
    void Build_Table() {
        for (int log = 1; log < LOG; log++) {
            for (int i = 0; i + (1 << log) <= n; i++) {
                table[i][log] = Merge(table[i][log - 1], table[i + (1 << (log - 1))][log - 1]);
            }
        }
    }
    Node Query1(int l, int r) {
        int log = Bin_Log[r - l + 1];
        return Merge(table[l][log], table[r - (1 << log) + 1][log]);
    }
    Node Query_Log_N(int L, int R) {
        Node answer = DEFAULT;
        for (int log = LOG; log >= 0; log--) {
            if (L + (1 << log) <= R) {
                answer = Merge(answer, table[L][log]);
                L += 1 << log;
            }
        }
        return answer;
    }
};


void solve() {
    int n;
    cin >> n;
    vector<int>v(n);
    for (auto& i : v)
        cin >> i;
    for (int i = 0; i < n; i++)//for cycle queries
        v.push_back(v[i]);
    Sparse_Table<int>s(v);
    int res = 0;
    for (int i = 0; i < n; i++) {
        int l = i, r = n + i - 1, idx = -1;
        int gc = s.Query1(i, i + n - 1).val;
        while (l <= r) {
            int mid = l + r >> 1;
            if (s.Query1(i, mid).val <= gc) {
                r = mid - 1;
                idx = mid;
            }
            else
                l = mid + 1;
        }
        if (idx >= 0)
            res = max(res, idx - i);
    }
    cout << res << '\n';
}

int main() {
    Fast;
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
}