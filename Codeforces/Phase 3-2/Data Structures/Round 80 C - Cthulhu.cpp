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
vector<vector<int>>v;
int vis[102]{}, lvl[102], c = 1;
void bfs() {
	queue<pair<int, int>>q;
	q.push({ 1,0 });
	while (q.size()) {
		int x = q.front().first, y = q.front().second;
		q.pop();
		vis[x] = 1;
		for (auto j : v[x]) {
			if (!vis[j]) {
				q.push({ j,x });
				vis[j] = 1;
				c++;
			}
		}
	}
}
int main()
{
	Fast;
	int T = 1;
	//cin >> T;
	while (T--) {
		int n, m;
		cin >> n >> m;
		v = vector<vector<int>>(n + 1, vector<int>());
		for (int i = 0; i < m; i++) {
			int x, y;
			cin >> x >> y;
			v[x].push_back(y);
			v[y].push_back(x);
		}
		bfs();
		cout << (n == m and c == n ? "FHTAGN!\n" : "NO\n");
	}
}