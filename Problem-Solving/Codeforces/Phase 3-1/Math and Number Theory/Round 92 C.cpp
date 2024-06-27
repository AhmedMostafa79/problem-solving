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
const int N = 2e7 + 3, mod = 1e9 + 7;
void rotat(int& r, int& c, int& n, int& m) {
	int t = c;
	c = n - r + 1;
	r = t;
	swap(n, m);
}
void solve() {
	int n, m, x, y, z, p, r, c;
	cin >> n >> m >> x >> y >> z >> p;
	x %= 4, y %= 2, z %= 4;
	while (p--) {
		cin >> r >> c;
		int _m = m, _n = n;
		for (int j = 1; j <= x; j++)
			rotat(r, c, _n, _m);
		c = y ? _m - c + 1 : c;
		for (int j = 1; j <= 4 - z; j++)
			rotat(r, c, _n, _m);
		cout << r << ' ' << c << '\n';
	}
}
int main()
{
	Fast;
	int T = 1;
	//cin >> T;
	for (int i = 1; i <= T; i++) {
		solve();
		cout << '\n';
	}
	return 0;
}