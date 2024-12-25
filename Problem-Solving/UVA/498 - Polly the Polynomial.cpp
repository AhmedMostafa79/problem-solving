#include<bits/stdc++.h>
/*
    Key Idea..
    Polynomials
*/
using namespace std;
#define  ll long long 
#define  all(v) ((v).begin()),((v).end())
#define  rall(v) ((v).rbegin()),((v).rend())
#define Fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define files  freopen("closing.in", "r", stdin); freopen("closing.out", "w", stdout);
const int N = 2e5 + 5, mod = 1e9 + 7;
int countbit(ll n) { return (n > 1 ? (n & 1) + countbit(n >> 1) : n); }
ll gcd(ll x, ll y) { if (!y)return x; return gcd(y, x % y); }
ll lcm(ll x, ll y) { return x * y / gcd(x, y); }

void solve() {
    string s;
    while (getline(cin, s)) {
        vector<int>c;
        stringstream ss(s);
        int a;
        while (ss >> a) {
            c.push_back(a);
        }
        getline(cin, s);
        vector<int>x;
        stringstream ss2(s);
        while (ss2 >> a) {
            x.push_back(a);
        }
        for (int i = 0; i < x.size(); i++) {
            ll sum = 0;
            for (int j = 0; j < c.size(); j++) {
                sum += c[j] * pow(x[i], c.size() - j - 1);
            }
            cout << sum;
            if (i + 1 < x.size())
                cout << " ";
        }
        cout << '\n';
    }
}
int main() {
    Fast;
    int t = 1;
    //cin >> t;
    for (int i = 1; i <= t; i++) {
        //cout << "Case " << i << ": ";
        solve();
    }
}