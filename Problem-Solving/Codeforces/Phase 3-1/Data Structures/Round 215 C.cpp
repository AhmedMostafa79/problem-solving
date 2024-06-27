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
struct f {
	int x, y, z;
};
void solve() {
	string s;
	cin >> s;
	vector<int>in;
	vector<f>ar(s.size() + 2);
	for (int i = 1; i <= s.size(); i++) {
		ar[i].x += (s[i - 1] == 'x') + ar[i - 1].x;
		ar[i].y += (s[i - 1] == 'y') + ar[i - 1].y;
		ar[i].z += (s[i - 1] == 'z') + ar[i - 1].z;
	}
	int m;
	cin >> m;
	while (m--) {
		int l, r;
		cin >> l >> r;
		int x, y, z;
		x = ar[r].x - ar[l - 1].x;
		y = ar[r].y - ar[l - 1].y;
		z = ar[r].z - ar[l - 1].z;
		int n = max({ abs(x - y),abs(x - z),abs(y - z) });
		cout << (n > 1 and r - l + 1 > 2 ? "NO\n" : "YES\n");
	}
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