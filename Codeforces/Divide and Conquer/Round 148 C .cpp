#include<bits/stdc++.h>
using namespace std;
#define  ll long long 
#define  range(v) ((v).begin()),((v).end())
#define Fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define frac(n) fixed<<setprecision(n)

int main() {
    Fast;
    int size;
    cin >> size;
    vector<ll>v(size);
    for (int i = 0; i < size; i++)cin >> v[i];
    ll sum1 = 0, sum2 = 0, sum3 = 0, sum4 = 0, ma = 0;
    int l = 0, r = size - 1, L = 0, R = size - 1;
    while (l < r) {

        if (sum1 <= sum2)sum1 += v[l], l++;
        else sum2 += v[r], r--;
        if (sum3 < sum4)sum3 += v[L], L++;
        else sum4 += v[R], R--;
        if (sum1 == sum2)ma = max(ma, sum1);
        if (sum3 == sum4)ma = max(ma, sum4);
    }
    if (l == r) {
        if (sum1 <= sum2)sum1 += v[l], l++;
        else sum2 += v[r], r--;
    }
    if (L == R) {
        if (sum3 < sum4)
            sum3 += v[L], L++;
        else sum4 += v[R], R--;
    }if (sum1 == sum2)ma = max(ma, sum1);
    if (sum3 == sum4)ma = max(ma, sum4);
    cout << ma;
}