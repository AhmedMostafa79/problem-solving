#include <bits/stdc++.h>
using namespace std;
#define  ll long long 
#define  all(v) ((v).begin()),((v).end())
#define  rall(v) ((v).rbegin()),((v).rend())
#define Fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define close(n) return cout<<n,0;
#define f first
#define s second
const int dx[] = { -1,0,1,0,1,-1,1,-1 };
const int dy[] = { 0,1,0,-1,1,-1,-1,1 };
const int di[] = { 'U','R','D','L' };
int countbit(ll n) { return (n > 1 ? (n & 1) + countbit(n >> 1) : n); }
ll gcd(ll x, ll y) { if (!y)return x; return gcd(y, x % y); }
ll lcm(ll x, ll y) { return x * y / gcd(x, y); }
//const int N = 1e7 + 3, mod = 1e9 + 7;
int mod;
ll fast_power(ll n, ll p) {//time O(log(p))
	if (!p)return 1;
	ll ret = fast_power(n, p / 2);
	return ((p & 1) ? ((((ret % mod) * (ret % mod)) % mod) * n) % mod : ((ret % mod) * (ret % mod)) % mod);
}
void solve() {
	int n;
	cin >> n >> mod;
	cout << (fast_power(3, n) - 1 + mod) % mod;
}
int main()
{
	Fast;
	int T = 1;
	//cin >> T;
	while (T--) {
		solve();
	}
}