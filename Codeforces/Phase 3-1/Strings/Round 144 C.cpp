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
	string s, p;
	cin >> s >> p;
	int ar[26]{};
	for (auto i : p)
		ar[i - 'a']++;
	int n = s.size(), np = p.size(), res = 0, ex = 0;
	for (int j = 0, i = 0; i < n; i++) {
		while (j < n and j < i + p.size()) {
			if (s[j] == '?')
				ex++;
			else
				np -= ar[s[j] - 'a'] >= 1, ar[s[j] - 'a']--;
			j++;
		}
		bool val = 1;
		for (int j = 0; j < 26; j++)
			if (ar[j] < 0)
				val = 0;
		if (val and ex == np)
			res++;
		if (s[i] != '?')
			ar[s[i] - 'a']++, np += ar[s[i] - 'a'] >= 1;
		ex -= s[i] == '?';
	}
	cout << res << '\n';
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