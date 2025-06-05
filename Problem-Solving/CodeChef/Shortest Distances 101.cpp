/*
    main idea..
        -Sparse Table.
        -Binary Lifting 
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
        ll val, idx;
        Node(ll v = 0, int idx = 0) :val(v), idx(idx) {}
        Node operator = (const Node& other) {
            val = other.val;
            idx = other.idx;
            return *this;
        }
        Node operator = (const T& other) {
            val = other.first;
            idx = other.second;
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
    Node Merge(const Node& a, const Node& b) {
        if (a.val != b.val)
            return a.val > b.val ? a : b;
        else return a.idx > b.idx ? a : b;
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
    int n, m;
    cin >> n >> m;
    vector<int>v(n);
    vector<pair<int, int>>vec(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
        vec[i] = { v[i] + i,i };
    }
    Sparse_Table<pair<int, int>>s(vec);
    vector<vector<int>>lift(n, vector<int>(21));
    for (int i = 0; i < n; i++) {
        auto q = s.Query1(i, min(n - 1, i + v[i]));
        lift[i][0] = q.idx;
    }
    for (int j = 1; j <= 20; j++) {
        for (int i = 0; i < n; i++) {
            lift[i][j] = lift[lift[i][j - 1]][j - 1];
        }
    }

    while (m--) {
        int l, r;
        cin >> l >> r;
        l--, r--;
        if (r < l)
            cout << -1;
        else if (r == l)
            cout << 0;
        else if (l + v[l] >= r)
            cout << 1;
        else {
            int res = 0;
            for (int i = 20; i >= 0; i--) {
                if (lift[lift[l][i]][0] < r) {//i need last step to be exactly before r
                    l = lift[l][i];
                    res += (1 << i);
                }
            }
            if (l + v[l] >= r)
                cout << res + 1;
            else if (lift[l][0] + v[lift[l][0]] >= r)
                cout << res + 2;
            else cout << -1;
        }
        cout << '\n';
    }

}

int main() {
    Fast;
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
}