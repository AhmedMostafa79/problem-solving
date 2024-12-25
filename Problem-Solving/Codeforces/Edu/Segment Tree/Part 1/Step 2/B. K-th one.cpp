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
const int N = 1e6 + 5, base = 31, mod = 1e9 + 7;
vector<int>ar;
vector<int>st;

void build(int l, int r, int node) {
	if (l == r)
		return void(st[node] = ar[l]);
	int mid = l + r >> 1;
	int c1 = node * 2 + 1;
	int c2 = node * 2 + 2;
	build(l, mid, c1);
	build(mid + 1, r, c2);
	st[node] = st[c1] + st[c2];
}
void update(int l, int r, int node, int idx) {
	if (l == r)
		return void(st[node] ^= 1);
	int mid = l + r >> 1;
	int c1 = node * 2 + 1;
	int c2 = node * 2 + 2;
	if (mid < idx)
		update(mid + 1, r, c2, idx);
	else
		update(l, mid, c1, idx);
	st[node] = st[c1] + st[c2];
}
int query(int l, int r, int node, int k) {
	if (l == r)
		return l;
	int mid = l + r >> 1;
	int c1 = node * 2 + 1;
	int c2 = node * 2 + 2;
	int lft = st[c1];
	if (k <= lft)
		return query(l, mid, c1, k);
	else
		return query(mid + 1, r, c2, k - lft);

}
void solve() {
	int n, m;
	cin >> n >> m;
	ar.resize(n);
	for (int i = 0; i < n; i++)
		cin >> ar[i];
	st.resize(4 * n);
	build(0, n - 1, 0);
	while (m--) {
		int t, l, r;
		cin >> t >> l;
		if (t == 1)
			update(0, n - 1, 0, l);
		else {
			cout << query(0, n - 1, 0, l + 1) << '\n';
		}

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