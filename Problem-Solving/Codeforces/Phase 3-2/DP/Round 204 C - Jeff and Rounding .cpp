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
int n;
double dp[2002][2002], a[2002]{};
bool vis[2002][2002];
double f(int cur, int i, int j) {
	double& ret = dp[i][j];
	if (vis[i][j])
		return ret;
	double v1 =1e12, v2 =1e12;
	if (cur > n * 2)
		return 0;
	vis[i][j] = 1;
	if (i < n)
		v1 = ceil(a[cur]) - a[cur] + f(cur + 1, i + 1, j);
	if (j < n)
		v2 = floor(a[cur]) - a[cur] + f(cur + 1, i, j + 1);
	if (fabs(v1) < fabs(v2))
		ret = v1;
	else ret = v2;
	return ret;
}
void solve() {
	cin >> n;
	for (int i = 1; i <= n * 2; i++) {
		cin >> a[i];
	}
	cout << fixed << setprecision(3) << fabs(f(1, 0, 0));

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