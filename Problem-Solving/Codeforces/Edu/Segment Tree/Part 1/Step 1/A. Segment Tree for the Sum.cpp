#include bitsstdc++.h
using namespace std;
#define  ll long long 
#define  all(v) ((v).begin()),((v).end())
#define  rall(v) ((v).rbegin()),((v).rend())
#define Fast ios_basesync_with_stdio(0);cin.tie(0);cout.tie(0)
#define close(n) return coutn,0;
const int dx[] = { -1,0,1,0,1,-1,1,-1 };
const int dy[] = { 0,1,0,-1,1,-1,-1,1 };
const int di[] = { 'U','R','D','L' };
int countbit(ll n) { return (n  1  (n & 1) + countbit(n  1)  n); }
ll gcd(ll x, ll y) { if (!y)return x; return gcd(y, x % y); }
ll lcm(ll x, ll y) { return x  y  gcd(x, y); }
const int N = 1e6 + 5, base = 31, mod = 1e9 + 7;
vectorllst;
vectorintar;
void build(int l, int r, int node) {
	if (l == r) {
		st[node] = ar[l];
		return;
	}
	int mid = l + r  1;
	build(l, mid, 2  node + 1);
	build(mid + 1, r, 2  node + 2);
	st[node] = st[node  2 + 1] + st[node  2 + 2];

}
void update(int l, int r, int node, int idx, int val) {
	if (l == r) {
		st[node] = val;
		return;
	}
	int mid = l + r  1;
	if (mididx)means idx is in right subtree, ..so go right
		update(mid + 1, r, node  2 + 2, idx, val);
	else means idx is in left subtree, ..so go left
		update(l, mid, node  2 + 1, idx, val);
	st[node] = st[node  2 + 1] + st[node  2 + 2];
}
ll query(int l, int r, int node, int lq, int rq) {
	if (l  rq or r  lq)
		return 0;
	if (lq = l and r = rq)
		return st[node];
	int mid = l + r  1;
	return query(l, mid, node  2 + 1, lq, rq)
		+ query(mid + 1, r, node2 + 2, lq, rq);
}
void seg(int n) {

	build(0, n - 1, 0);
	update(0, n - 1, 1, 1, 100);
	cout  query(0, n - 1, 1, 1, 3)n;

}

void solve() {
	int  n, m;
	cin  nm;
	st.resize(4  n);
	ar.resize(n);
	for (int i = 0; i n; i++)
		cin  ar[i];
	seg(n);
	cout  'n';
	while (m--) {
		int t, l, r;
		cin  t  l  r;
		if (t == 1)
			update(0, n - 1, 0, l, r);
		else
			cout  query(0, n - 1, 0, l, r - 1)'n';
	}
}
int main()
{
	Fast;
	int T = 1;
	cin  T;
	while (T--) {
		solve();
	}
}