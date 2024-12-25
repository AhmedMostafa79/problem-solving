#include <bits/stdc++.h>
using namespace std;
#define  ll long long 
#define  all(v) ((v).begin()),((v).end())
#define  rall(v) ((v).rbegin()),((v).rend())
#define Fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define close(n) return cout<<n,0;
#define files  freopen("closing.in", "r", stdin); freopen("closing.out", "w", stdout);
const int dx[] = { -1,0,1,0,1,-1,1,-1 };
const int dy[] = { 0,1,0,-1,1,-1,-1,1 };
const int di[] = { 'U','R','D','L' };
int countbit(ll n) { return (n > 1 ? (n & 1) + countbit(n >> 1) : n); }
ll gcd(ll x, ll y) { if (!y)return x; return gcd(y, x % y); }
ll lcm(ll x, ll y) { return x * y / gcd(x, y); }
const int N = 1e6 + 5;
ll x, y, p, q;
bool check(int t) {
	return p * t >= x and q * t - p * t >= y - x;
}
void solve() {
	cin >> x >> y >> p >> q;
	int l = -1, r = 1e9;
	if (!check(r))
		return void(cout << -1 << '\n');
	while (r - l > 1) {
		ll mid = l + r >> 1;
		if (check(mid))
			r = mid;
		else l = mid;
	}
	cout << r * 1ll * q - y << '\n';
}
int main() {
	Fast;
	int t = 1;
	cin >> t;
	while (t--) {
		solve();
	}
}