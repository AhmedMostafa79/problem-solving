#include <bits/stdc++.h>
using namespace std;
#define  ll long long 
#define  range(v) ((v).begin()),((v).end())
#define Fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define frac(n) fixed<<setprecision(n)
#define close(n) return cout<<n,0;
ll gcd(ll x, ll y) { if (!y)return x; return gcd(y, x % y); }
ll lcm(ll x, ll y) { return x * y / gcd(x, y); }

int main() {
	Fast;
	int T = 1;
	//cin >> T;
	while (T--) {
		int size, x, res = 0, idx = INT_MAX;
		cin >> size >> x;
		vector<int>v(size);
		for (int i = 0; i < size; i++) {
			cin >> v[i];
		}
		if (find(range(v), x) == v.end()) {
			v.emplace_back(x), res++, size++;
		}
		sort(range(v));
		for (int i = 0; i < size; i++) {
			if (v[i] == x and abs((size + 1) / 2 - (i + 1)) < abs((size + 1) / 2 - idx))
				idx = i + 1;
		}
		while (idx != (size + 1) / 2) {
			if (idx > (size + 1) / 2)size++;
			else size--;
			res++;
		}
		cout << res << '\n';
	}
}