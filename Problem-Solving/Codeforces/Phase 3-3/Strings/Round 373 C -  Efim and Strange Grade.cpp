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

	string s;
	int t, n;
	cin >> n >> t >> s;
	int i = s.find('.') + 1;
	while (i < n and s[i] < '5')
		i++;
	while (s[i - 1] != '.' and s[i] >= '5' and t)
		s[i - 1]++, i--, t--;

	if (s[i - 1] == '.' and s[i] >= '5' and t) {
		i -= 2;
		if (s[i] == '9') {
			while (i >= 0 and s[i] == '9')
				s[i] = '0', i--;
			if (i < 0)
				s = '1' + s;
			else s[i]++;
			i++;
		}
		else
			s[i]++;
	}
	cout << s.substr(0, max(i + 1, (int)s.find('.'))) << '\n';
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