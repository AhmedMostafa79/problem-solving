#include<bits/stdc++.h>
#include <unordered_set>
using namespace std;
#define  ll long long
#define  all(v) ((v).begin()),((v).end())
#define  rall(v) ((v).rbegin()),((v).rend())
#define Fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define files  freopen("closing.in", "r", stdin); freopen("closing.out", "w", stdout);

int countbit(ll n) { return (n > 1 ? (n & 1) + countbit(n >> 1) : n); }
ll gcd(ll x, ll y) { if (!y)return x; return gcd(y, x % y); }
ll lcm(ll x, ll y) { return x * y / gcd(x, y); }
const int dx[] = { 0, 1,-1,0,0,1,1,-1,-1 };
const int dy[] = { 0, 0,0,1,-1,1,-1,1,-1 };
const int N = 2e5 + 5, mod = 1e9 + 7, base = 31;
//main idea..
//first player who has muliple options wins
ll  f(ll a, ll b) {
    if (!b)
        return 0;
    if (a / b > 1)
        return 1;
    return f(b, a - b) + 1;
}
ll a, b;
void solve() {
    if (a < b)
        swap(a, b);
    cout << (f(a, b) % 2 ? "Stan wins" : "Ollie wins") << '\n';
}
int main() {
    Fast;
    int t = 1;
    //cin >> t;
    for (int i = 1; cin >> a >> b and (a and b); i++) {
        solve();
        //if (i < t)
            //cout << '\n';
    }
    return 0;
}