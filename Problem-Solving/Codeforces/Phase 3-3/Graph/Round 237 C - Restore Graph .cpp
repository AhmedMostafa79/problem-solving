#include <bits/stdc++.h>
using namespace std;
#define  ll long long 
#define  all(v) ((v).begin()),((v).end())
#define  rall(v) ((v).rbegin()),((v).rend())
#define Fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define close(n) return cout<<n,0;
#define f first
#define s second
const int dx[] = { -1,0,1,0,1,-1,1,-1 };
const int dy[] = { 0,1,0,-1,1,-1,-1,1 };
const int di[] = { 'U','R','D','L' };
int countbit(ll n) { return (n > 1 ? (n & 1) + countbit(n >> 1) : n); }
ll gcd(ll x, ll y) { if (!y)return x; return gcd(y, x % y); }
ll lcm(ll x, ll y) { return x * y / gcd(x, y); }
const int N = 1e5 + 5, mod = 1e9 + 9;

void solve() {
	int n, k;
	cin >> n >> k;
	vector<int>a(n + 1);
	vector<vector<int>>v(n + 2, vector<int>());
	bool valid = 1;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		v[a[i]].push_back(i);//push in each level its vertices
	}
	vector<pair<int, int>>res;
	for (int i = 0; i <= n; i++) {//loop for vertices
		int j1 = 0;
		for (int j2 = 0; j2 < v[i].size(); j2++) {//loop in parents in level i
			for (int kk = k; kk > (i > 0) and j1 < v[i + 1].size(); kk--) {
				res.push_back({ v[i][j2],v[i + 1][j1] });//set children in this level k-1 if i>0 ,k if i=0
				j1++;
			}
		}
		if (j1 < v[i + 1].size())
			return void(cout << -1);//parents less than children
	}
	if (v[0].size() != 1)
		return void(cout << -1);
	cout << res.size() << '\n';
	for (auto i : res)
		cout << i.first << " " << i.second << '\n';
}
int main()
{
	Fast;
	int T = 1;
	//cin >> T;
	//seive(1e5);

	while (T--) {
		solve();
	}
}