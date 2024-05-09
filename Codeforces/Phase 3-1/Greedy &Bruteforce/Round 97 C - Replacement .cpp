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
    vector<int>v(size);
    int ma = 0, ind = 0;
    for (int i = 0; i < size; i++) {
        cin >> v[i];
        if (ma < v[i])ma = v[i], ind = i;
    }
    if (ma == 1)v[ind] = 2;
    else v[ind] = 1;
    sort(range(v));
    for (auto i : v)cout << i << " ";
}