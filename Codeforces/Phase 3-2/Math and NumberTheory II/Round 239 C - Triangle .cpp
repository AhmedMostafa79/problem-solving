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
const int N = 1e7 + 3, mod = 1e9 + 7;

void solve() {
	int d1, d2;
	cin >> d1 >> d2;
	for (int i = 1; i <= 1e3; i++) {//x2
		for (int j = 1; j <= 1e3; j++) {//y2
			if (i * i + j * j == d1 * d1) {//x2*x2+y2*y2=b as x1=0 and x1=0
				for (int k = 1; k <= 1e3; k++) {//x3 -->moving x3 from x2 by k
					if (i * k % j == 0) {
						int l = -k * i / j;//y3
						if (!l or k == i or j == l)//x3==x1 or x2==x3 or y2==y3
							continue;
						if (l * l + k * k == d2 * d2) {
							cout << "YES\n";
							cout << "0 0\n";
							cout << i << " " << j << '\n';
							cout << k << " " << l << '\n';
							return;
						}
					}
				}
			}
		}

	}
	cout << "NO\n";
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