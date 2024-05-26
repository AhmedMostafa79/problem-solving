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
const int N = 2e6 + 3, mod = 1e9 + 7;
void solve() {
	string s;
	cin >> s;
	map<int, vector<int>>v;
	int cur = 0, remz = 0;
	for (int i = 0; i < s.size(); i++) {
		if (s[i] == '0')
			v[++cur].push_back(i + 1);
		else v[cur--].push_back(i + 1);
		if (cur < 0)
			return void(cout << -1);
		remz = max(remz, cur);//get max num   of 0
	}
	if (remz != cur)
		return void(cout << -1);//remained 0 must be = to front 0 as 000011110000
	cout << v.size() << '\n';
	for (auto i : v) {
		cout << i.second.size() << ' ';
		for (auto j : i.second) {
			cout << j << " ";
		}
		cout << '\n';
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