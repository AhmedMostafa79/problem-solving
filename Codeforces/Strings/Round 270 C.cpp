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
		int size;
		cin >> size;
		vector<pair<string, string>>v(size);
		for (int i = 0; i < size; i++) {
			cin >> v[i].first >> v[i].second;
		}
		string last = "", s;
		for (int x, i = 0; i < size; i++) {
			cin >> x;
			x--;
			if (last > v[x].first and last > v[x].second)close("NO\n");
			last = (min(v[x].first, v[x].second) >= last ? min(v[x].first, v[x].second) : max(v[x].second, v[x].first));
		}
		cout << "YES\n";
	}
}