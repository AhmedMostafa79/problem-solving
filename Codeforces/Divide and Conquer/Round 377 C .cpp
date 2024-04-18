#include<bits/stdc++.h>
using namespace std;
#define  ll long long 
#define  range(v) ((v).begin()),((v).end())
#define Fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)

int main() {
	Fast;
	ll ar[3];
	cin >> ar[0] >> ar[1] >> ar[2];
	sort(ar, ar + 3);
	ll res = 0;
	if (ar[2] == ar[1] && ar[2] != ar[0])res = ar[2] - 1 - ar[0];
	else if (ar[2] - ar[1] >= 2)res = (ar[2] - 1) * 2 - (ar[1] + ar[0]);
	else if (ar[2] - ar[0] >= 2)res = (ar[1]) - (ar[0]);

	//else if()
	cout << res;
}