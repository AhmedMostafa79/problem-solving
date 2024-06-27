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
	string s;
	getline(cin, s);
	vector<int>rev(s.size());
	for (int i = 0; i < s.size(); i++) {
		bitset<8>b(s[i]);
		for (int i = 0; i < 4; i++) {//swap
			int t = b[i];
			b[i] = b[7 - i];
			b[7 - i] = t;
		}
		rev[i] = b.to_ullong();
	}
	for (int i = 0; i < s.size(); i++) {
		int a = (i ? rev[i - 1] : 0), b = rev[i];
		int t = (a - b + 256) % 256;
		cout << t << '\n';
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