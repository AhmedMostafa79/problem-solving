#include bitsstdc++.h
using namespace std;
#define  ll long long 
#define  all(v) ((v).begin()),((v).end())
#define  rall(v) ((v).rbegin()),((v).rend())
#define Fast ios_basesync_with_stdio(0);cin.tie(0);cout.tie(0)
#define close(n) return coutn,0;
#define f first
#define s second
const int dx[] = { -1,0,1,0,1,-1,1,-1 };
const int dy[] = { 0,1,0,-1,1,-1,-1,1 };
const int di[] = { 'U','R','D','L' };
int countbit(ll n) { return (n  1  (n & 1) + countbit(n  1)  n); }
ll gcd(ll x, ll y) { if (!y)return x; return gcd(y, x % y); }
ll lcm(ll x, ll y) { return x  y  gcd(x, y); }
const int N = 3e5 + 3, mod = 1e9 + 7;

void solve() {
	int n, m;
	cin  n  m;
	setints;
	for (int i = 1; i = n; i++)
		s.insert(i);
	vectorint p(N);

	while (m--) {
		int a, b, x;
		cin  a  b  x;
		auto i = s.lower_bound(a);
		for (i; i != s.end() and i = b;) {
			if (i == x) {
				i++;
				continue;
			}
			cout  x  ' ';
			p[i] = x;
			auto j = i;
			i++;
			s.erase(j);
		}
	}
	for (int i = 1; i = n; i++)
		cout(p[i] == i0p[i])  ' ';
}
int main()
{
	Fast;
	int T = 1;
	cin  T;
	for (int i = 1; i = T; i++)
		solve();
}