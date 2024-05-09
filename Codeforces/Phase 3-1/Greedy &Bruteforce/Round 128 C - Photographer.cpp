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
    int n, d, a, b;
    cin >> n >> d >> a >> b;
    vector<pair<int, ll>>v(n);
    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        v[i].first = x * 1ll * a + y * b;
        v[i].second = i + 1;
    }
    sort(all(v));
    ll sum = 0, i;
    for (i = 0; i < n; i++) {
        if (sum + v[i].first > d)
            break;
        sum += v[i].first;
    }
    cout << i << '\n';
    for (int j = 0; j < i; j++)
        cout << v[j].second << '\n';
}
int main()
{
    Fast;
    int T = 1;
    //cin >> T;
    for (int i = 1; T--; i++) {
        solve();
    }
    return 0;
}