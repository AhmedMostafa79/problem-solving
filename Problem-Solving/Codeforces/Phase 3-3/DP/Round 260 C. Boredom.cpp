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
const int dx[] = { 1,-1,0,0 };
const int dy[] = { 0,0,1,-1 };
const int N = 1e5 + 5, mod = 1e9 + 7, base = 31;

void solve() {
    int n;
    cin >> n;
    vector<ll>v(N);
    for (int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        v[x] += x;
    }
    for (int i = 1; i < N; i++) {
        if (i > 2)
            v[i] += max(v[i - 3], v[i - 2]);
        else if (i > 1)
            v[i] += v[i - 2];
    }

    cout << *max_element(all(v));
}
int main() {
    Fast;
    int t = 1;
    //cin >> t;
    for (int i = 1; i <= t; i++) {
        solve();
        //if (i < t)
            //cout << '\n';
    }
    return 0;
}
