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
const ll N = 2e5 + 5, MOD = 1e9 + 7;

void solve() {
    int  k[3]{};
    cin >> k[0] >> k[1] >> k[2];
    int n = k[0] + k[1] + k[2];
    vector<int>ar(n + 1);
    for (int i = 1; i <= 3; i++) {
        for (int j = 0; j < k[i - 1]; j++) {
            int x;
            cin >> x;
            ar[x] = i;
        }
    }
    vector<vector<int>>dp(n + 1, vector<int>(3));

    dp[n][0] = ar[n] != 1;
    dp[n][1] = ar[n] != 2;
    dp[n][2] = ar[n] != 3;
    for (int i = n - 1; i >= 1; i--) {
        dp[i][0] = min({ dp[i + 1][0], dp[i + 1][1],dp[i + 1][2] }) + (ar[i] != 1);
        dp[i][1] = min(dp[i + 1][1], dp[i + 1][2]) + (ar[i] != 2);
        dp[i][2] = dp[i + 1][2] + (ar[i] != 3);
    }
    /* for (int i = 1; i <= n; i++)
     {
         for (int j = 0; j < 3; j++) {
             cout << dp[i][j] << " ";
         }
         cout << '\n';
     }*/
    cout << min({ dp[1][0],dp[1][1],dp[1][2] });
}
int main() {
    Fast;
    int t = 1;
    //cin >> t;
    for (int i = 1; i <= t; i++) {
        //cout << "Case " << i << ": ";
        solve();
        cout << "\n";

    }
}