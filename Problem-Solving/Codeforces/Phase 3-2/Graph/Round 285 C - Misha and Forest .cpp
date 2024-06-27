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
//const int N = 1e7 + 3, mod = 1e9 + 7;
void solve() {
	int n, m = 0;
	vector<int>a((1 << 16) + 2), b((1 << 16) + 2);
	queue<int>q;
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> a[i] >> b[i];
		if (a[i] == 1)
			q.push(i);
		m += a[i];//m+ number of nodes
	}
	cout << m / 2 << '\n';//as nodes are double counted;
	while (!q.empty()) {
		int x = q.front();
		q.pop();
		if (!a[x])
			continue;
		a[b[x]]--;
		b[b[x]] ^= x;
		if (a[b[x]] == 1)
			q.push(b[x]);
		cout << x << " " << b[x] << '\n';
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