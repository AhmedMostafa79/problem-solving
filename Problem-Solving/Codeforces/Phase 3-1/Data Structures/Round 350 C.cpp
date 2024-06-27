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
const int N = 2e7 + 3, mod = 1e9 + 7;
void solve() {
	int n;
	cin >> n;
	map<int, int>ar;
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		ar[x]++;
	}
	int m;
	cin >> m;
	vector<int>a(m), b(m);
	for (auto& i : a)
		cin >> i;
	for (auto& i : b)
		cin >> i;
	int res = 0, j = 0;
	for (int i = 0; i < m; i++) {
		if (ar[a[i]] > res)
			j = i, res = ar[a[i]];
		else if (ar[a[i]] == res and ar[b[i]] > ar[b[j]])
			j = i;
	}
	cout << j + 1 << '\n';
}

int main()
{
	Fast;
	int T = 1;
	//cin >> T;
	for (int i = 1; i <= T; i++) {
		solve();
		cout << '\n';
	}
	return 0;
}