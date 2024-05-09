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
const int N = 1e5 + 5;
int col[N]{};
bool valid = 1;
vector<int>a, b;
void dfs(int i, int c) {
	col[i] = c;
	if (c == 1)
		a.push_back(i);
	else b.push_back(i);
	for (auto j : v[i]) {
		if (!col[j]) {
			dfs(j, 3 - c);
		}
		else if (col[j] and col[j] == c)
			valid = 0;
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
		for (int i = 1; i <= n; i++)
			if (!col[i])
				dfs(i, 1);
		if (!valid)cout << -1;
		else {
			cout << a.size() << '\n';
			for (auto i : a)cout << i << " ";
			cout << '\n';
			cout << b.size() << '\n';
			for (auto i : b)cout << i << " ";

		}
	}
}