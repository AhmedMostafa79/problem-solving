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
const int N = 1e6 + 3, mod = 1e9 + 9;

void solve() {
	string s;
	cin >> s;
	set<string>res;
	int n = s.size();
	bool dp[10002][2]{};
	dp[n][1] = dp[n][0] = 1;
	for (int i = n - 2; i >= 5; i--) {
		if (dp[i + 2][1] or (dp[i + 2][0] and s.substr(i, 2) != s.substr(i + 2, 2))) {
			dp[i][0] = 1;
			res.insert(s.substr(i, 2));
		}
		if (dp[i + 3][0] or (dp[i + 3][1] and s.substr(i, 3) != s.substr(i + 3, 3)) and i + 3 <= n) {
			dp[i][1] = 1;
			res.insert(s.substr(i, 3));
		}
	}
	cout << res.size() << '\n';
	for (auto i : res)
		cout << i << ' ';
}
int main()
{
	Fast;
	int T = 1;
	//cin >> T;
	while (T--) {
		solve();
	}
}