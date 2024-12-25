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
//vector<vector<int>>ar(2e5+5);

void solve() {
    int n;
    cin >> n;
    vector<pair<pair<int, int>, int>>v(n);
    for (auto& i : v)
        cin >> i.first.first >> i.first.second >> i.second;
    vector<ll>dp(n + 1);
    int gurb = 2e9;
    v.push_back({ {gurb + 1,gurb + 1},gurb + 1 });
    sort(all(v));
    for (int i = n - 1; i >= 0; i--) {
        int y = v[i].first.second;
        int idx = upper_bound(all(v), make_pair(make_pair(y, gurb), gurb)) - v.begin();
        dp[i] = max(v[i].second + dp[idx], dp[i + 1]);
    }
    cout << dp[0] << '\n';
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