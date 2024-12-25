#include <bits/stdc++.h>
using namespace std;
#define  ll long long 
#define  all(v) ((v).begin()),((v).end())
#define  rall(v) ((v).rbegin()),((v).rend())
#define Fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define close(n) return cout<<n,0;
#define files  freopen("closing.in", "r", stdin); freopen("closing.out", "w", stdout);
const int dx[] = { -1,0,1,0,1,-1,1,-1 };
const int dy[] = { 0,-1,0,1,1,-1,-1,1 };
const int di[] = { 'U','R','D','L' };
int countbit(ll n) { return (n > 1 ? (n & 1) + countbit(n >> 1) : n); }
ll gcd(ll x, ll y) { if (!y)return x; return gcd(y, x % y); }
ll lcm(ll x, ll y) { return x * y / gcd(x, y); }
const int N = 1e6 + 5;
vector<string>ar(55);
int n, m, vis[55][55];
bool check(int i, int j) {
	return i >= 0 and j >= 0 and i < n and j < m and ar[i][j] == '#';
}
int dfs(int i, int j) {
	if (vis[i][j] or !check(i, j))
		return 0;
	vis[i][j] = 1;
	for (int r = 0; r < 4; r++) {
		int x = dx[r] + i, y = dy[r] + j;
		dfs(x, y);
	}
	return 1;
}
void solve() {
	cin >> n >> m;
	for (int i = 0; i < n; i++)
		cin >> ar[i];
	int hs = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (ar[i][j] == '#') {
				hs++;
				ar[i][j] = '.';
				memset(vis, 0, sizeof vis);
				int s = 0;//checks if we start from i,j is it a loop or not 
				// if all are visited ,so it is a loop 
				for (int r = 0; r < 4; r++) {
					int x = dx[r] + i, y = dy[r] + j;
					s += dfs(x, y);
				}
				if (s > 1)
					return void(cout << 1);
				ar[i][j] = '#';
			}
		}
	}
	cout << (hs > 2 ? 2 : -1);
}
int main() {
	Fast;
	int t = 1;
	//cin >> t;
	while (t--) {
		solve();
	}
}