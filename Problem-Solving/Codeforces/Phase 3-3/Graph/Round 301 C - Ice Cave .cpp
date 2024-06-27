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
const int N = 5e2 + 3, mod = 1e9 + 7;

int n, m, c1, c2, r1, r2;;
char ar[N][N];
bool dfs(int i, int j) {
	if (ar[i][j] != '.')
		return i == r2 and j == c2;
	ar[i][j] = 'X';
	for (int r = 0; r < 4; r++) {
		int x = dx[r] + i, y = dy[r] + j;
		if (dfs(x, y))
			return 1;
	}
	return 0;
}
void solve() {
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++)
			cin >> ar[i][j];
	}
	cin >> r1 >> c1 >> r2 >> c2;
	ar[r1][c1] = '.';
	cout << (dfs(r1, c1) ? "YES\n" : "NO\n");

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