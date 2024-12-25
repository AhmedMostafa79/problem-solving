#include <bits/stdc++.h>
using namespace std;
#define  ll long long 
#define  all(v) ((v).begin()),((v).end())
#define  rall(v) ((v).rbegin()),((v).rend())
#define Fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define close(n) return cout<<n,0;
#define files  freopen("closing.in", "r", stdin); freopen("closing.out", "w", stdout);
const int dx[] = { -1,0,1,0,1,-1,1,-1 };
const int dy[] = { 0,-1,0,1,1,-1,-1,1 };
const int di[] = { 'U','R','D','L' };
int countbit(ll n) { return (n > 1 ? (n & 1) + countbit(n >> 1) : n); }
ll gcd(ll x, ll y) { if (!y)return x; return gcd(y, x % y); }
ll lcm(ll x, ll y) { return x * y / gcd(x, y); }
const int N = 1e3 + 5;
char s[12];
int m, q[N];
int f(int c, int sum) {
	for (int i = sum + 1; i <= 10 and c <= m; i++) {
		q[c] = i;//number chosen for cur choice
		if (i != q[c - 1] and s[i - 1] == '1' and f(c + 1, i - sum))
			return 1;
	}
	return  c > m;//means sequnce is more than n so 1
}
void solve() {
	cin >> s >> m;
	int res = f(1, 0);
	if (res) {
		cout << "YES\n";
		for (int j = 1; j <= m; j++)
			cout << q[j] << ' ';
		cout << '\n';
	}
	else cout << "NO\n";
}
int main() {
	Fast;
	int t = 1;
	//cin >> t;
	while (t--) {
		solve();
	}
}