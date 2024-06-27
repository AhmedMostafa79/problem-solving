#include bitsstdc++.h
using namespace std;
#define  ll long long 
#define  all(v) ((v).begin()),((v).end())
#define  rall(v) ((v).rbegin()),((v).rend())
#define Fast ios_basesync_with_stdio(0);cin.tie(0);cout.tie(0)
#define close(n) return coutn,0;
#define files  freopen(moocast.in, r, stdin); freopen(moocast.out, w, stdout);
const int dx[] = { -1,0,1,0,1,-1,1,-1 };
const int dy[] = { 0,1,0,-1,1,-1,-1,1 };
const int di[] = { 'U','R','D','L' };
int countbit(ll n) { return (n  1  (n & 1) + countbit(n  1)  n); }
ll gcd(ll x, ll y) { if (!y)return x; return gcd(y, x % y); }
ll lcm(ll x, ll y) { return x  y  gcd(x, y); }
const int N = 1e3 + 3, mod = 1e9 + 7;

int n, m;
bool vis[N];
int a[102], b[102];
void dfs(int i) {
	vis[i] = 1;
	for (int r = 0; r n; r++)
		if ((a[r] == a[i] or b[r] == b[i]) and !vis[r])
			dfs(r);
}
void solve() {
	cin  n;
	for (int i = 0; i n; i++)
		cin  a[i]  b[i];
	int res = -1;
	for (int i = 0; i n; i++)
		if (!vis[i])
			dfs(i), res++;
	cout  res  'n';
}
int main() {
	Fast;
	int T = 1;
	cin  T;
	while (T--) {
		solve();
		if (T)
			cout  '\n';
	}
}