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
const int N = 1e5 + 3, mod = 1e9 + 7;
vector<int>primes;
void seive(ll n) {
	bool isprime[N]{};
	memset(isprime, true, sizeof isprime);
	for (ll i = 2; i <= n; i++) {
		if (isprime[i]) {
			primes.push_back(i);
			for (int j = i * i; j <= n; j += i) {
				isprime[j] = 0;
			}
		}
	}
}
string ask(int a) {
	cout << a << '\n';
	cout.flush();
	string ret;
	cin >> ret;
	return ret;
}
void solve() {
	int p = 0, q = 20;
	vector<int>v;
	for (int i = 0; i < 15 and q; i++, q--) {
		if (p <= 1 and ask(primes[i]) == "yes") {
			p++;
			if (primes[i] * primes[i] <= 100)
				v.push_back(primes[i] * primes[i]);
		}
	}
	for (auto i : v)
		if (q and p <= 1 and ask(i) == "yes")
			p++;
	cout << (p <= 1 ? "prime\n" : "composite");
}
int main()
{
	Fast;
	int T = 1;
	//cin >> T;
	seive(100);
	while (T--) {
		solve();
	}
}