#include<bits/stdc++.h>
using namespace std;
#define  ll long long 
#define  range(v) ((v).begin()),((v).end())
#define Fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
int gcd(int a, int b) {
	int a2 = 1;
	while (b) {
		a2 = b;
		b = (a % b);
		a = a2;
	}
	return a2;
}
int main() {
	Fast;
	ll ar[3];
	cin >> ar[0] >> ar[1] >> ar[2];
	sort(ar, ar + 3);
	ll res = 0;//1000000000000000000 0 1000000000000000000
	if (ar[2] == ar[1] && ar[2] != ar[0])res = ar[2] - 1 - ar[0];
	else if (ar[2] - ar[1] >= 2)res = (ar[2] - 1) * 2 - (ar[1] + ar[0]);
	else if (ar[2] - ar[0] >= 2)res = (ar[1]) - (ar[0]);

	//else if()
	cout << res;
}