﻿#include<bits/stdc++.h>
using namespace std;
#define  ll long long
#define  all(v) ((v).begin()),((v).end())
#define  rall(v) ((v).rbegin()),((v).rend())
#define Fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define close(n) return cout<<n,0;
#define files  freopen("closing.in", "r", stdin); freopen("closing.out", "w", stdout);
const int dx[] = { -1,0,1,0,1,-1,1,-1 };
const int dy[] = { 0,-1,0,1,1,-1,-1,1 };
const int di[] = { 'U','R','D','L' };
int countbit(ll n) { return (n > 1 ? (n & 1) + countbit(n >> 1) : n); }
ll gcd(ll x, ll y) { if (!y)return x; return gcd(y, x % y); }
ll lcm(ll x, ll y) { return x * y / gcd(x, y); }
const ll N = 2e5 + 5, mod = 1e9 + 7, LOG = 30;
vector<int>par;
int ar[N][LOG], n;
void build() {
    for (int i = 1; i <= n; i++) {
        ar[i][0] = par[i];
    }
    for (int j = 1; j < LOG; j++) {
        for (int i = 2; i <= n; i++) {
            ar[i][j] = ar[ar[i][j - 1]][j - 1];
        }
    }
}
int get(int x, int k) {
    for (int i = LOG - 1; i >= 0; i--) {
        if ((k >> i) & 1) {
            x = ar[x][i];
        }
    }
    return x;
}
void solve() {
    Fast;
    int q;
    cin >> n >> q;
    par = vector<int>(n + 1);
    for (int i = 2; i <= n; i++)
        cin >> par[i];
    build();
    while (q--) {
        int x, k;
        cin >> x >> k;
        int res = get(x, k);
        cout << (res == 0 ? -1 : res) << '\n';
    }
}

int main() {
    Fast;
    int t = 1;
    //cin >> t;
    while (t--) {
        solve();
    }
}