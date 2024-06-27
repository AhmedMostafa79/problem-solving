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
int main()
{
	Fast;
	int T = 1;
	//cin >> T;
	while (T--) {
		int a, b;
		cin >> a >> b;
		if (a - b > 1)close(-1)
			string res;
		while (a and b) {
			res += "01";
			a--, b--;
		}
		if (a)res += "0";
		string res2;
		if (b)res2 += (b == 1 ? "1" : "11"), b -= min(b, 2);
		for (int i = 0; i < res.size(); i++) {
			res2 += res[i];
			if (b and res[i] == '1')res2 += res[i], b--;
		}
		if (b)cout << -1;
		else cout << res2 << '\n';
	}
}