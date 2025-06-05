#include<bits/stdc++.h>
#include<unordered_map>
using namespace std;
#define  ll long long
#define  all(v) ((v).begin()),((v).end())
#define  rall(v) ((v).rbegin()),((v).rend())
#define Fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define files  freopen("closing.in", "r", stdin); freopen("closing.out", "w", stdout);
const int N = 1e5 + 5, mod = 1e9 + 7;
const int SQ = 710;
vector<int>v, blocks[SQ];
void update(int j, int x) {
    int blk = j / SQ;
    //blocks[blk].clear();
    int idx = lower_bound(all(blocks[blk]), v[j]) - blocks[blk].begin();
    //for (int i = blk * SQ; i < min((int)v.size(),(blk + 1) * SQ); i++)
        //blocks[blk].push_back(v[i]);
    blocks[blk][idx] = v[j] = x;
    sort(all(blocks[blk]));
    //sort(all(blocks[blk]));
}
int query(int j, int x) {
    int blk = j / SQ;
    int res = 0;
    for (int i = 0; i < blk; i++) {
        auto l = lower_bound(all(blocks[i]), x);
        res += blocks[i].end() - l;
    }
    for (int i = blk * SQ; i <= j; i++)
        res += (v[i] >= x);
    return res;
}
void solve() {
    int n;
    cin >> n;
    v = vector<int>(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
        blocks[i / SQ].push_back(v[i]);
    }
    for (int i = 0; i <= n / SQ; i++)
        sort(all(blocks[i]));
    int q;
    cin >> q;
    while (q--) {
        int t;
        cin >> t;
        if (t == 0) {
            int l, r, x;
            cin >> l >> r >> x;
            cout << query(r - 1, x) - query(l - 2, x) << "\n";
        }
        else {
            int pos, x;
            cin >> pos >> x;
            update(pos - 1, x);
        }

    }
}
int main() {
    Fast;
    int t = 1;
    // cin >> t;
    for (int i = 1; i <= t; i++) {
        solve();
    }
}