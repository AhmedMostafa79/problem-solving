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
	int n;
	cin >> n;
	vector<int>v(n),suf(n+1);
	vector<bool>in(1e5 + 2);
	for (auto& i : v)
		cin >> i;
	set<int>s;
	for (int i = n - 1; i >= 0; i--) {
		suf[i] = s.size();
		s.insert(v[i]);
	}
	ll res = 0;
	for (int i = 0; i < n; i++) {
		if(!in[v[i]])
		res += suf[i];
		in[v[i]] = 1;
	}
	cout << res << "\n";
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