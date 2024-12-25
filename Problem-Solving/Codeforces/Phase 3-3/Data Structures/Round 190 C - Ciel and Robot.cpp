#include <bits/stdc++.h>
using namespace std;
#define  ll long long 
#define  all(v) ((v).begin()),((v).end())
#define  rall(v) ((v).rbegin()),((v).rend())
#define Fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define close(n) return cout<<n,0;
#define files  freopen("closing.in", "r", stdin); freopen("closing.out", "w", stdout);
const int dx[] = { -1,0,1,0,1,-1,1,-1 };
const int dy[] = { 0,-1,0,1,1,-1,-1,1 };
const int di[] = { 'U','R','D','L' };
int countbit(ll n) { return (n > 1 ? (n & 1) + countbit(n >> 1) : n); }
ll gcd(ll x, ll y) { if (!y)return x; return gcd(y, x % y); }
ll lcm(ll x, ll y) { return x * y / gcd(x, y); }
const int N = 1e3 + 5;

void solve() {
	int n, a, b;
	string s;
	cin >> a >> b >> s;
	vector<pair<int, int>>v(1);
	int x = 0, y = 0;
	for (auto i : s) {
		if (i == 'L')
			x--;
		else if (i == 'R')
			x++;
		else if (i == 'U')
			y++;
		else y--;
		v.push_back({ x,y });
	}
	for (auto i : v) {
		int t = 0;
		if (x)
			t = (a - i.first) / x;
		if (y)
			t = (b - i.second) / y;
		if (t < 0)
			continue;
		if (t * x == a - i.first and t * y == b - i.second)
			return void(cout << "Yes\n");
	}
	cout << "No\n";
}
int main() {
	Fast;
	int t = 1;
	//cin >> t;
	while (t--) {
		solve();
	}
}