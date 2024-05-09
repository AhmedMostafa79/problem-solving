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
struct f {
	int  times, l, r;
	ll value;
};
int main()
{
	Fast;
	int T = 1;
	//cin >> T;
	while (T--) {
		int size, x, y;
		cin >> size;
		vector<pair<int, int>>v(size);
		for (int i = 0; i < size; i++) {
			cin >> x >> y;
			v[i].first = x, v[i].second = y;
		}
		sort(range(v));
		ll c = 1;
		ll res = 0;
		swap(v[0].first, v[0].second);
		for (int i = 1; i < size; i++) {
			if (v[i].first == v[i - 1].second)c++;
			else res += (c * (c - 1)) / 2, c = 1;
			swap(v[i].first, v[i].second);
		}
		res += (c * (c - 1)) / 2;
		c = 1;
		sort(range(v));
		for (int i = 1; i < size; i++) {
			if (v[i].first == v[i - 1].first)c++;
			else if (v[i].first != v[i - 1].first)res += (c * (c - 1)) / 2, c = 1;
		}
		res += (c * (c - 1)) / 2;;
		c = 1;
		for (int i = 1; i < size; i++) {
			if (v[i].first == v[i - 1].first and v[i].second == v[i - 1].second)
				c++;
			else res -= (c * (c - 1) / 2), c = 1;
		}
		res -= (c * (c - 1) / 2);
		cout << res << '\n';
	}
}