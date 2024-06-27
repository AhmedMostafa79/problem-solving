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
		int size, q;
		cin >> size >> q;
		vector<int>v(size), ar(size + 1);
		for (auto& i : v)
			cin >> i;
		while (q--) {
			int x, y;
			cin >> x >> y;
			ar[x - 1]++;
			ar[y]--;
		}
		for (int i = 1; i < size; i++)
			ar[i] += ar[i - 1];
		for (int i = 0; i < size; i++);

		sort(ar.begin(), --ar.end());
		sort(all(v));
		ll res = 0;
		for (int i = 0; i < size; i++)
			res += (v[i] * 1ll * ar[i]);
		cout << res << '\n';
	}
}