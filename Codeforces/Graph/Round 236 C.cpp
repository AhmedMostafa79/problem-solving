#include <bits/stdc++.h>
using namespace std;
#define  ll long long 
#define  range(v) ((v).begin()),((v).end())
#define Fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define close(n) return cout<<n,0;
int nx[] = { -1,-1,-1,0,0,1,1,1 };
int ny[] = { -1,0,1,-1,1,-1,0,1 };
int countbit(ll n) { return (n > 1 ? (n & 1) + countbit(n >> 1) : n); }
ll gcd(ll x, ll y) { if (!y)return x; return gcd(y, x % y); }
ll lcm(ll x, ll y) { return x * y / gcd(x, y); }
vector<vector<int>>v;
int main()
{
	Fast;
	int T = 1;
	cin >> T;
	while (T--) {
		int size, p;
		cin >> size >> p;
		int rem = size + p;
		v = vector<vector<int>>(size + 1, vector<int>());
		for (int i = 1; i <= size; i++) {
			v[i].push_back(i + 1 > size ? (i + 1) % size : i + 1);
		}
		while (rem) {
			for (int i = 1; i <= size and rem; i++, rem--) {
				v[i].push_back(v[i].back() + 1 > size ? (v[i].back() + 1) % size : v[i].back() + 1);
			}
		}
		for (int i = 1; i <= size; i++) {
			for (auto j : v[i])cout << i << " " << j << "\n";
		}
	}
}