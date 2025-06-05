/*
    main idea..
        -coordinates compression.
        -Sparse table for min.

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
    Node Merge(const Node& a, const Node& b) {
        return min(a.val, b.val);//returns max val
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
    vector<pair<int, int>>v(n);
    vector<int>comp;
    for (auto& i : v) {
        cin >> i.first >> i.second;
        comp.push_back(i.first);
        comp.push_back(i.second);
        comp.push_back(i.second + 1);
    }
    sort(all(comp));
    comp.erase(unique(all(comp)), comp.end());
    vector<int>pre(comp.size() + 1);
    for (auto i : v) {
        int l = lower_bound(all(comp), i.first) - comp.begin();
        int r = lower_bound(all(comp), i.second + 1) - comp.begin();
        //we use coordinate compression by giving each number a unique id.. that is considered its new range..
        // so before if we were in a segment [l,r]..we look if we end it befor next l  or they overlapp
        //if we have l  and r like (l1,r1) 1e6-1e7  and (l2,r2) 1e6+5-1e7+5..
        // we use pre[1e6]++,pre[1e7+1]--, as it must be decremented by 1 before start of 1e7+5..so we used pre[i.second+1]--; 
        pre[l]++;
        pre[r]--;
    }
    for (int i = 1; i < pre.size(); i++) {
        pre[i] += pre[i - 1];
    }
    Sparse_Table<int>s(pre);
    for (int i = 0; i < v.size(); i++) {
        int l = lower_bound(all(comp), v[i].first) - comp.begin();
        int r = lower_bound(all(comp), v[i].second) - comp.begin();
        if (s.Query1(l, r).val > 1)
            return void(cout << i + 1 << '\n');
    }
    cout << "-1\n";
}

int main() {
    Fast;
    int t = 1;
    //cin >> t;
    while (t--) {
        solve();
    }
}