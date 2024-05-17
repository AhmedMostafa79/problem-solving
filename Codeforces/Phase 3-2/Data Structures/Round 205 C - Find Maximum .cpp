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
	int n;
	cin >> n;
	vector<int>v(n + 1);
	string s;
	for (int i = 0; i < n; i++)
		cin >> v[i];
	cin >> s;
	reverse(all(v));// for simplicity
	reverse(all(s));
	s = ' ' + s;
	vector<ll>pre(n + 1), suf(n + 2);
	ll mx = 0;
	for (int i = 1; i <= n; i++) {
		pre[i] += pre[i - 1] + v[i] * (s[i] == '1');
		mx += v[i] * (s[i] == '1');//calc default
	}
	for (int i = n; i >= 1; i--)
		suf[i] += suf[i + 1] + v[i];

	for (int i = 1; i <= n; i++) {
		if (s[i] == '1') {
			mx = max(mx, pre[i - 1] + suf[i + 1]);
		}
	}
	cout << mx << '\n';
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