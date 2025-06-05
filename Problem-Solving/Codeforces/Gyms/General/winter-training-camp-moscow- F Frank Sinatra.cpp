#include<bits/stdc++.h>
using namespace std;
#define  ll long long
#define  all(v) ((v).begin()),((v).end())
#define  rall(v) ((v).rbegin()),((v).rend())
#define Fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define files  freopen("closing.in", "r", stdin); freopen("closing.out", "w", stdout);

int countbit(ll n) { return (n > 1 ? (n & 1) + countbit(n >> 1) : n); }
ll gcd(ll x, ll y) { if (!y)return x; return gcd(y, x % y); }
ll lcm(ll x, ll y) { return x * y / gcd(x, y); }
const int dx[] = { 0, 1,-1,0,0,1,1,-1,-1 };
const int dy[] = { 0, 0,0,1,-1,1,-1,1,-1 };
const int N = 2e5 + 5, LOG = 30, mod = 1e9 + 7, base = 31;

vector<pair<int, int>>v[N];
vector<int>tour;
int val[N], cnt = -1, st[N], en[N], sq;
int anc[N][LOG], depth[N];

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
struct Mo {
    int l, r, i, lc;
    bool operator<(const Mo& other) {
        if (l / sq != other.l / sq)
            return l / sq < other.l / sq;
        return (l / sq & 1 ? r<other.r : r>other.r);
    }
};
void dfs(int i, int p) {
    st[i] = ++cnt;
    depth[i] = depth[p] + 1;
    anc[i][0] = p;
    tour.push_back(i);
    for (int bit = 1; bit < LOG; bit++) {
        anc[i][bit] = anc[anc[i][bit - 1]][bit - 1];
    }
    for (auto j : v[i]) {
        if (j.first != p) {
            val[j.first] = j.second;
            dfs(j.first, i);
        }
    }
    tour.push_back(i);
    en[i] = ++cnt;
}

void solve() {
    int n, m;
    cin >> n >> m;
    sq = sqrt(n) + 5;
    vector<pair<pair<int, int>, int>>edg(n + 1);
    for (int i = 1; i < n; i++) {
        int x, y, w;
        cin >> x >> y >> w;
        w = min(w, (int)(1e5 + 1));
        v[x].push_back({ y ,w });
        v[y].push_back({ x,w });
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
            q[i] = { st[x] + 1,st[y],i,0 };
        else {
            if (en[x] > st[y])
                swap(x, y);
            q[i] = { en[x],st[y],i,lc };
        }
    }
    sort(all(q));
    bitset<N>s;
    s.set();
    //indicates that all numbers are missing
    //as 0=unmissing ,1=missing
    vector<int>freq(n + 2), res(m + 2), in(N);
    auto add = [&](int i) {
        i = tour[i];
        int vl = val[i];
        if (in[i]) {
            if (freq[vl] == 1)
                s[vl] = 1;
            freq[vl]--;
        }
        else {
            if (freq[vl] == 0)
                s[vl] = 0;
            freq[vl]++;
        }
        in[i] ^= 1;
        };
    int l = 0, r = -1;
    for (auto i : q) {
        int lq = i.l, rq = i.r;
        int idx = i.i, lc = i.lc;
        //cout << tour[lq] << ' ' << tour[rq] << ' ';
        while (lq < l)
            add(--l);
        while (r < rq)
            add(++r);
        while (l < lq)
            add(l++);
        while (rq < r)
            add(r--);
        //cout << *s.begin() << '\n';
        res[idx] = s._Find_first();

    }
    for (int i = 0; i < m; i++)
        cout << res[i] << "\n";
}
int main() {
    Fast;
    int t = 1;
    //cin >> t;
    for (int i = 1; i <= t; i++) {
        solve();
        if (i < t)
            cout << '\n';
    }
    return 0;
}