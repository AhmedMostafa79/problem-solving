#include <bits/stdc++.h>
using namespace std;
#define  ll long long 
#define  all(v) ((v).begin()),((v).end())
#define  rall(v) ((v).rbegin()),((v).rend())
#define Fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define close(n) return cout<<n,0;
const int dx[] = { -1,0,1,0,1,-1,1,-1 };
const int dy[] = { 0,1,0,-1,1,-1,-1,1 };
const int di[] = { 'U','R','D','L' };
int countbit(ll n) { return (n > 1 ? (n & 1) + countbit(n >> 1) : n); }
ll gcd(ll x, ll y) { if (!y)return x; return gcd(y, x % y); }
ll lcm(ll x, ll y) { return x * y / gcd(x, y); }
int main()
{
	Fast;
	int T = 1;
	//cin >> T;
	while (T--) {
		int size, k1, k2;
		cin >> size;
		cin >> k1;
		deque<int>v1, v2;
		for (int x, i = 0; i < k1; i++)
			cin >> x, v1.push_back(x);
		cin >> k2;
		for (int x, i = 0; i < k2; i++)
			cin >> x, v2.push_back(x);
		map<pair<deque<int>, char>, bool>exist;
		deque<int>v;
		char c = '0', win;
		int i, res = 0;
		for (i = 0; i <= 10000 and (v1.size() and v2.size()); i++) {
			if (v1.front() > v2.front())
			{
				v = v1;
				c = '1';
				v1.push_back(v2.front());
				v1.push_back(v1.front());
				v1.pop_front();
				v2.pop_front();
			}
			else if (v1.front() < v2.front()) {
				v = v2;
				c = '2';
				v2.push_back(v1.front());
				v2.push_back(v2.front());
				v1.pop_front();
				v2.pop_front();
			}
			if (v1.empty())
				c = '2';
			else c = '1';
			res++;
			exist[{v, c}] = 1;
			v.clear();
		}
		if (i > 10000)
			close(-1)
			cout << res << ' ' << c << '\n';
	}
}