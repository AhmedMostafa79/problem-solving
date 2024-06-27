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
int n, m, c0, d0, a[12], b[12], c[12], d[12], aa[12];
int dp[12][102][1002]{};
int f(int i, int ai, int n) {
	if (ai < 0 or n < 0)
		return -1e9;
	if (i > m)
		return 0;
	int& ret = dp[i][ai][n];
	if (~ret)
		return ret;
	ret = f(i + 1, a[i + 1], n);//leave
	ret = max(ret, f(i, ai - b[i], n - c[i]) + d[i]);//take 1,2,...max of ith item
	return max(0, ret);
}
void solve() {
	cin >> n >> m >> c[0] >> d[0];
	memset(dp, -1, sizeof dp);
	for (int i = 1; i <= m; i++) {
		cin >> a[i] >> b[i] >> c[i] >> d[i];
		aa[i] = a[i];
	}
	cout << f(0, 0, n);
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