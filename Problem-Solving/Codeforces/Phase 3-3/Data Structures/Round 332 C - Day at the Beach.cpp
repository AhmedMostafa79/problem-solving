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
	int n;
	cin >> n;
	int res = 0;
	vector<int>v(1);
	for (int x, i = 0; i < n; i++) {
		cin >> x;
		if (x >= v.back()) {
			v.push_back(x);
		}
		else {
			int i = upper_bound(all(v), x) - v.begin();
			int mx = v.back();
			for (int j = v.size(); v.size() > i + 1; j++) {
				v.pop_back();
				mx = max(v[i], mx);
			}
			v.back() = mx;
		}
	}
	cout << v.size() - 1 << '\n';
}
int main() {
	Fast;
	int t = 1;
	//cin >> t;
	while (t--) {
		solve();
	}
}