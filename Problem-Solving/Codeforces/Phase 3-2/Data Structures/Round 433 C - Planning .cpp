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
	int n, k, x, i;
	cin >> n >> k;
	set<pair<int, int>>s;
	for (i = 1; i <= k; i++)
		cin >> x, s.insert({ x,i });
	vector<int>t(n + 1);
	ll res = 0;
	for (; i <= n + k; i++) {
		if (i <= n)
			cin >> x, s.insert({ x,i });
		auto p = s.rbegin();
		res += (i - p->second) * 1ll * p->first;
		t[p->second] = i;
		s.erase(*p);
	}
	cout << res << '\n';
	for (int i = 1; i <= n; i++)
		cout << t[i] << ' ';
	cout << '\n';

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