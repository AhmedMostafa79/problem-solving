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
const ll N = 1e3 + 5, MOD = 1e9 + 7;

string s;
void solve() {
    int n, ar[26];
    cin >> n >> s;
    for (int i = 0; i < 26; i++)
        cin >> ar[i];
    int* dp = new int[n + 1] {};
    int* min_len = new int [n + 1] {};
    dp[n] = 1;
    //memset(min_len, 1, sizeof min_len);
    int max_sub = 1;
    for (int i = n - 1; i >= 0; i--) {
        min_len[i] = 1e3;
        bool go = 1, is_in[26]{};
        int j;
        for (j = i; j < n and go; j++) {
            is_in[s[j] - 'a'] = 1;
            for (int k = 0; k < 26; k++) {
                if (is_in[k])
                    go &= (ar[k] >= (j - i + 1));
            }
            if (go) {
                dp[i] = (dp[i] % MOD + (dp[j + 1] % MOD)) % MOD;
            }
        }
        j -= !go;
        min_len[i] = min(min_len[i], min_len[j] + 1);
        max_sub = max(max_sub, j - i);
    }
    cout << dp[0] << ' ' << max_sub << " " << min_len[0] << '\n';
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