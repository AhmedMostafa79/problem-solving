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

void solve() {
	int n, k;
	cin >> k;
	string s;
	cin >> s;
	n = s.size();
	int ar[26]{};
	string need;
	for (auto i : s)
		if (i != '?')
			ar[i - 'a'] = 1;
	for (int i = 0; i < k; i++)
		if (!ar[i])
			need += 'a' + i;
	for (int i = n / 2; i < n; i++) {
		int c = s[i], ops = s[n - i - 1];
		if (c == '?' and ops == '?') {
			if (need.size()) {
				s[i] = s[n - i - 1] = need.back();
				need.pop_back();
			}
			else s[i] = s[n - i - 1] = 'a';
		}
		else if (c == '?')
			s[i] = ops;
		else if (ops == '?')
			s[n - i - 1] = c;
		else if (c != ops)
			return void(cout << "IMPOSSIBLE\n");
	}
	if (need.size())
		cout << "IMPOSSIBLE\n";
	else
		cout << s << '\n';

}
int main() {
	Fast;
	int t = 1;
	//cin >> t;
	while (t--) {
		solve();
	}
}