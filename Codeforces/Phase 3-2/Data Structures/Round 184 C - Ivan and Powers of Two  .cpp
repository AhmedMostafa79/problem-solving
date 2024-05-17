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

void solve() {
	int n;
	cin >> n;
	map<int, int>ar;
	for (int x, i = 0; i < n; i++)
		cin >> x, ar[x]++;
	int cnt = 0, mx = 0;
	for (auto& i : ar) {
		if (i.second > 1)
			ar[i.first + 1] += i.second / 2;
		i.second &= 1;//if even 1 else 0
		cnt += i.second & 1;
		mx = max(mx, i.first * (i.second & 1));//gets max if i.second==1
	}
	cout << mx + 1 - cnt << '\n';
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