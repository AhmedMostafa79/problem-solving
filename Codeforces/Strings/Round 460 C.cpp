#include <bits/stdc++.h>
using namespace std;
#define  ll long long 
#define  range(v) ((v).begin()),((v).end())
#define Fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define close(n) return cout<<n,0;
int nx[] = { -1,-1,-1,0,0,1,1,1 };
int ny[] = { -1,0,1,-1,1,-1,0,1 };
int main()
{
	Fast;
	int T = 1;
	//cin >> T;
	while (T--) {
		int n, m, k;
		cin >> n >> m >> k;
		vector<string>v(n);
		for (int i = 0; i < n; i++)cin >> v[i];
		ll res = 0;
		for (int j = 0; j < m; j++) {
			int i = 0, c = 0;
			while (i < n) {
				if (v[i][j] == '.')c++;
				else res += (c >= k ? c - k + 1 : 0), c = 0;
				i++;
			}
			res += (c >= k ? c - k + 1 : 0);
		}
		for (int i = 0; i < n; i++) {
			int j = 0, c = 0;
			while (j < m) {
				if (v[i][j] == '.')c++;
				else res += (c >= k ? c - k + 1 : 0), c = 0;
				j++;
			}
			res += (c >= k ? c - k + 1 : 0);
		}
		cout << (k == 1 ? res / 2 : res) << '\n';
	}
}