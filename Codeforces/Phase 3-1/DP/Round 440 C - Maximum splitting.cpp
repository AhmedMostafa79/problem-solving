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
    int q;
    cin >> q;
    while (q--) {
        int n;
        cin >> n;
        if (n <= 12 and ((n % 2 and n != 9) or n == 2)) {
            cout << -1 << '\n';
        }
        else {
            int res = 0;
            if (n % 2)
                n -= 9, res++;
            res += n / 4;
            cout << res << '\n';
        }
    }
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