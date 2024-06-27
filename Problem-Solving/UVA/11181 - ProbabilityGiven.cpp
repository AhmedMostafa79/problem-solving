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

int n, r;
double p[21]{};
double f(int j) {//calculates p(a|b)
    double ret = 1.0;
    for (int i = 0; i < n; i++) {
        if ((1 << i) & j) {//if ith bit ==1
            ret *= p[i];
        }
        else ret *= (1.0 - p[i]);//if ith bit==0
    }
    return ret;
}
void solve() {
    for (int i = 0; i < n; i++)
        cin >> p[i];
    for (int i = 0; i < n; i++) {
        double a = 0, b = 0;//a=prob(ith),b=total prob of r buyers
        for (int j = 0; j < (1ll << n); j++) {
            if (countbit(j) == r) {
                double t = f(j);
                b += t;
                if ((1 << i) & j) {//if bit (a<<i) is 1 in number j
                    a += t;
                }
            }
        }
        cout << fixed << setprecision(6) << a / b << '\n';//p(a|b)=p(a and b)/p(b) 
    }
}
int main()
{
    Fast;
    int T = 1;
    //cin >> T;
    for (int i = 1; cin >> n >> r and (n + r); i++) {
        cout << "Case " << i << ":\n";
        solve();
    }
    return 0;
}