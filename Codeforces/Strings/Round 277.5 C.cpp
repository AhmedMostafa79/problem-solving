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
void ma(int n, int  s) {
	while (s) {
		cout << min(s, 9);
		s -= min(9, s);
		n--;
	}
	while (n--)
		cout << 0;
}
void mi(int n, int s) {
	for (int i = n - 1; i >= 0; i--) {
		int j = max(0, s - 9 * i);
		if (j == 0 and s and i == n - 1)
			j = 1;
		cout << j;
		s -= j;
	}
}
void solve() {
	int n, s;
	cin >> n >> s;
	if (n == 1 and !s)
		return void(cout << "0 0");
	if (!s or n * 9 < s)
		return void(cout << "-1 -1");
	mi(n, s);
	cout << " ";
	ma(n, s);
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