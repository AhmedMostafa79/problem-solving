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
const int N = 2e7 + 3, mod = 1e9 + 7;

void solve() {
	int n;
	cin >> n;
	n *= 2;
	vector<int>v(n);
	for (int i = 1; i <= n; i++)
		cin >> v[i - 1];

	sort(all(v));
	ll mi = 1e9 + 2;
	for (int i = 1; i < n / 2; i++)
		mi = min(mi, 1ll * v[n / 2 + i - 1] - v[i]);
	cout << min((v[n - 1] - v[0]) * 1ll * mi, (v[n / 2 - 1] - v[0]) * 1ll * (v[n - 1] - v[n / 2]));
}

int main()
{
	Fast;
	int T = 1;
	//cin >> T;
	for (int i = 1; i <= T; i++) {
		solve();
		cout << '\n';
	}
	return 0;
}