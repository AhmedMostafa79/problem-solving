#include<bits/stdc++.h>
using namespace std;
#define  ll long long 
#define  range(v) ((v).begin()),((v).end())
#define Fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define frac(n) fixed<<setprecision(n)
int main() {
    Fast;
    int size, k;
    cin >> size >> k;
    vector<ll>v(size + 1);
    for (int i = 1; i <= size; i++) {
        cin >> v[i];
        v[i] += v[i - 1];
    }
    int l = 1, r = k;
    double ma = 0;
    while (l + k - 1 <= size) {
        r = l + k - 1;
        while (r <= size) {
            ma = max(ma, (double)((v[r] - v[l - 1]) * 1.0 / (r - l + 1)));
            r++;
        }
        l++;
    }
    cout << frac(7) << ma;
}

