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
const int N = 1e7 + 3, mod = 1e9 + 9;
ll fp(ll x, ll p) {
	ll res = 1;
	while (p) {
		if (p & 1)
			(res *= x) %= mod;
		(x *= x) %= mod;
		p /= 2;
	}
	return res;
}
void solve() {
	ll n, m, k;
	cin >> n >> m >> k;
	int x = max(0ll, n / k - (n - m));//number of valid groups,cancelling number of faults
	ll res = 0;
	res = k * (fp(2, x + 1) - 2) % mod;
	res += (m - k * x);//add faults groups cancelled with no doubling
	cout << (res + mod) % mod << '\n';
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