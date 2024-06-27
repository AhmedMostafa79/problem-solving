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
const int N = 5e4 + 3, mod = 1e9 + 7;
ll n, m;
bool solve(ll n, ll m) {
    vector<pair<ll, ll>> factors;
    ll t = m;
    for (ll i = 2; i * i <= m; i++) {
        ll cnt = 0;
        while (t % i == 0) {
            t /= i;
            cnt++;
        }

        if (cnt) {
            factors.push_back({ i,cnt });
        }
    }
    if (t != 1) {
        factors.push_back({ t,1 });
    }
    ll ii;
    for (auto p : factors) {
        ii = p.first;
        while (p.second > 0) {
            if (ii > n) return 0;
            p.second -= n / ii;
            ii *= p.first;
        }
    }
    return 1;
}
int main()
{
	Fast;
	int T = 1;
	//cin >> T;
	for (int i = 1;cin>>n>>m ; i++) {
        if (m>=0 and solve(max((ll)1, n), m)) {
            cout << m << " divides " << n << "!" << endl;
        }
        else {

            cout << m << " does not divide " << n << "!" << endl;
        }

	}
	return 0;
}