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
int res = 0;


void solve() {
	double R, x1, x2, y1, y2;
	cin >> R >> x1 >> y1 >> x2 >> y2;
	double x, y, rd = 0;
	if ((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2) > R * R)//fafa outside flat
		x = x1, y = y1, rd = R;
	else {
		double dst = sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
		rd = (R + dst) / 2.0;//midpoint between fafa and center of flat
		if (dst == 0)//fafa is in flat center
			x = x1 + rd, y = y1;
		else {
			x = x2 - (x2 - x1) * rd / dst;
			y = y2 - (y2 - y1) * rd / dst;
		}
	}
	cout << fixed << setprecision(15) << x << ' ' << y << ' ' << rd << '\n';
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