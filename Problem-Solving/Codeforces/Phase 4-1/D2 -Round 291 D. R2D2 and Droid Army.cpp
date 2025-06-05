/*
    main idea..
        -Sparse table 
        -Two pointers

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
        return max(a.val, b.val);//returns max val
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
    int n, m, k;
    cin >> n >> m >> k;
    vector<vector<int>>v(m, vector<int>(n));
    for (int j = 0; j < n; j++) {
        for (int i = 0; i < m; i++)
            cin >> v[i][j];
    }
    Sparse_Table<int>s[5];
    for (int i = 0; i < m; i++) {
        s[i].init(v[i]);
    }
    vector<int>res(m);
    int mx = 0;
    auto valid = [&](int i, int j) {
        ll sum = 0;
        j = min(j, n - 1);
        for (int r = 0; r < m; r++) {
            sum += s[r].Query1(i, j).val;
        }
        return sum <= k;
        };


    for (int i = 0, j = 0; i < n; i++) {
        j = max(j, i);
        while (j < n and valid(i, j)) {
            j++;
        }
        if (j - i > mx) {
            mx = j - i;
            for (int r = 0; r < m; r++) {
                res[r] = s[r].Query1(i, j - 1).val;
            }
        }
    }
    for (auto i : res)
        cout << i << " ";

}

int main() {
    Fast;
    int t = 1;
    //cin >> t;
    while (t--) {
        solve();
    }
}