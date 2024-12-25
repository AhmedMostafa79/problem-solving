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
const ll N = 2e5 + 5, mod = 1e9 + 7;

template < typename treeType = int, typename graphType = int >
class LCA {
public:
    LCA(
        int n = 0,
        const vector < vector < pair < int, graphType > > >& G = {},
        function < treeType(treeType, treeType) > op = [](treeType a, treeType b) { return a + b; },
        treeType _neutral = treeType(),
        int root = 1
    ) : N(n), LOG(0), ROOT(root), adj(G), operation(op), neutral(_neutral) {
        while ((1 << LOG) <= N) LOG++;
        anc.assign(N + 5, vector < int >(LOG));
        cost.assign(N + 5, vector < treeType >(LOG, neutral));
        depth.assign(N + 5, 0);
        dfs(ROOT);
    }

    int kth_ancestor(int u, int k) const {
        if (depth[u] < k) return -1;
        for (int bit = 0; bit < LOG; bit++)
            if (k & (1 << bit))
                u = anc[u][bit];
        return u;
    }

    int get_lca(int u, int v) const {
        if (depth[u] < depth[v]) swap(u, v);

        u = kth_ancestor(u, depth[u] - depth[v]);
        if (u == v) return u;

        for (int bit = LOG - 1; bit >= 0; bit--)
            if (anc[u][bit] != anc[v][bit])
                u = anc[u][bit], v = anc[v][bit];

        return anc[u][0];
    }
    int get_dist(int a, int b) {
        return abs(depth[b] - depth[a]);
    }
    treeType query(int u, int v) const {
        int lca = get_lca(u, v);
        return operation(get_cost(u, depth[u] - depth[lca]), get_cost(v, depth[v] - depth[lca]));
    }
private:
    int N, LOG, ROOT;
    const vector < vector < pair < int, graphType > > >& adj;
    vector < vector < int > > anc;
    vector < vector < treeType > > cost;
    vector < int > depth;
    function < treeType(treeType, treeType) > operation;
    treeType neutral;

    void dfs(int u, int p = 0) {
        for (auto& x : adj[u]) {
            int v = x.first, w = x.second;
            if (v == p) continue;
            depth[v] = depth[u] + 1;
            anc[v][0] = u;
            cost[v][0] = treeType(w);
            for (int bit = 1; bit < LOG; bit++) {
                anc[v][bit] = anc[anc[v][bit - 1]][bit - 1];
                cost[v][bit] = operation(cost[v][bit - 1], cost[anc[v][bit - 1]][bit - 1]);
            }
            dfs(v, u);
        }
    }

    treeType get_cost(int u, int dist) const {
        if (depth[u] < dist) return neutral;
        treeType ret = neutral;
        for (int bit = 0; bit < LOG; bit++) {
            if (dist & (1 << bit)) {
                ret = operation(ret, cost[u][bit]);
                u = anc[u][bit];
            }
        }
        return ret;
    }
};

struct Edge {
    int mn, mx;
    Edge(int x) {
        mx = mn = x;
    }
    Edge(int mn, int mx) : mn(mn), mx(mx) {}
};

Edge merge(const Edge& a, const Edge& b) {
    int mx = max(a.mx, b.mx);
    int mn = min(a.mn, b.mn);
    return Edge(mn, mx);
}
void solve() {
    int n;
    cin >> n;
    if (!n)
        exit(0);
    vector<vector<pair<int, int>>>adj(n + 5, vector<pair<int, int>>());
    for (int i = 1; i < n; i++) {
        int x, y;
        cin >> x >> y;
        adj[x].push_back({ y,0 });
        adj[y].push_back({ x,0 });
    }
    LCA < Edge, int > lca(n, adj, [](const Edge& a, const Edge& b) { return merge(a, b); }, Edge(1e9, -1e9));

    int q;
    cin >> q;
    while (q--) {
        int x, y;
        cin >> x >> y;
        swap(x, y);
        int d1 = lca.get_dist(x, 1);
        int d2 = lca.get_dist(y, 1);
        if (d1 > d2)
            cout << "NO\n";
        else cout << "YES " << lca.get_lca(x, y) << '\n';
    }
}
int main() {
    Fast;
    int t = 1;
    //cin >> t;
    for (int i = 1; i <= t; i++) {
        //cout << "Case " << i << ":\n";
        solve();
        cout << '\n';
    }
}