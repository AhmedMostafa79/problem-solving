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
vector<int>p;
vector<int>isprime(N, 0);
void seive(ll n) {
	isprime[0] = isprime[1] = 0;
	for (ll i = 2; i * i <= n; i++) {
		if (!isprime[i]) {
			for (ll j = i * i; j <= n; j += i) {
				isprime[j] = 1;
			}
		}
	}
	for (int i = 2; i <= n; i++)
		if (!isprime[i])
			p.push_back(i);
}
void solve() {
	int n;
	cin >> n;
	vector<int>a(n + 1), ind(N);
	set<int>v;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		ind[a[i]] = i;
		if (i != a[i])
			v.insert(a[i]);
	}
	seive(n);
	vector<pair<int, int>>res;
	while (v.size()) {
		int x = *v.rbegin(), i;
		while (ind[x] != x) {
			i = ind[x];
			auto it = lower_bound(all(p), x - i + 1);
			if (it == p.end() or *it > (x - i + 1))
				it--;
			int j = i + *it - 1;//new index of v[i]
			res.push_back({ i, j });
			ind[a[j]] = i;
			ind[x] = j;
			swap(a[j], a[i]);
			if (a[i] != i)
				v.insert(a[i]);
		}
		v.erase(x);
	}
	cout << res.size() << '\n';
	for (auto i : res)
		cout << i.first << " " << i.second << '\n';
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