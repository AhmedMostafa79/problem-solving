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
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n, m, K;
	cin >> n >> m;
	cin >> K;
	int a = 1, b = 1, res = 0;
	int k1[11]{}, k2[11]{};

	for (int i = 0; i < K; i++)
		cin >> k1[i] >> k2[i];

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			int dif = n + m;
			for (int r = 0; r < K; r++) {
				dif = min(dif, abs(k1[r] - i) + abs(k2[r] - j));
			}
			if (res < dif)
				res = dif, a = i, b = j;
		}
	}
	cout << a << ' ' << b;
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