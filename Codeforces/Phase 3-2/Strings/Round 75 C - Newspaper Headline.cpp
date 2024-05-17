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
const int N = 5e5 + 3, mod = 1e9 + 7;

void solve() {
	string a, b;
	cin >> a >> b;
	vector<int>v[26]{};
	for (int i = 0; i < a.size(); i++)
		v[a[i] - 'a'].push_back(i + 1);
	int cur = 1, res = 1;
	for (int i = 0; i < b.size(); i++) {
		int c = b[i] - 'a';
		if (v[c].empty())
			return void(cout << -1);
		auto f = lower_bound(v[c].begin(), v[c].end(), cur);
		if (f == v[c].end())
			res++, cur = v[c][0], cur++;
		else cur = *f++, cur++;
	}
	cout << res << '\n';
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