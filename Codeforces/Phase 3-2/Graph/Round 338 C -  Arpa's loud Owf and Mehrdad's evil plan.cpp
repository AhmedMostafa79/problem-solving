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
bool vis[N]{}, anc[N]{};
vector<vector<int>>v;
void dfs(int i, int& lc, int& st) {
	anc[i] = vis[i] = 1;
	for (auto j : v[i]) {
		if (!vis[i] and !anc[i])
			dfs(i, lc, st);
		else if (anc[i]) {
			if (!vis[st]);
		}
	}
	anc[i] = 0;
}
int main()
{
	Fast;
	int T = 1;
	//cin >> T;
	while (T--) {
		cin >> n;
		vector<int>v(N);
		//v=vector<vector<int>>(N, vector<int>(n+1));
		for (int i = 1; i <= n; i++) {
			cin >> v[i];
		}
		int lc = 1;
		for (int i = 1; i <= n; i++) {
			fill(vis, vis + N, 0);
			int l = 0;
			for (int st = v[i]; !vis[st]; st = v[st]) {
				l++, vis[st] = 1;
			}
			if (!vis[i])close(-1);
			lc = lcm(lc, l & 1 ? l : l / 2);
		}
		cout << lc << '\n';
	}
}