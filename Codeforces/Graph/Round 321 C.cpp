#include <bits/stdc++.h>
using namespace std;
#define  ll long long 
#define  range(v) ((v).begin()),((v).end())
#define Fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define close(n) return cout<<n,0;
int nx[] = { -1,-1,-1,0,0,1,1,1 };
int ny[] = { -1,0,1,-1,1,-1,0,1 };
int countbit(ll n) { return (n > 1 ? (n & 1) + countbit(n >> 1) : n); }
ll gcd(ll x, ll y) { if (!y)return x; return gcd(y, x % y); }
ll lcm(ll x, ll y) { return x * y / gcd(x, y); }
vector<vector<int>>v;
bool vis[(int)1e5 + 5]{}, cat[(int)1e5 + 5]{};
ll res = 0;
int m;
void dfs(int i, int p, int c) {
	if (c > m)return;
	int o = 1;
	for (int j = 0; j < v[i].size(); j++) {
		if (v[i][j] != p)
			o = 0, dfs(v[i][j], i, c * cat[v[i][j]] + cat[v[i][j]]);
	}
	res += o;
}
int main()
{
	Fast;
	int T = 1;
	//cin >> T;
	while (T--) {
		int size;
		cin >> size >> m;
		v = vector<vector<int>>(size, vector<int>());
		for (int x, i = 0; i < size; i++) {
			cin >> x;
			cat[i] = x;
		}
		for (int i = 0; i < size - 1; i++) {
			int x, y;
			cin >> x >> y;
			x--, y--;
			v[x].push_back(y);
			v[y].push_back(x);
		}
		dfs(0, -1, cat[0]);
		cout << res;
	}
}