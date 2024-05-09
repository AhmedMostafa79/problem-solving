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
/*
    R1===> 1=p,2=q*p,3=q*q*p,i=q^i-1*p (in one round)
    R2===> 1=q^n*p,2=q^n*q*p,3=q^n*q*q*p,i=q^n*q^i-1*p
    Rm===> 1=q^(n*(m-1))*q^(i-1)*p
*/
double n, p, ith, q;
void solve() {
    cin >> n >> p >> ith;
    q = 1 - p;
    if (p == 0)
        return void(cout << "0.0000\n");
    double p2 = 1;
    for (int i = 1; i <= n; i++) {
        p2 *= q;  //get total expected fail of n players in 1 round
    }
    p2 = 1 - p2;  //total expected success of n players in 1 round
    double res = p / p2;//prob. of single throw/ total n throws
    for (int i = 1; i < ith; i++) {//p(ith)= q^i-1*p;
        res *= q;
    }
    cout << fixed << setprecision(4) << res << '\n';
}
int main()
{
    Fast;
    int T = 1;
    cin >> T;
    for (int i = 1; T--; i++) {
        solve();
    }
    return 0;
}