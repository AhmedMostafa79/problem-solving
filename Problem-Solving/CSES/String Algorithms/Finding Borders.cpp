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
const int N = 1e6 + 5, base = 31, mod = 1e9 + 7;
int base2 = 37, base3 = 43;
void solve() {
	string s;
	cin >> s;
	int n = s.size();
	vector<int>pre(n + 1), suf(n + 1), pw(n + 1);
	pw[0] = 1;
	for (int i = 1; i < n; i++)
		pw[i] = 1ll * pw[i - 1] * base % mod;
	pre[0] += s[0];
	suf[n - 1] += s.back();
	for (int i = 1; i < n; i++) {
		pre[i] = (1ll * pre[i - 1] * base % mod + s[i]) % mod;//prefix -->h * base + c
		suf[n - i - 1] = (1ll * pw[i] * s[n - i - 1] + suf[n - i]) % mod;//suffix --> c * pw[len(suf)] + h;
	}
	for (int i = 0; i + 1 < n; i++) {
		if (pre[i] == suf[n - i - 1])
			cout << i + 1 << ' ';
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