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
		int size, m, k;
		cin >> size >> m >> k;
		vector<ll>v(size + 2), pre(size + 2);
		vector<f>vm(m + 2);
		for (int i = 1; i <= size; i++)cin >> v[i];
		for (int i = 1; i <= m; i++) {
			cin >> vm[i].l >> vm[i].r >> vm[i].value;
		}
		for (int i = 0; i < k; i++) {
			int x, y;
			cin >> x >> y;
			vm[x].times++; vm[y + 1].times--;
		}
		for (int i = 1; i <= m; i++) {
			vm[i].times += vm[i - 1].times;
		}
		for (int i = 1; i <= m; i++) {
			int x = vm[i].l, y = vm[i].r;
			pre[x] += vm[i].value * vm[i].times;
			pre[y + 1] -= vm[i].value * 1ll * vm[i].times;
		}
		for (int i = 1; i <= size; i++)pre[i] += pre[i - 1];
		for (int i = 1; i <= size; i++)cout << v[i] + pre[i] << ' ';
	}
}