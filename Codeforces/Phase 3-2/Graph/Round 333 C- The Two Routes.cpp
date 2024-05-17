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
int n, m;
const int N = 4e2 + 2;
int val[N]{};
void bfs(int i, vector<vector<bool>>v) {
	priority_queue<int, vector<int>, greater<>>q;
	q.push(i);
	val[1] = 0;
	while (!q.empty()) {
		int x = q.top();
		q.pop();
		for (int j = 1; j <= n; j++) {
			if (v[x][j]) {
				if (val[x] + 1 < val[j])
					q.push({ j }), val[j] = val[x] + 1;
			}
		}
	}
}
vector<vector<bool>>tr, b;
int main()
{
	Fast;
	int T = 1;
	//cin >> T;
	while (T--) {
		cin >> n >> m;
		b = tr = vector<vector<bool>>(n + 1, vector<bool>(n + 1));
		for (int i = 0; i < m; i++) {
			int x, y;
			cin >> x >> y;
			tr[x][y] = 1;
			tr[y][x] = 1;
		}

		fill(val, val + N, 1e8);
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				if (!tr[i][j])
					b[i][j] = 1;
			}
		}
		/*for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				cout << b[i][j] << ' ';
			}
			cout << '\n';
		}*/
		bfs(1, tr);
		int ma = val[n];
		fill(val, val + N, 1e8);
		bfs(1, b);
		ma = max(ma, val[n]);
		cout << (ma == 1e8 ? -1 : ma);
	}
}