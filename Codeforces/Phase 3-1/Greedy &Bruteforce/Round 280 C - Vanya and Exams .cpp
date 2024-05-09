#include <bits/stdc++.h>
using namespace std;
#define  ll long long 
#define  all(v) ((v).begin()),((v).end())
#define  rall(v) ((v).rbegin()),((v).rend())
#define Fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define close(n) return cout<<n,0;
const int dy[] = { -1,0,1,0,1,-1,1,-1 };
const int dx[] = { 0,1,0,-1,1,-1,-1,1 };
const int di[] = { 'U','R','D','L' };
int countbit(ll n) { return (n > 1 ? (n & 1) + countbit(n >> 1) : n); }
ll gcd(ll x, ll y) { if (!y)return x; return gcd(y, x % y); }
ll lcm(ll x, ll y) { return x * y / gcd(x, y); }
const int N = 5e4 + 3, mod = 1e9 + 7;

void solve() {
    int n, r, av;
    cin >> n >> r >> av;
    vector<pair<int,int>>v;
    ll sum = 0;
    for (int i = 1; i <= n; i++) {
        int x, y;
        cin >> x >> y;
        if (x < r)
            v.push_back({ y,x });
        sum += x;
    }
    if (sum / n >= av)
        cout << 0;
    else {
        sort(all(v));
        ll need = n*1ll*av-sum;
        ll res = 0;
        for (int i = 0; i < v.size() and need; i++) {
            res += min(r-v[i].second*1ll, need) * 1ll * v[i].first;
            need -= min(r-v[i].second * 1ll, need);
        }
        cout << res << '\n';
    }
}
int main()
{
    Fast;
    int T = 1;
    //cin >> T;
    for (int i = 1;T--; i++) {
        solve();
    }
    return 0;
}