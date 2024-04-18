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
		ll n;
		cin >> n;
		ll dif = n * (n + 1) / 2;
		cout << (dif & 1) << '\n';
		vector<int>res;
		dif /= 2;
		for (int i = n; dif and i; i--) {
			if (dif - i >= 0)res.push_back(i), dif -= i;
		}
		cout << res.size() << ' ';
		for (auto i : res)cout << i << ' ';
	}
}