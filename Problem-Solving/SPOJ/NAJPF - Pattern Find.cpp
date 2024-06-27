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
string a, b;
int n, m;
void Pi(int ar[], string b) {
	int n = b.size();
	int len = 0;
	for (int i = 1; i < n; i++) {
		while (len > 0 and b[len] != b[i])
			len = ar[len - 1];
		if (b[i] == b[len])
			len++;
		ar[i] = len;
	}
}
vector<int>res;
void Kmp(int ar[]) {
	for (int i = m + 1; i < m + n + 1; i++) {
		if (ar[i] == m)
			res.push_back(i - 2 * m + 1);
	}
}
void solve() {
	cin >> a >> b;
	n = a.size();
	m = b.size();
	b += '#' + a;
	int* ar = new int[b.size()] {};
	res.clear();
	Pi(ar, b);
	Kmp(ar);
	if (res.size()) {
		cout << res.size() << '\n';
		for (auto i : res)
			cout << i << " ";
		cout << '\n';
	}
	else cout << "Not Found\n";
}
int main()
{
	Fast;
	int T = 1;
	cin >> T;
	while (T--) {
		solve();
	}
}