#include<bits/stdc++.h>
using namespace std;
string s;
int n, m, x, y, a[1000005], t;
int main() {
	cin >> s;
	for (int i = 0; i < s.size(); i++) {
		if (s[i] == '(') x++;
		else if (s[i] == ')') x--;
		else a[++t]++, x--, y = i;
		if (x < 0) cout << -1, exit(0);
	}
	int m1 = 0;
	for (int i = s.size() - 1; i > y; i--) {
		if (s[i] == '(') m1--;
		else m1++;
		if (m1 < 0) cout << -1, exit(0);
	}
	a[t] += x;
	for (int i = 1; i <= t; i++) cout << a[i] << endl;
}

