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
map<string, int>m;
string  ins(string s) {
	string x;
	for (int i = s.size() - 1; i >= 0; i--) {
		x = char((s[i] & 1) + '0') + x;
	}
	return x;
}
int main()
{
	Fast;
	int T = 1;
	//cin >> T;
	while (T--) {
		int size;
		cin >> size;
		char c;
		for (int i = 0; i < size; i++) {
			string x;
			cin >> c >> x;
			x = string(18 - x.size(), '0') + x;
			if (c == '?') {
				cout << m[x] << '\n';
			}
			else m[ins(x)] += (c == '+' ? 1 : -1);
		}
	}
}