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
const int N = 2e3 + 3, mod = 1e9 + 7;
vector<int>v[N];
int  bfs(int i) {
	int lvl = 1;
	queue<pair<int, int>>q;
	q.push({ i,1 });
	while (q.size()) {
		int j = q.front().first, l = q.front().second;
		q.pop();
		for (auto x : v[j]) {
			q.push({ x,l + 1 });
		}
		lvl = max(lvl, l);
	}
	return lvl;
}
void solve() {
	int n;
	cin >> n;
	bool par[2002]{};
	for (int x, i = 1; i <= n; i++) {
		cin >> x;
		if (x > 0)
			v[x].push_back(i), par[i] = 1;
	}
	int res = 0;
	for (int i = 1; i <= n; i++) {
		if (!par[i])
			res = max(res, bfs(i));
	}
	cout << res << "\n";
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