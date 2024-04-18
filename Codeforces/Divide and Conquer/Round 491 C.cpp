#include <bits/stdc++.h>
using namespace std;
#define  ll long long 
#define  range(v) ((v).begin()),((v).end())
#define Fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define close(n) return cout<<n,0;
int nx[] = { -1,-1,-1,0,0,1,1,1 };
int ny[] = { -1,0,1,-1,1,-1,0,1 };
ll n;
bool  c(ll k) {
	ll res = 0, nn = n;
	while (nn > 0) {
		nn -= k;
		if (nn <= 0)break;
		res += nn / 10, nn -= nn / 10;
	}
	return res * 2 > n;
}
int main()
{
	Fast;
	int T = 1;
	//cin >> T;
	while (T--) {
		cin >> n;
		ll l = 1, r = n;
		while (l < r) {
			ll mid = (l + r) / 2;
			if (c(mid)) {
				l = mid + 1;
			}
			else {
				r = mid;
			}
		}
		cout << l << '\n';
	}
}