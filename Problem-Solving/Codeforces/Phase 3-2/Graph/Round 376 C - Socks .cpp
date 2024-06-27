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
const int N = 2e5 + 3, mod = 1e9 + 7;
//vector<vector<int>>v;
vector<int>c(N), p(N), mx(N);
map<int, int>mp[N];
int find(int i) {
	return i == p[i] ? i : p[i] = find(p[i]);
}
void solve() {
	int n, m, k;
	cin >> n >> m >> k;
	//v = vector<vector<int>>(n + 1);
	for (int i = 1; i <= n; i++)
		cin >> c[i], p[i] = i;
	for (int i = 1; i <= m; i++) {
		int x, y;
		cin >> x >> y;
		p[find(x)] = p[find(y)];
	}
	int res = n;
	for (int i = 1; i <= n; i++) {
		mx[find(i)] = max(mx[find(i)], ++mp[find(i)][c[i]]);//max child color under parent(i)
	}
	for (int i = 1; i <= n; i++) {
		res -= mx[i];
	}
	cout << res << '\n';
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