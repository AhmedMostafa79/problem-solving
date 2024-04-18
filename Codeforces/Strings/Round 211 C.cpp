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
		string s, res;
		cin >> s;
		int size = s.size();
		for (int i = 0; i < size; i++) {
			if (res.size() > 2 and res.back() == s[i] and res[res.size() - 2] == res[res.size() - 3])
				continue;
			else if (res.size() >= 2 and res.back() == res[res.size() - 2] and res.back() == s[i])
				continue;
			res += s[i];
		}
		cout << res << '\n';
	}
}