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
	int n;
	cin >> n;
	string s;
	cin >> s;
	int t = count(all(s), 'T'), res = n * 2;
	for (int i = 0; i < n; i++) {
		int e = 0;
		for (int j = 0; j < t; j++) {//for each pos get min number of hamsters need to get full segment of T
			e += s[(i + j) % n] == 'H';
		}
		res = min(res, e);
	}
	cout << res;
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