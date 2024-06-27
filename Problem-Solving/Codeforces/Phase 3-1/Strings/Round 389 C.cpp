#include <bits/stdc++.h>
using namespace std;
#define  ll long long 
#define  range(v) ((v).begin()),((v).end())
#define Fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define frac(n) fixed<<setprecision(n)
#define close(n) return cout<<n,0;
#define break(n) {cout<<n;break}
#define continue(n) {cout<<n<<'\n';continue;}
int main() {
	Fast;
	int t = 1;
	//cin >> t;
	while (t--) {
		char r = 0, u = 0, x;
		int size, res = 1;
		cin >> size;
		for (int i = 0; i < size; i++) {
			cin >> x;
			if (x == 'U' || x == 'D')
				(u == 0 || x == u) ? u = x : (res++, u = x, r = 0);
			if (x == 'R' || x == 'L') (r == 0 || x == r) ? r = x : (res++, r = x, u = 0);
		}
		cout << res;
	}
}