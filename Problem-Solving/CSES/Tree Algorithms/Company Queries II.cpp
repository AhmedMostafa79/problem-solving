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
const ll N = 2e5 + 5, mod = 1e9 + 7, LOG = 30;
int n, q;
int ar[N][LOG];
vector<vector<int>>v;
int dep[N];
void dfs(int cur, int p) {
    for (auto i : v[cur]) {
        if (i == p)
            continue;
        dep[i] = dep[cur] + 1;
        ar[i][0] = cur;
        for (int j = 1; j < LOG; j++) {
            ar[i][j] = ar[ar[i][j - 1]][j - 1];
        }
        dfs(i, cur);
    }
}
int Get_Kth(int x, int k) {
    for (int i = LOG - 1; i >= 0; i--) {
        if ((k >> i) & 1) {
            x = ar[x][i];
        }
    }
    return x;
}
int Get_LCA(int a, int b) {
    if (dep[a] > dep[b])
        swap(a, b);
    b = Get_Kth(b, dep[b] - dep[a]);
    if (a == b)
        return a;
    for (int i = LOG - 1; i >= 0; i--) {
        if (ar[a][i] != ar[b][i]) {
            a = ar[a][i];
            b = ar[b][i];
        }
    }
    return ar[a][0];
}
void solve() {
    Fast;
    cin >> n >> q;
    v = vector<vector<int>>(n + 1, vector<int>());
    for (int i = 2; i <= n; i++) {
        int x;
        cin >> x;
        v[i].push_back(x);
        v[x].push_back(i);
    }
    dfs(1, 0);
    while (q--) {
        int a, b;
        cin >> a >> b;
        cout << Get_LCA(a, b) << '\n';
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