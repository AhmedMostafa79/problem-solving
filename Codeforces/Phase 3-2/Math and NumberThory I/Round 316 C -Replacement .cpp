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
const int N = 1e5 + 3, mod = 1e9 + 7;

void solve() {
	int n, m, k;
	string s;
	cin >> n >> m >> s;
	int res = 0;
	s = ' ' + s;
	for (int i = 1; i <= n; i++) {
		res += (s[i] == '.') and (s[i + 1] == '.');
	}
	while (m--) {
		int x;
		char c;
		cin >> x >> c;
		if (s[x] != '.' and c == '.')
			res += (s[x - 1] == '.') + (s[x + 1] == '.');
		if (s[x] == '.' and c != '.')
			res -= (s[x - 1] == '.') + (s[x + 1] == '.');
		s[x] = c;
		cout << res << '\n';
	}
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