#include<bits/stdc++.h>
using namespace std;
long long int n, q, i, k, s, c, a[222000];
int main() {
	for (cin >> n >> q; i < n; i++)cin >> k, a[i] = k + a[i - 1] * !!i;
	for (; q--;) {
		cin >> k; s += k;
		auto j = upper_bound(a, a + n, s) - a;
		j == n ? c = s = 0 : c = j;
		cout << n - c << '\n';
	}
}
