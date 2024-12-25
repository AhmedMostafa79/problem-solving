#include <bits/stdc++.h>
using namespace std;
#define  ll long long 
#define  all(v) ((v).begin()),((v).end())
#define  rall(v) ((v).rbegin()),((v).rend())
#define Fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define close(n) return cout<<n,0;
#define files  freopen("closing.in", "r", stdin); freopen("closing.out", "w", stdout);
const int dx[] = { -1,0,1,0,1,-1,1,-1 };
const int dy[] = { 0,-1,0,1,1,-1,-1,1 };
const int di[] = { 'U','R','D','L' };
int countbit(ll n) { return (n > 1 ? (n & 1) + countbit(n >> 1) : n); }
ll gcd(ll x, ll y) { if (!y)return x; return gcd(y, x % y); }
ll lcm(ll x, ll y) { return x * y / gcd(x, y); }
const int N = 1e6 + 5, mod = 1e9 + 7, base = 31;

void solve() {
	int n;
	cin >> n;
	if (n % 2 == 0)
		return void(cout << n / 2 << ' ' << n / 2 << '\n');
	int gd = 1;
	for (int i = 2; i * i <= n; i++) {
		if (n % i == 0) {
			gd = max(gd, n / i);
			break;
		}
	}
	cout << gd << " " << n - gd << '\n';
}
int main() {
	Fast;
	int t = 1;
	cin >> t;
	while (t--) {
		solve();
	}
}