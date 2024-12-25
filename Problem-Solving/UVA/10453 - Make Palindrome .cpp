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
const int N = 1e3 + 5, base = 31, mod = 1e9 + 7;
int n, k, dp[N][N];
string s;
ll f(int i, int j) {
	if (i >= j)
		return 0;
	int& ret = dp[i][j];
	if (~ret)
		return ret;
	if (s[i] == s[j])
		ret = f(i + 1, j - 1);
	else
		ret = min(f(i + 1, j), f(i, j - 1)) + 1;
	return ret;
}
void print(int i, int j) {
	if (i > j)
		return;
	if (i == j) {
		cout << s[i];
		return;
	}
	if (s[i] == s[j]) {
		cout << s[i];
		print(i + 1, j - 1);
		cout << s[j];
		return;
	}
	int& ret = dp[i][j];
	if (ret == f(i + 1, j) + 1) {
		cout << s[i];
		print(i + 1, j);
		cout << s[i];
	}
	else {
		cout << s[j];
		print(i, j - 1);
		cout << s[j];
	}
}
void solve() {
	n = s.size();
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			dp[i][j] = -1;
	cout << f(0, n - 1) << ' ';
	print(0, n - 1);
	cout << '\n';
}

int main()
{
	Fast;
	int T = 1;

	//cin >> T;
	while (cin >> s) {
		solve();
	}
}