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
const int N = 2e5 + 5, mod = 1e9 + 9;
struct bTrie {
	struct Node {
		Node* ch[2];
		int frq[2];
		Node() {

			ch[0] = ch[1] = 0;
			frq[0] = frq[1] = 0;
		}
	};
	Node* root = new Node();
	bTrie() {
		insert(0);
	}
	void insert(int n) {
		Node* cur = root;
		for (int i = 29; i >= 0; i--) {
			int idx = (n >> i) & 1;//check bit
			if (cur->ch[idx] == 0)
				cur->ch[idx] = new Node();
			cur->frq[idx]++;//frequency of ith bit ++
			cur = cur->ch[idx];
		}
	}
	void del(int n, int i, Node* cur) {
		if (i == -1)
			return;
		int idx = (n >> i) & 1;
		del(n, i - 1, cur->ch[idx]);
		cur->frq[idx]--;
		if (cur->frq[idx] == 0) {
			delete cur->ch[idx];
			cur->ch[idx] = 0;
		}
	}
	int maxXor(int n) {
		Node* cur = root;
		int ret = 0;
		for (int i = 29; i >= 0; i--) {
			int idx = (n >> i) & 1;
			if (cur->ch[idx ^ 1] == 0) {//if 1 check 0 ,if 0 check 1
				cur = cur->ch[idx];
			}
			else {
				ret |= (1 << i);//set bit i^1
				cur = cur->ch[1 ^ idx];
			}
		}
		return ret;
	}
};
void solve() {
	int q;
	cin >> q;
	bTrie t;
	while (q--) {
		int x;
		char c;
		cin >> c >> x;
		if (c == '+')
			t.insert(x);
		else if (c == '-')
			t.del(x, 29, t.root);
		else cout << t.maxXor(x) << '\n';
	}
}
int main()
{
	Fast;
	int T = 1;
	//cin >> T;
	while (T--) {
		solve();
	}
}