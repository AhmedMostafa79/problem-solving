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
vector<double>p;
double dfs(int i = 1, int p = 0) {
	double sum = 0;
	for (auto j : v[i]) {
		if (j != p)
			sum += dfs(j, i) + 1;
	}
	return (sum ? sum / (v[i].size() - (p >= 1)) : 0);
}

int main()
{
	Fast;
	int T = 1;
	//cin >> T;
	while (T--) {
		int size, q;
		cin >> size;
		p.resize(size + 1);
		v = vector<vector<int>>(size + 1, vector<int>());
		for (int i = 2; i <= size; i++) {
			int x, y;
			cin >> x >> y;
			v[x].push_back(y);
			v[y].push_back(x);
		}
		cout << fixed << setprecision(15) << dfs() << '\n';
	}
}