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
	ll lc = 1,mx=1;
	if (n == 2)
		return void(cout << 2 << '\n');
	for (int i = n; i >= max(1,n - 100); i--) {
		for (int i2 = i-1; i2 >= max(1,n - 100); i2--) {
			for (int i3 = i2-1 ; i3 >= max(1,n - 100); i3--) {
				if (gcd(i, i2) == 1 and gcd(i, i3) == 1 and gcd(i2, i3) == 1)
					mx = max(mx, 1ll * i * i2 * i3);
						/*
						* i could use this but, time differs a lot
						lc = lcm(i*1ll, lcm(i2*1ll, i3*1ll));
						mx = max(mx, lc);

						*/
			}
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