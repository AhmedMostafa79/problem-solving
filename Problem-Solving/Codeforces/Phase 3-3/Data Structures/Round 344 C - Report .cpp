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
const int N = 2e5 + 5, base = 31, mod = 1e9 + 7;

void solve() {
	int n, m;
	cin >> n >> m;
	vector<int>a(n + 2), b(n + 2), r(m + 2), t(m + 2);
	for (int i = 0; i < n; i++)
		cin >> a[i];
	int p = 0;
	for (int i = 1; i <= m; i++) {
		int tt, rr;
		cin >> tt >> rr;
		while (p > 0 and r[p - 1] <= rr)
			p--;
		r[p] = rr;
		t[p] = tt;
		p++;
	}
	int h = r[0];
	r[p++] = 0;
	for (int i = 0; i < h; i++)
		b[i] = a[i];
	sort(b.begin(), b.begin() + h);
	int l = 0;
	for (int i = 1; i < p; i++) {
		for (int j = r[i - 1]; j > r[i]; j--) {
			if (t[i - 1] == 1)
				a[j - 1] = b[--h];
			else if (t[i - 1] == 2) a[j - 1] = b[l++];
		}
	}
	for (int i = 0; i < n; i++)
		cout << a[i] << " ";
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