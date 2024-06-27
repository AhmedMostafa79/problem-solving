#include <bits/stdc++.h>
using namespace std;
#define  ll long long 
#define  range(v) ((v).begin()),((v).end())
#define Fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define close(n) return cout<<n,0;
int nx[] = { -1,-1,-1,0,0,1,1,1 };
int ny[] = { -1,0,1,-1,1,-1,0,1 };
int countbit(ll n) { return (n > 1 ? (n & 1) + countbit(n >> 1) : n); }
int main()
{
	Fast;
	int T = 1;
	//cin >> T;
	while (T--) {
		int size, d;
		cin >> size >> d;
		vector<int>v(size);
		for (auto& i : v)cin >> i;
		ll res = 0;
		for (int i = 0, j = 0; i < size; i++) {
			while (j < size and v[j] - v[i] <= d)j++;
			ll x = j - i - 1;
			res += (x * (x - 1)) / 2;
		}
		cout << res << "\n";
	}
}