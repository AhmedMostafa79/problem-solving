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
//const int N = 1e7 + 3, mod = 1e9 + 7;
void solve() {
	int n, m, k;
	cin >> n >> m >> k;
	int cells = n * m / k, a = 1, b = 1, x = 1;
	for (int i = 1; i <= k; i++) {
		if (i == k)
			cells += n * m % k;
		cout << cells << ' ';
		for (int j = 1; j <= cells; j++) {
			cout << a << " " << b << ' ';
			b += x;
			if (b > m)
				b = m, x = -1, a++;
			else if (b < 1)
				b = 1, x = 1, a++;
		}
		cout << '\n';
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