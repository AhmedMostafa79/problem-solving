/*
*
SPOJ - Count on a tree II (COT2)

        Category: Data Structures

        Keys: Tree Flattening, Mo's Algorithm
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
const ll N = 4e4 + 5, MOD = 998244353, LOG = 20;

vector<vector<ll>>adj;
int st[N], en[N], timer = 0;
int anc[N][LOG]{}, depth[N];
vector<int>v;
void dfs(int i, int p) {
    st[i] = v.size();
    v.push_back(i);
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
    en[i] = v.size();
    v.push_back(i);
}
int kth_ancestor(int u, int k) {
    if (depth[u] < k) return -1;
    for (int bit = 0; bit < LOG; bit++)
        if (k & (1 << bit))
            u = anc[u][bit];
    return u;
}

int get_lca(int u, int v) {
    if (depth[u] < depth[v]) swap(u, v);

    u = kth_ancestor(u, depth[u] - depth[v]);
    if (u == v) return u;

    for (int bit = LOG - 1; bit >= 0; bit--)
        if (anc[u][bit] != anc[v][bit])
            u = anc[u][bit], v = anc[v][bit];

    return anc[u][0];
}

void compress(vector<ll>& v) {
    vector<ll> t = v;
    sort(t.begin(), t.end());

    t.erase(unique(t.begin(), t.end()), t.end());

    for (auto& j : v) {
        auto it = lower_bound(all(t), j) - t.begin();
        j = it;
    }
}
int sq;
struct Mo {
    int l, r, i, lc;
    bool operator<(const Mo& x) {
        if (l / sq != x.l / sq)
            return l / sq < x.l / sq;
        return (l / sq & 1 ? r<x.r : r>x.r);
    }
};
void solve() {
    int n, m;
    cin >> n >> m;
    sq = sqrt(n) + 1;
    adj = vector<vector<ll>>(n + 1, vector<ll>());
    vector<ll>val(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> val[i];
    compress(val);
    for (int i = 2; i <= n; i++) {
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    dfs(1, 0);

    vector<Mo>q(m);
    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        if (depth[x] > depth[y])
            swap(x, y);
        int lc = get_lca(x, y);
        if (lc == x)
            q[i] = { st[x],st[y],i,0 };
        else {
            if (en[x] > st[y])//to ensure l < r 
                swap(x, y);
            q[i] = { en[x],st[y],i,lc };
        }
    }
    vector<int>freq(n + 5), in(n + 5);
    int res = 0;

    sort(all(q));
    auto add = [&](int i) {
        i = v[i];
        if (in[i] and --freq[val[i]] == 0)
            res--;
        if (!in[i] and ++freq[val[i]] == 1)
            res++;
        in[i] ^= 1;//if (ith node)&1 so it is in path
        };

    vector<int>ans(m);

    int l = 0, r = -1;
    for (auto j : q) {
        int lq = j.l, rq = j.r, i = j.i;

        while (lq < l)
            add(--l);
        while (r < rq)
            add(++r);
        while (l < lq)
            add(l++);
        while (rq < r)
            add(r--);
        if (j.lc)//if lca(x,y) !=x and !=y ,so we only need to add lca freq and then remove it 
            add(st[j.lc]);
        ans[i] = res;
        if (j.lc)
            add(st[j.lc]);
    }
    for (auto i : ans)
        cout << i << " ";
    cout << '\n';
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