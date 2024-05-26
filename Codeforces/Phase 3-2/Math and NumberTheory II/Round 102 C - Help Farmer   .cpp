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
void solve() {
	ll n;
	cin >> n;
	ll mi = 1e15;
	for (ll i = 1; i * i * i <= n; i++) {
		if (n % i)
			continue;
		ll now = n / i;
		for (ll j = i; j * j <= now; j++) {
			ll x = i, y = j, z = now / j;
			if (z % j == 0) {
				mi = min(mi, (j + 1) * 1ll * (y + 2) * (z / j + 2));//dividing z to smaller z1 and z2
			}
		}
	}
	cout << mi - n << ' ' << (n + 1) * 3 * 3 - n;//deduced formula
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