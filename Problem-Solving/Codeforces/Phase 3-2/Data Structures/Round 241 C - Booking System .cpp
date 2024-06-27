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
	int n, m;
	cin >> n;
	vector<pair<int, pair<int, int>>>cu;
	vector<pair<int, int>>tbl;
	for (int i = 1; i <= n; i++) {
		int x, y;
		cin >> x >> y;
		cu.push_back({ x,{y,i} });//size,pay,index
	}
	cin >> m;
	for (int x, i = 1; i <= m; i++) {
		cin >> x;
		tbl.push_back({ x,i });//capacity,index
	}
	sort(all(cu));
	sort(all(tbl));
	int j = 0, rescost = 0;
	vector<pair<int, int>>res;
	set<pair<int, int>, greater<>>s;
	for (auto i : tbl) {
		while (j < n and cu[j].first <= i.first)
			s.insert(cu[j].second), j++;
		if (s.size()) {
			res.push_back({ s.begin()->second,i.second });
			rescost += s.begin()->first;
			s.erase(s.begin());
		}
	}
	cout << res.size() << " " << rescost << '\n';
	for (auto i : res)
		cout << i.first << " " << i.second << '\n';
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