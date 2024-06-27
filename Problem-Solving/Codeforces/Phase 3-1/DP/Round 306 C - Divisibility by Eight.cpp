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
void solve() {
    string s;
    cin >> s;
    int n = s.size(), v = 0, res = -1;
    for (int i = 0; i < n; i++) {
        ll x = (s[i] - '0');
        if (x % 8 == 0)
            res = x;
        for (int j = i + 1; j < n; j++) {
            ll y = (x * 10 + (s[j] - '0'));
            if (y % 8 == 0)
                res = y;
            for (int j2 = j + 1; j2 < n; j2++) {
                ll z = (y * 10 + (s[j2] - '0'));
                if (z % 8 == 0)
                    res = z;
            }
        }
    }
    if (res >= 0)
        cout << "YES\n" << res;
    else
        cout << "NO\n";
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