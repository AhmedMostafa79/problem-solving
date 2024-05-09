#include <bits/stdc++.h>
using namespace std;
#define  ll long long 
#define  all(v) ((v).begin()),((v).end())
#define  rall(v) ((v).rbegin()),((v).rend())
#define Fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define close(n) return cout<<n,0;
const int dx[] = { -1,0,1,0,1,-1,1,-1 };
const int dy[] = { 0,1,0,-1,1,-1,-1,1 };
const int di[] = { 'U','R','D','L' };
int countbit(ll n) { return (n > 1 ? (n & 1) + countbit(n >> 1) : n); }
ll gcd(ll x, ll y) { if (!y)return x; return gcd(y, x % y); }
ll lcm(ll x, ll y) { return x * y / gcd(x, y); }
const int N = 5e4 + 3, mod = 1e9 + 7;
double a, b, n, ttl;
void solve() {
    ttl = a + b;
    double s1 = a / ttl * (b / (ttl - n - 1));//chosen cow then car(so we subtract n and 1 (chosen cow befor))
    double s2 = b / ttl * ((b - 1) / (ttl - n - 1));//chosen car then car (so we subtracted n and 1 chosen car befor)
    cout << fixed << setprecision(5) << s1 + s2 << '\n';

}
int main()
{
    Fast;
    int T = 1;
    //cin >> T;
    for (int i = 1; cin >> a >> b >> n; i++) {
        solve();
    }
    return 0;
}