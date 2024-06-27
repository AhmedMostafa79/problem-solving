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
void Pi(int lps[]) {
	int i = 1, len = 0;
	while (i < m) {
		if (b[i] == b[len]) {
			len++;
			lps[i] = len;
			i++;
		}
		else {
			if (len)
				len = lps[len - 1];
			else lps[i] = 0, i++;
		}
	}
}
int  Kmp(int lps[]) {
	int i = 0, j = 0, res = 0;
	while (n - i >= m - j) {
		if (a[i] == b[j]) {
			i++, j++;

		}
		if (j == m) {//match
			j = lps[j - 1];
			res++;
		}
		else if (i < n and a[i] != b[j]) {
			if (j != 0)
				j = lps[j - 1];
			else i++;
		}
	}
	return res;
}
void solve() {
	cin >> a >> b;
	n = a.size(), m = b.size();
	if (n < m)
		return void(cout << 0);
	int* lps = new int[n + 5];
	lps[0] = 0;
	Pi(lps);
	cout << Kmp(lps) << '\n';
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