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
vector<int>st;
vector<int>ar;
void build(int l, int r, int node) {
	if (l == r) {
		st[node] = ar[l];
		return;
	}
	int c1 = node * 2 + 1, c2 = node * 2 + 2;
	int mid = l + r >> 1;
	build(l, mid, c1);
	build(mid + 1, r, c2);
	//if (st[c1].first == st[c2].first)//if min in c1==c2 add freq[c1] +freq[c2]
	//	st[node].second = st[c1].second + st[c2].second;
	//else if(st[c1].first<st[c2].first)
	//	st[node] =st[c1];
	//else 
	//	st[node] =st[c2];
	st[node] = min(st[c1], st[c2]);
}
void update(int l, int r, int node, int idx, int val) {
	if (l == r) {
		st[node] = val;
		return;
	}
	int mid = l + r >> 1;
	int c1 = node * 2 + 1, c2 = node * 2 + 2;
	if (mid < idx) {
		update(mid + 1, r, c2, idx, val);
	}
	else
		update(l, mid, c1, idx, val);
	//if (st[c1].first == st[c2].first)//if min in c1==c2 add freq[c1] +freq[c2]
	//	st[node].second = st[c1].second + st[c2].second;
	//st[node].first = min(st[node * 2 + 1].first, st[node * 2 + 2].first);
	st[node] = min(st[c1], st[c2]);
}
int query(int l, int r, int node, int lq, int rq) {
	if (l > rq or r < lq)
		return 2e9;
	if (lq <= l and r <= rq)
		return st[node];
	int mid = l + r >> 1;
	int lft = query(l, mid, node * 2 + 1, lq, rq);
	int rt = query(mid + 1, r, node * 2 + 2, lq, rq);
	return min(lft, rt);
}
void solve() {
	int n, q;
	cin >> n >> q;
	ar.resize(n);
	st.resize(4 * n);
	for (int i = 0; i < n; i++)
		cin >> ar[i];
	build(0, n - 1, 0);
	while (q--) {
		int t, l, r;
		cin >> t >> l >> r;
		if (t == 1) {
			update(0, n - 1, 0, l, r);
		}
		else {
			cout << query(0, n - 1, 0, l, r - 1) << '\n';
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