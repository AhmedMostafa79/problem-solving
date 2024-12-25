/*
Main Idea..
    Data Structures
    Euler Tour + Mo on Trees

*/
#include<bits/stdc++.h>
using namespace std;
#define  ll long long 
#define  all(v) ((v).begin()),((v).end())
#define  rall(v) ((v).rbegin()),((v).rend())
#define Fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
const int N = 2e5 + 5, mod = 1e9 + 7;
vector<vector<int>>adj;
vector<int>st(N), en(N), path;
int timer = -1, sq;
void dfs(int i, int p) {//Euler Tour
    st[i] = ++timer;
    path.push_back(i);
    for (auto j : adj[i]) {
        if (p != j)
            dfs(j, i);
    }
    path.push_back(i);
    en[i] = ++timer;
}

struct Mo {//MO's Algorithm
    int l, r, idx;
    bool operator<(const Mo& other) {
        if (l / sq != other.l / sq)
            return l / sq < other.l / sq;
        return (l / sq & 1 ? r<other.r : r>other.r);
    }
};
void compress(vector<ll>& v) {
    vector<ll> t = v;
    sort(t.begin(), t.end());

    t.erase(unique(t.begin(), t.end()), t.end());

    for (auto& j : v) {
        auto it = lower_bound(all(t), j) - t.begin();
        j = it;
    }

}
void solve() {
    int n;
    cin >> n;
    sq = sqrt(n) + 2;
    adj = vector<vector<int>>(n + 1, vector<int>());
    vector<ll>col(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> col[i];
    compress(col);
    for (int i = 1; i < n; i++) {
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    dfs(1, 0);

    vector<Mo>v;
    for (int i = 1; i <= n; i++)
        v.push_back({ st[i],en[i],i - 1 });
    sort(all(v));
    vector<int>ans(n), freq(n + 1);
    int res = 0;
    auto add = [&](int i) {
        int c = col[path[i]];
        res += freq[c] == 0;
        freq[c]++;
        };
    auto del = [&](int i) {
        int c = col[path[i]];
        res -= freq[c] == 1;
        freq[c]--;
        };
    int l = 0, r = -1;
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
        ans[idx] = res;
    }
    for (auto i : ans)
        cout << i << ' ';
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