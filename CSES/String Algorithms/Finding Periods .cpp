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
const int N = 1e6 + 5, base = 31, mod = 1e9 + 7;
void solve() {
	string s;
	cin >> s;
	ll n = s.size();
	s = ' ' + s;
	vector<ll>h(n + 1), pw(n + 1);
	for (int i = 1; i <= n; i++)
		h[i] = (1ll * h[i - 1] * base % mod + (s[i] - 'a' + 1)) % mod;
	pw[0] = 1;
	for (int i = 1; i <= n; i++)
		pw[i] = 1ll * pw[i - 1] * base % mod;
	for (int i = 1; i <= n; i++) {
		int c = 1;
		for (int j = i * 2; j <= n; j += i) {
			ll h2 = h[j] - (1ll * h[j - i] * pw[i]) % mod;
			if (h2 < 0)
				h2 += mod;
			if (h2 != h[i])
				break;
			c++;
		}
		if (n % i) {
			ll h2 = h[n] - (h[n - (n % i)] * 1ll * pw[n % i]) % mod;
			if (h2 < 0)
				h2 += mod;
			c += h2 == h[n % i];
		}
		if (c == (n + i - 1) / i)
			cout << i << ' ';

	}
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