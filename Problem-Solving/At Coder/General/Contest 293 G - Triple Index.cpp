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
const ll N = 5e4 + 5, MOD = 998244353;
int sq = 450;
struct Mo {
    int l, r, idx;
    bool operator<(const Mo& x) {
        if (l / sq != x.l / sq)
            return l / sq < x.l / sq;
        return (l / sq & 1 ?
            r<x.r : r >x.r);
    }
};

ll C(ll n) {// nC3
    if (n < 3)
        return 0;
    return n * (n - 1) * (n - 2) / (3 * 2 * 1);
}
void solve() {
    int n, m;
    cin >> n >> m;
    //sq = sqrt(n) + 1;
    vector<int>a(n);
    for (auto& i : a)
        cin >> i;
    vector<Mo>v(m);
    for (int i = 0; i < m; i++) {
        cin >> v[i].l >> v[i].r;
        v[i].idx = i;
        v[i].l--, v[i].r--;
    }
    sort(all(v));
    vector<int>freq(*max_element(all(a)) + 1);
    ll res = 0;
    auto add = [&](int i) {
        int val = a[i];
        res -= C(freq[val]);
        freq[val]++;
        res += C(freq[val]);
        };
    auto del = [&](int i) {
        int val = a[i];
        res -= C(freq[val]);
        freq[val]--;
        res += C(freq[val]);
        };
    auto query = [&]() {
        return res;
        };
    /*  for (auto i : v)
          cout << i.l << ' ' << i.r << '\n';*/
    int l = 0, r = -1;
    vector<ll>ans(m);
    for (auto i : v) {
        int lq = i.l, rq = i.r, idx = i.idx;
        while (lq < l)
            add(--l);
        while (r < rq)
            add(++r);
        while (l < lq)
            del(l++);
        while (rq < r)
            del(r--);
        ans[idx] = query();
    }
    cout << '\n';
    for (auto i : ans)
        cout << i << '\n';
    cout << '\n';
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