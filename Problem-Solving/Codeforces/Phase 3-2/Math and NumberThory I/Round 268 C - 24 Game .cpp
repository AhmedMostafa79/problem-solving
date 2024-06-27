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
		int n;
		cin >> n;
		if (n <= 3)
			cout << "NO\n";
		else if (n % 2 == 1) {
			cout << "YES\n";
			cout << "2 - 1 = 1\n";
			cout << "3 + 1 = 4\n";
			cout << "4 * 5 = 20\n";
			cout << "4 + 20 = 24\n";
			for (int i = 6; i < n; i += 2) {
				cout << i + 1 << " - " << i << " = " << 1 << '\n';
				cout << "24 * 1 = 24\n";
			}
		}
		else {
			cout << "YES\n";
			cout << "2 * 1 = 2\n";
			cout << "2 * 3 = 6\n";
			cout << "4 * 6 = 24\n";
			for (int i = 5; i < n; i += 2) {
				cout << i + 1 << " - " << i << " = " << 1 << '\n';
				cout << "24 * 1 = 24\n";
			}
		}
	}
}