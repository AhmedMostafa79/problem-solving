#include <bits/stdc++.h>
using namespace std;
#define  ll long long 
#define  all(v) ((v).begin()),((v).end())
#define  rall(v) ((v).rbegin()),((v).rend())
#define Fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define close(n) return cout<<n,0;
#define files  freopen("moocast.in", "r", stdin); freopen("moocast.out", "w", stdout);
const int dx[] = { -1,0,1,0,1,-1,1,-1 };
const int dy[] = { 0,1,0,-1,1,-1,-1,1 };
const int di[] = { 'U','R','D','L' };
int countbit(ll n) { return (n > 1 ? (n & 1) + countbit(n >> 1) : n); }
ll gcd(ll x, ll y) { if (!y)return x; return gcd(y, x % y); }
ll lcm(ll x, ll y) { return x * y / gcd(x, y); }
const int N = 1e2 + 3, mod = 1e9 + 7;

int n, m, vis[N * 2];
vector<int>adj[N * 2];
void dfs(int i) {
	vis[i] = 1;
	for (auto r : adj[i])
		if (!vis[r])
			dfs(r);
}
void solve() {
	cin >> n >> m;
	int c = 0;
	for (int i = 1; i <= n; i++) {
		int x, a;
		cin >> x;
		c += !x;
		while (x--) {
			cin >> a;
			adj[i].push_back(a + n);
			adj[n + a].push_back(i);
		}
	}
	if (c == n)
		return void(cout << n);
	int res = -1;
	for (int i = 1; i <= n; i++)
	{
		if (!vis[i])
			dfs(i), res++;
	}
	cout << res << '\n';
}
int main() {
	Fast;
	int T = 1;
	//cin >> T;
	while (T--) {
		solve();
		if (T)
			cout << '\n';
	}
}