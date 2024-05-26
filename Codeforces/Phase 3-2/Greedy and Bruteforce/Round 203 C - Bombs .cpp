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
const int N = 1e7 + 3, mod = 1e9 + 9;
bool cmp(pair<int, int>a, pair<int, int>b) {
	return abs(a.first) + abs(a.second) < abs(b.first) + abs(b.second);
}
void solve() {
	int n;
	cin >> n;
	vector<pair<int, int>>v(n);//coords,negative or not
	int ops = n * 2;
	for (auto& i : v) {
		cin >> i.first >> i.second;
		ops += (i.first != 0) * 2 + (i.second != 0) * 2;
	}
	sort(all(v), cmp);
	cout << ops << '\n';
	for (auto i : v) {
		int x = i.first, y = i.second;
		if (x)
			cout << 1 << " " << abs(x) << (x < 0 ? " L" : " R") << '\n';
		if (y)
			cout << 1 << " " << abs(y) << (y < 0 ? " D" : " U") << '\n';
		cout << 2 << '\n';
		if (y)
			cout << 1 << " " << abs(y) << (y > 0 ? " D" : " U") << '\n';
		if (x)
			cout << 1 << " " << abs(x) << (x > 0 ? " L" : " R") << '\n';
		cout << 3 << '\n';
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