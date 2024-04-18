#include <bits/stdc++.h>
using namespace std;
#define  ll long long 
#define  range(v) ((v).begin()),((v).end())
#define Fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define close(n) return cout<<n,0;
int nx[] = { -1,-1,-1,0,0,1,1,1 };
int ny[] = { -1,0,1,-1,1,-1,0,1 };
int countbit(ll n) { return (n > 1 ? (n & 1) + countbit(n >> 1) : n); }
struct f {
	int son, odd, even, ind;
};
vector<vector<int>>v;
vector<f>val;
vector<int>res;
void dfs(int i, int x) {
	for (auto& j : v[i]) {
		val[j].odd += val[i].odd + (x);
		val[j].even += val[i].even + (!x);
	}
}
int main()
{
	Fast;
	int T = 1;
	//cin >> T;
	while (T--) {
		int size, c;
		cin >> size;
		vector<int>vv;
		v = vector<vector<int>>(size + 1, vector<int>());
		val = vector<f>(size + 1);
		vector<bool>init(size + 1), last(size + 1);
		val[1].ind = 1;
		vv.push_back(1);
		for (int x, y, i = 2; i <= size; i++) {
			cin >> x >> y;
			if (val[y].ind) {
				val[x].ind = val[y].ind + 1;
				v[y].push_back(x);
				vv.push_back(x);
			}
			else {
				val[y].ind = val[x].ind + 1;
				v[x].push_back(y);
				vv.push_back(y);
			}
		}
		for (int x, i = 1; i <= size; i++) {
			cin >> x;
			init[i] = x;
		}
		for (int x, i = 1; i <= size; i++) {
			cin >> x;
			last[i] = x;
		}
		for (int x, r = 0; r < vv.size(); r++) {
			x = last[vv[r]];
			int i = vv[r];
			int parity = ((val[i].ind & 1) ? val[i].odd : val[i].even);
			if (((parity & 1) ^ init[i]) != x) {
				res.push_back(i);
				dfs(i, (val[i].ind & 1));
			}
			else for (auto& j : v[i])val[j].even += val[i].even, val[j].odd += val[i].odd;
		}
		cout << res.size() << '\n';
		for (auto i : res)cout << i << ' ';
	}
}