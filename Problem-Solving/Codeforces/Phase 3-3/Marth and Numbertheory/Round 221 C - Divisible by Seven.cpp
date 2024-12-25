#include <bits/stdc++.h>
using namespace std;
#define  ll long long 
#define  all(v) ((v).begin()),((v).end())
#define  rall(v) ((v).rbegin()),((v).rend())
#define Fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define close(n) return cout<<n,0;
#define files  freopen("closing.in", "r", stdin); freopen("closing.out", "w", stdout);
const int dx[] = { -1,0,1,0,1,-1,1,-1 };
const int dy[] = { 0,-1,0,1,1,-1,-1,1 };
const int di[] = { 'U','R','D','L' };
int countbit(ll n) { return (n > 1 ? (n & 1) + countbit(n >> 1) : n); }
ll gcd(ll x, ll y) { if (!y)return x; return gcd(y, x % y); }
ll lcm(ll x, ll y) { return x * y / gcd(x, y); }
const int N = 5e2 + 5;
int pr[7] = { 1869, 6198, 1896, 1689, 1986, 1968, 1698 };
void solve() {
	string s;
	cin >> s;
	int ar[10]{};
	for (auto i : s)
		ar[i - '0']++;
	ar[1]--, ar[6]--;
	ar[8]--, ar[9]--;
	int c = 0;
	for (int i = 1; i <= 9; i++)
		while (ar[i]--) {
			c = (c * 10 + (i)) % 7;
			cout << i;
		}
	cout << pr[c];
	while (ar[0]--)
		cout << 0;
}
int main() {
	Fast;
	int t = 1;
	//cin>> t;
	while (t--) {
		solve();
	}
}