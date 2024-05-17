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
const int N = 5e5 + 3, mod = 1e9 + 7;
vector<vector<int>>v;
vector<int>c(N), f(N);
int n;
void dfs(int u) {
	int now = 0;
	for (auto j : v[u]) {
		if (j == f[u])
			continue;
		now++;
		while (c[u] == now or c[f[u]] == now)
			now++;
		c[j] = now;
		f[j] = u;
		dfs(j);
	}
}
void solve() {
	cin >> n;
	v = vector<vector<int>>(n + 1);
	for (int i = 1; i < n; i++) {
		int x, y;
		cin >> x >> y;
		v[x].push_back(y);
		v[y].push_back(x);
	}
	c[1] = 1, f[1] = 0;
	dfs(1);
	cout << *max_element(all(c)) << '\n';
	for (int i = 1; i <= n; i++)
		cout << c[i] << " ";
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