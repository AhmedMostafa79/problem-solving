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

char ar[2002][1002]{};
void solve() {
	int n;
	cin >> n;
	int x = 0, mny = 1000, mxy = 1000, y = 1000;
	for (int i = 1; i <= n; i++) {
		int c;
		cin >> c;
		for (int j = x; j < x + c; j++) {
			if (i & 1)
				ar[y][j] = '/', y++;
			else y--, ar[y][j] = '\\';
		}
		mxy = max(mxy, y);
		mny = min(mny, y);
		x += c;
	}
	for (int j = mxy - 1; j >= mny; j--) {
		for (int i = 0; i < x; i++) {
			if (ar[j][i])
				cout << ar[j][i];
			else cout << ' ';
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