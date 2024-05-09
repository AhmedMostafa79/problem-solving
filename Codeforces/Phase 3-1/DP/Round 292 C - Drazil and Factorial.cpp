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
		string s;
		cin >> size >> s;
		string ar[10] = { "1","2","3","223","5","35","7","7222","7332" };
		string res;
		for (auto i : s) {
			if (i > '1')
				res += ar[i - '1'];
		}
		sort(rall(res));
		cout << res << '\n';
	}
}