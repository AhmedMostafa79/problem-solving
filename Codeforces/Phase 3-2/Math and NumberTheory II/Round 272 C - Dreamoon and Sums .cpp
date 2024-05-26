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
const int N = 1e5 + 3, mod = 1e9 + 7;
int res = 0;
ll f(ll a) {
	ll x = a, y = a + 1;
	if (x % 2 == 0)//divide by 2 to not get to use mod inverse
		x /= 2;
	else y /= 2;
	x %= mod;
	y %= mod;
	return (x * y) % mod;
}

void solve() {
	ll a, b;//final form b*(b-1)/2*(a*(a+1)/2 *b + a)
	cin >> a >> b;
	ll suma = f(a);
	ll sumb = f(b - 1);
	suma = (suma * b) % mod;
	suma = (suma + a) % mod;
	suma = (sumb * suma) % mod;
	cout << suma << '\n';
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