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
const int N = 5e5 + 3, mod = 1e9 + 7;

void solve() {
	int w, h, n;
	cin >> w >> h >> n;
	multiset<int>x, y, tx, ty;
	x.insert(0), x.insert(w);//gets cutting segments and their neighbours
	y.insert(0), y.insert(h);
	tx.insert(w), ty.insert(h);//set lengths in x and y
	while (n--) {
		int g;
		char c;
		cin >> c >> g;
		if (c == 'V') {
			x.insert(g);
			int a = *(--x.find(g));
			int b = *(++x.find(g));
			tx.erase(tx.find(b - a));
			tx.insert(g - a), tx.insert(b - g);
		}
		else {
			y.insert(g);
			int a = *(--y.find(g));
			int b = *(++y.find(g));
			ty.erase(ty.find(b - a));
			ty.insert(g - a), ty.insert(b - g);
		}
		ll res = 1ll * (*tx.rbegin()) * (*ty.rbegin());
		cout << res << '\n';
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