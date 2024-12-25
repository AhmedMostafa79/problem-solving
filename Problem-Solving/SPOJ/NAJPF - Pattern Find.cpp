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
const int N = 1e5 + 5, mod = 1e9 + 7, base = 31;
ll mul(ll a, ll b) {
	return a % mod * (b % mod) % mod;
}
ll fp(ll x, ll p) {
	ll res = 1;
	while (p) {
		if (p & 1)
			res = res % mod * x % mod % mod;
		x = x % mod * x % mod % mod;
		p /= 2;
	}
	return res;
}
void solve() {
	string s, pat;
	cin >> s >> pat;
	int n = s.size(), m = pat.size();
	if (m > n)
		return void(cout << "Not Found\n");
	vector<ll>h(n + 1);
	h[0] = s[0] - 'a' + 1;
	for (int i = 1; i < n; i++) {
		h[i] = mul(base, h[i - 1]) + (s[i] - 'a' + 1);
	}
	ll h_pat = pat[0] - 'a' + 1;
	for (int i = 1; i < m; i++) {
		h_pat = mul(h_pat, base) + (pat[i] - 'a' + 1);
	}
	//cout << h_pat << ' ' << h[m-1] << '\n';
	vector<int>res;
	if (h[m - 1] == h_pat)
		res.push_back(1);
	for (int i = m; i < n; i++) {
		ll del = h[i - m] * fp(base, m);
		if (((h[i] - del) % mod + mod) % mod == h_pat)
			res.push_back(i - m + 2);
	}
	if (!res.size())
		cout << "Not Found\n";
	else {
		cout << res.size() << '\n';
		for (auto i : res)
			cout << i << ' ';
		cout << '\n';
	}
}
int main() {
	Fast;
	int t = 1;
	cin >> t;
	while (t--) {
		solve();
	}
}