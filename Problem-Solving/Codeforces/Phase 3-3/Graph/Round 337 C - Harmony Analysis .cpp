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
const int N = 1e5 + 5, mod = 1e9 + 9;

void solve() {
	int k;
	cin >> k;
	k = 1 << k;
	for (int i = 0; i < k; i++) {
		for (int j = 0; j < k; j++) {
			cout << (countbit(i & j) % 2 ? "*" : "+");
		}
		cout << '\n';
	}
}
int main()
{
	Fast;
	int T = 1;
	//cin >> T;
	//seive(1e5);

	while (T--) {
		solve();
	}
}