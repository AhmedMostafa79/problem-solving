#include <bits/stdc++.h>
using namespace std;
#define  ll long long 
#define  all(v) ((v).begin()),((v).end())
#define  rall(v) ((v).rbegin()),((v).rend())
#define Fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define close(n) return cout<<n,0;
const int dy[] = { -1,0,1,0,1,-1,1,-1 };
const int dx[] = { 0,1,0,-1,1,-1,-1,1 };
const int di[] = { 'U','R','D','L' };
int countbit(ll n) { return (n > 1 ? (n & 1) + countbit(n >> 1) : n); }
ll gcd(ll x, ll y) { if (!y)return x; return gcd(y, x % y); }
ll lcm(ll x, ll y) { return x * y / gcd(x, y); }
const int N = 5e4 + 3, mod = 1e9 + 7;

void solve() {
    string s;
    cin >> s;
    cout << s[0];
    bool a = 0, b = 0;
    for (int i = 1; i < s.size(); i++) {
        if (i + 2 < s.size() - 1 and s[i] == 'd' and s[i + 1] == 'o' and s[i + 2] == 't') {
            cout << '.';
            i += 2;
        }
        else if (!b and i + 1 < s.size() - 1 and s[i] == 'a' and s[i + 1] == 't') {
            cout << "@";
            i++;
            b = 1;
        }
        else cout << s[i];
    }
}
int main()
{
    Fast;
    int T = 1;
    //cin >> T;
    for (int i = 1; T--; i++) {
        solve();
    }
    return 0;
}