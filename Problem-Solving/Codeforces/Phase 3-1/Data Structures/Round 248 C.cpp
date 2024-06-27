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
const int N = 2e7 + 3, mod = 1e9 + 7;
void solve() {
	int n, m, q;
	cin >> n >> m >> q;
	int ar[102][102]{};
	int r[10002]{}, c[10002]{}, z[10002]{};
	for (int i = 1; i <= q; i++) {
		int t;
		cin >> t;
		if (t <= 2) {
			if (t == 1)
				cin >> r[i];
			else cin >> c[i];
		}
		else {
			cin >> r[i] >> c[i] >> z[i];
		}
	}

	for (int i = q; i >= 1; i--) {
		if (r[i] and c[i])
			ar[r[i]][c[i]] = z[i];
		else if (r[i])
		{
			int t = ar[r[i]][m];
			for (int j = m; j >= 1; j--)
				ar[r[i]][j] = ar[r[i]][j - 1];
			ar[r[i]][1] = t;
		}

		else
		{
			int t = ar[n][c[i]];
			for (int j = n; j >= 1; j--)
				ar[j][c[i]] = ar[j - 1][c[i]];
			ar[1][c[i]] = t;
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++)
			cout << ar[i][j] << " ";
		cout << '\n';
	}
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
	return 0;
}