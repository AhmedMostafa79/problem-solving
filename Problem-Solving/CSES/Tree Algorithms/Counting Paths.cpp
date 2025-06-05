#include <bits/stdc++.h>
using namespace std;
#define  ll long long 
#define  all(v) ((v).begin()),((v).end())
#define  rall(v) ((v).rbegin()),((v).rend())
#define Fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
const int N = 2e5 + 5;
template<typename T>
class LCA {
    struct Node {
        ll val;
        Node() {
            val = 0;
        }
        Node(ll v) {
            this->val = v;
        }
    };
    vector<vector<int>>anc;
    vector < vector < Node >> cost;
    vector<int>depth;
    int size, LOG;

    void dfs(int i, int p, const vector<vector<T>>& adj) {
        for (auto x : adj[i]) {
            int j = x.first;
            ll w = x.second;
            if (j == p)
                continue;
            depth[j] = depth[i] + 1;
            anc[j][0] = i;
            cost[j][0] = w;
            for (int bit = 1; bit < LOG; bit++) {
                int up = anc[j][bit - 1];
                anc[j][bit] = anc[up][bit - 1];
                cost[j][bit] = merge(cost[j][bit - 1], cost[up][bit - 1]);
            }
            dfs(j, i, adj);
        }
    }
    Node merge(const Node& a, const Node& b) {

        return Node(a.val + b.val);
    }

    Node get_cost_dist(int u, int dist) {
        Node temp;
        if (depth[u] < dist)
            return temp;
        for (int bit = 0; bit < LOG; bit++) {
            if (dist & (1 << bit)) {
                temp = merge(temp, cost[u][bit]);
                u = anc[u][bit];
            }
        }
        return temp;
    }
public:
    LCA(int n) {
        size = n + 1;
        LOG = 0;
        while ((1 << LOG) <= size)LOG++;
        depth = vector<int>(size);
        anc.assign(size, vector<int>(LOG));
        cost.assign(size, vector<Node>(LOG));
    }
    void init(const vector<vector<T>>& adj) {
        dfs(1, 0, adj);
    }
    int get_dist(int u, int v) {
        return abs(depth[u] - depth[v]);
    }
    int get_kth(int u, int k) {
        if (depth[u] < k) return -1;
        for (int bit = 0; bit < LOG; bit++)
            if (k & (1 << bit))
                u = anc[u][bit];
        return u;
    }
    int get_lca(int u, int v) {
        if (depth[u] < depth[v]) swap(u, v);

        u = get_kth(u, depth[u] - depth[v]);
        if (u == v) return u;

        for (int bit = LOG - 1; bit >= 0; bit--)
            if (anc[u][bit] != anc[v][bit])
                u = anc[u][bit], v = anc[v][bit];

        return anc[u][0];
    }
    ll get_cost(int u, int v) {
        int lc = get_lca(u, v);
        Node ret1 = get_cost_dist(u, get_dist(u, lc));
        Node ret2 = get_cost_dist(v, get_dist(v, lc));
        ret1 = merge(ret1, ret2);
        return ret1.val;
    }
};
vector<vector<pair<int, int>>>v;
void dfs(int i, int p, vector<int>& ar) {
    for (auto j : v[i]) {
        if (j.first != p) {
            dfs(j.first, i, ar);
            ar[i] += ar[j.first];
        }
    }
}
void solve() {
    int n, m;
    cin >> n >> m;
    v = vector<vector<pair<int, int>>>(n + 1, vector<pair<int, int>>());
    for (int i = 1; i < n; i++) {
        int x, y, w;
        cin >> x >> y;
        v[x].push_back({ y, 0 });
        v[y].push_back({ x, 0 });
    }
    LCA<pair<int, int>>lca(n);
    lca.init(v);
    vector<int>res(n + 1), ar(n + 1);
    while (m--) {
        int x, y;
        cin >> x >> y;
        int lc = lca.get_lca(x, y);
        if (lc == y)
            swap(x, y);
        res[lc]++;
        if (lc != x and lc != y)
            ar[lc] -= 2, ar[x]++, ar[y]++;
        else {
            ar[lc]--;
            ar[y]++;
        }
    }
    dfs(1, 0, ar);
    for (int i = 1; i <= n; i++)
        cout << res[i] + ar[i] << " ";
    cout << '\n';
}
int main() {
    Fast;
    int T = 1;
    //cin >> T;
    for (int i = 1; i <= T; i++) {
        //cout << "Case " << i << ":" << '\n';
        solve();
    }
}
