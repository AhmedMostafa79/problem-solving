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
const int N = 2e5 + 5, mod = 1e9 + 9;
int n, a, b;
int d[N]{};
vector<int>v[N];
int p[N]{};
void dfs(int i, int fa) {
	d[i] = d[fa] + 1;
	p[i] = fa;
	for (auto j : v[i]) {
		if (j != fa)
			dfs(j, i);
	}
}
void solve() {
	cin >> n;
	cin >> a >> b;
	for (int i = 1; i <= n; i++)
		v[i].clear();
	for (int i = 1; i < n; i++) {
		int x, y;
		cin >> x >> y;
		v[x].push_back(y);
		v[y].push_back(x);
	}
	d[0] = -1;
	dfs(a, 0);
	int c = b, res = 0;
	for (int i = 0; i < (d[b] + 1) / 2; i++) {//getting to middle node
		res++;
		c = p[c];
	}
	dfs(c, 0);
	int m = 0;
	for (int i = 1; i <= n; i++)
		m = max(m, d[i]);
	cout << res + (n * 2) - m - 2 << '\n';
}
int main()
{
	Fast;
	int T = 1;
	cin >> T;
	while (T--) {
		solve();
	}
}