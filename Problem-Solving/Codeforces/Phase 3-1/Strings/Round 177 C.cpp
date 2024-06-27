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
int main()
{
	Fast;
	int T = 1;
	//cin >> T;
	while (T--) {
		int size, k;
		cin >> size >> k;
		if (size == 1 and k == 1)close('a');
		if ((size < k or k == 1)) { close(-1); }
		for (int i = 0; i < size - k + 2; i++)cout << (i & 1 ? 'b' : 'a');
		for (int i = 2; i < k; i++)cout << char(i + 'a');
	}
}