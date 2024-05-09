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
int n = 8;
vector<vector<char>>v;
vector<vector<int>>vis;
bool lose;
bool valid(int i, int j) {
	return i >= 0 and j >= 0 and i < n and j < n;
}
void dfs(int i, int j, int k) {
	if (k >= 7)
	{
		cout << "WIN\n";
		exit(0);
	}
	for (int l = -1; l <= 1; l++) {
		for (int r = -1; r <= 1; r++) {
			int nx = l + i, ny = r + j;
			if (!valid(nx, ny))continue;
			if (nx - k >= 0 and v[nx - k][ny] == 'S')continue;
			if (nx - k >= 1 and v[nx - k - 1][ny] == 'S')continue;
			dfs(nx, ny, k + 1);
		}
	}
}
int main()
{
	Fast;
	int T = 1;
	//cin >> T;
	while (T--) {
		v = vector<vector<char>>(n, vector<char>(n));
		vis = vector<vector<int>>(n, vector<int>(n));
		for (int i = 0; i < 8; i++) {
			for (int j = 0; j < 8; j++) {
				cin >> v[i][j];

			}
		}

		dfs(n - 1, 0, 0);
		cout << "LOSE";
	}
}