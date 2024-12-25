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
int p[N], dp[4010][4010]{}, b[4002];

void solve() {
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> b[i];
	int res = 1;
	for (int i = 1; i <= n; i++) {
		for (int j = i + 1; j <= n; j++) {
			if (!p[b[j]])
				dp[i][j] = 2;
			else dp[i][j] = dp[p[b[j]]][i] + 1;//last pos[b[j]][cur_pos[b[i]]]+1;
			res = max(res, dp[i][j]);
		}
		p[b[i]] = i;
	}
	cout << res << '\n';
}
int main() {
	Fast;
	int t = 1;
	//cin >> t;
	while (t--) {
		solve();
	}
}