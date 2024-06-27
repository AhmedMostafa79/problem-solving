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
const int N = 2e6 + 3, mod = 1e9 + 7;
void solve() {
	int n;
	cin >> n;
	vector<int>v(n);
	ll s1 = 0, s2 = 0, pre = 0;
	for (auto& i : v)
		cin >> i, s1 += i;
	sort(all(v));
	//s1=sum(v);
	//s2=abs(ai-aj) for i!=j 
	for (int i = 1; i <= n; i++) {
		s2 += v[i - 1] * 1ll * (i - 1) - pre;
		pre += v[i - 1];
	}
	ll res = s1 + 2 * s2;//s2..is same for a[i]>=a[j] or a[i]<=a[j] so multiplied by 2
	int gc = gcd(res, n);
	cout << res / gc << ' ' << n / gc << '\n';
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