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
const int N = 1e5 + 3, mod = 1e9 + 7;
vector<vector<int>>v;
vector<int>c(N);
int cur_color;
bool ok;
void dfs(int i, int p) {
	ok &= c[i] == cur_color;
	for (auto j : v[i]) {
		if (p != j)
			dfs(j, i);
	}
}
bool tr(int x) {
	bool valid = true;
	for (auto i : v[x]) {
		cur_color = c[i];
		ok = 1;
		dfs(i, x);
		valid &= ok;
	}
	return valid;
}
void solve() {
	int n;
	cin >> n;
	v = vector<vector<int>>(n + 1);
	for (int i = 1; i < n; i++) {
		int x, y;
		cin >> x >> y;
		v[x].push_back(y);
		v[y].push_back(x);
	}
	for (int i = 1; i <= n; i++)
		cin >> c[i];
	int r1 = -1, r2 = -1;
	for (int i = 1; i <= n; i++) {
		for (auto j : v[i]) {
			if (c[i] != c[j])
				r1 = i, r2 = j;
		}
	}
	if (r1 == -1)
		cout << "YES\n" << 1;
	else  if (tr(r1)) {
		cout << "YES\n" << r1;
	}
	else if (tr(r2))
		cout << "YES\n" << r2;
	else cout << "NO\n";
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