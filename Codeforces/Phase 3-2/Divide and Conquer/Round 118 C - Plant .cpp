#include <bits/stdc++.h>
using namespace std;
#define  ll long long 
#define  range(v) ((v).begin()),((v).end())
#define Fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define close(n) return cout<<n,0;
int nx[] = { -1,-1,-1,0,0,1,1,1 };
int ny[] = { -1,0,1,-1,1,-1,0,1 };
int countbit(ll n) { return (n > 1 ? (n & 1) + countbit(n >> 1) : n); }
string to_decimal(int n) {
	if (n <= 1)return string("") + char(n + '0');
	return  to_decimal(n >> 1) + string("") + char((n & 1) + '0');
}
const int mod = 1000000007;
ll fast_power(ll n, ll p) {//time O(log(p))
	if (!p)return 1;
	ll ret = fast_power(n, p / 2);
	return ((p & 1) ? ((((ret % mod) * (ret % mod)) % mod) * n) % mod : ((ret % mod) * (ret % mod)) % mod);
}
int main()
{
	Fast;
	int T = 1;
	//cin >> T;
	while (T--) {
		ll y;
		cin >> y;
		ll res = fast_power(2, y);
		cout << ((res * res + res) / 2 % mod) << '\n';
	}
}