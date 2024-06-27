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

int main()
{
	Fast;
	int T = 1;
	//cin >> T;
	while (T--) {
		int size;
		cin >> size;
		vector<int>v(size + 2), res(size + 2);
		for (int i = 1; i <= size; i++) {
			cin >> v[i];
			res[1] += size / i;
			res[i] -= size / i;
			if (size % i)
				res[size % i + 1]--, res[1]++;
		}
		ll ans = 0;
		for (int i = 1; i <= size; i++)
			res[i] += res[i - 1], ans ^= (res[i] &= 1) * i;
		for (int i = 1; i <= size; i++) {
			ans ^= v[i];
		}
		/*	for (int i = 1; i <= size; i++)
				cout << res[i] << ' ';*/
		cout << ans << '\n';
	}
}