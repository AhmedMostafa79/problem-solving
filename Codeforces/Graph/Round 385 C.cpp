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
int p[N], isk[N], sz[N];
int find(int i) {
	return i == p[i] ? i : p[i] = find(p[i]);
}
void join(int x, int y) {
	x = find(x);
	y = find(y);
	if (x == y)
		return;
	if (isk[y])
		swap(x, y);
	p[y] = x;
	sz[x] += sz[y];
}
void solve() {
	int n, m, k;
	cin >> n >> m >> k;
	for (int i = 1; i <= n; i++)
		p[i] = i, sz[i] = 1;
	for (int x, i = 1; i <= k; i++) {
		cin >> x;
		isk[x] = 1;
	}
	vector<pair<ll, int>>v;
	for (int i = 0; i < m; i++) {
		int x, y;
		cin >> x >> y;
		join(x, y);
	}
	bool got[N]{};
	for (int i = 1; i <= n; i++) {
		int j = find(i);
		if (!got[j])
			v.push_back({ sz[j],j });
		got[j] = 1;
	}
	sort(all(v), greater<>());
	ll res = 0;
	for (int i = 0; i < v.size(); i++) {
		int x = find(v[i].second);
		for (int j = i + 1; j < v.size(); j++) {
			int y = find(v[j].second);
			if (isk[y] and isk[x])
				continue;
			join(x, y);
		}
	}
	for (int i = 1; i <= n; i++) {
		if (isk[i])
			res += sz[i] * 1ll * (sz[i] - 1) / 2;
	}
	cout << max(0ll, res - m) << '\n';

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