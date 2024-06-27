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
const int N = 5e5 + 3, mod = 1e9 + 7;
string s;
int n, k;
void solve() {
	cin >> n >> k;
	cin >> s;
	int A = 0;
	if (k == 2) {
		int d = 0;
		for (int i = 0; i < n; i++) {
			if (s[i] == 'A' + (i & 1))
				d++;//if ABAB
		}
		A = min(d, n - d);
		for (int i = 0; i < n; i++) {
			if (d == A)
				s[i] = (i + 1 & 1) + 'A';
			else s[i] = (i & 1) + 'A';
		}
	}
	else {
		for (int i = 0; i < n; i++) {
			if (s[i] == s[i + 1]) {
				A++;
				int a = 'A';
				while (s[i] == a or s[i + 2] == a)
					a++;
				s[i + 1] = a;
			}
		}
	}
	cout << A << " " << s;
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