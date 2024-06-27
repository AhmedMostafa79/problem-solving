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
vector<string>res;
bool t;
void f(deque<string >& v) {
	if (v.size()) {
		string s = v.front();
		res.push_back(s);
		v.pop_front();
		if (s == "pair") {
			res.push_back("<");
			f(v);
			res.push_back(",");
			f(v);
			res.push_back(">");
		}

	}
	else t = 1;
}
int main()
{
	Fast;
	int T = 1;
	//cin >> T;
	while (T--) {
		int size;
		cin >> size;
		string s;
		getline(cin, s);
		getline(cin, s);
		deque<string>v;
		for (int i = 0; i < s.size(); i++) {
			int r = s.find(' ', i);
			v.push_back(s.substr(i, r - i));
			if (r < 0)
				break;
			i = r;
		}
		f(v);
		for (int i = 0; i < res.size(); i++) {
			if (i + 1 < res.size() and res[i] == res[i + 1] and res[i] == "int")
				t = 1;
		}
		if (t or v.size())
			cout << "Error occurred\n";
		else
			for (auto i : res)
				cout << i;
	}
}