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
const int N = 1e3 + 3, mod = 1e9 + 7;
vector<int>v[N], d(N, 1e7), vis(N), p(N);
void dfs(int i, int& leaf, int& mi) {
	vis[i] = 1;
	mi = min(mi, d[i]);
	for (auto j : v[i]) {
		if (vis[j])
			continue;
		if (!v[j].size())
			leaf = j;
		dfs(j, leaf, mi);
	}
}
void solve() {
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int x, y, dd;
		cin >> x >> y >> dd;
		v[x].push_back(y);
		p[y] = x;
		d[x] = min(dd, d[x]);
		d[y] = min(dd, d[y]);
	}
	vector < pair<pair<int, int>, int>>res;
	for (int i = 1; i <= n; i++) {
		int leaf = i, mi = 1e9;
		if (v[i].size() == 1 and !p[i]) {
			dfs(i, leaf, mi);
			res.push_back({ {i,leaf },mi });
		}
	}
	cout << res.size() << '\n';
	for (auto i : res)
		cout << i.first.first << ' ' << i.first.second << " " << i.second << '\n';
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
}