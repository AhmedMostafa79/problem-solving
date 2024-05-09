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
const int N = 2e7 + 3, mod = 1e9 + 7;
void solve(){
	int ar[7][7]{},c=0;
	for (int i = 1; i <= 6; i++) {
		set<int>s;
		for (int i = 1; i <= 4; i++) {
			int x;
			cin >> x;
			s.insert(x);
		}
		if (s.size() == 1)
			c++;
		else if (s.size() == 2)
			ar[*s.begin()][*s.rbegin()]++;
		else
			c = 5;
	}
	for (int i = 1; i <= 6; i++) {
		for (int j = 1; j <= 6; j++)
			if (ar[i][j] > 1)
				c = 5;
	}
	cout << (c == 2 ? "YES\n" : "NO\n");
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