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
const int N = 1e5 + 3, mod = 1e9 + 9;
int dp[1002][2][2]{}, n, m, x, y, h[1002];
int f(int i, bool a, bool b) {

	if (i > m)
		return 0;
	int& ret = dp[i][a][b];
	if (~ret)
		return ret;
	ret = 1e8;
	for (int r = i + x - 1; r < min(m + 1, i + y); r++) {
		int dots = n * (r - i + 1) - (h[r] - h[i - 1]);
		if (!a)
			ret = min(ret, dots + f(r + 1, 1, 0));
		int hs = h[r] - h[i - 1];
		if (!b)
			ret = min(ret, hs + f(r + 1, 0, 1));
	}
	return ret;

}
void solve() {
	cin >> n >> m >> x >> y;
	memset(dp, -1, sizeof dp);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			char c;
			cin >> c;
			h[j] += c == '#';
		}
	}
	for (int i = 1; i <= m + 2; i++)
		h[i] += h[i - 1];
	cout << f(1, 0, 0) << '\n';
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