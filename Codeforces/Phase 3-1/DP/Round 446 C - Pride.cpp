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
const int N = 4e4 + 3, mod = 1e9 + 7;
int n;
static void solve() {
    cin >> n;
    vector<int>v(n);
    for (auto& i : v)
        cin >> i;
    int mi = 1e9, c = count(all(v), 1);
    for (int i = 0; i < n; i++) {
        int g = v[i];
        for (int j = i + 1; j < n; j++) {
            g = gcd(v[j], g);
            if (g == 1)
                mi = min(mi, j - i);
        }
    }
    if (c)
        cout << n - c;
    else if (mi != 1e9)
        cout << mi + n - 1;
    else cout << -1;
}
int main()
{
    Fast;
    int T = 1;
    //cin >> T;
    for (int i = 1; T--; i++) {
        //cout << "Case " << i << ":\n";
        solve();
    }
    return 0;
}