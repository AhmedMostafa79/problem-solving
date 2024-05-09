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
int main()
{
	Fast;
	int T = 1;
	//cin >> T;
	while (T--) {
		string s;
		ll nb, nc, ns, ps, pc, pb, m;
		cin >> s;
		cin >> nb >> ns >> nc;
		cin >> pb >> ps >> pc;
		cin >> m;
		ll B = 0, S = 0, C = 0;
		for (auto i : s) {
			B += (i == 'B');
			S += (i == 'S');
			C += (i == 'C');
		}
		ll l = 0, r = 1e14, res = 0;
		while (l + 1 < r) {
			ll mid = (l + r) / 2;
			ll need = max(0ll, (mid * B - nb) * pb) + max(0ll, (mid * C - nc) * pc) + max(0ll, (mid * S - ns) * ps);
			//cout << mid<<" "<<B<<" "<<pb<<' '<<nb<< '\n';
			if (need <= m)
				l = mid;
			else r = mid;
		}
		cout << l << '\n';
	}
}