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
const int N = 2e3 + 3, mod = 1e9 + 7;
void solve() {
	string s;
	cin >> s;
	vector<pair<int, char>>ar(26);
	for (auto i : s)
		ar[i - 'a'].first++, ar[i - 'a'].second = i;
	sort(all(ar));
	int n = s.size();
	fill(all(s), '0');
	for (int i = 2; i <= n; i++) {
		for (int j = i - 1; j < n; j += i) {
			if (s[j] != '0')
				continue;
			if (!ar.back().first)
				return void(cout << "NO\n");
			s[j] = ar.back().second;
			ar.back().first--;
		}
		if (!ar.back().first)
			ar.pop_back();
	}
	for (int i = 2; i <= n; i++) {
		for (int j = i; j <= n; j += i) {
			if (s[i - 1] != s[j - 1])
				return void(cout << "NO\n");
		}
	}
	s[0] = ar.back().second;
	cout << "YES\n" << s << '\n';
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
}