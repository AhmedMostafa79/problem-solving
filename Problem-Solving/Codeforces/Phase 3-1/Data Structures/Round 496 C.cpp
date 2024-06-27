#include<bits/stdc++.h>
using namespace std;
#define  ll long long 
#define  range(v) ((v).begin()),((v).end())
#define Fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define frac(n) fixed<<setprecision(n)
int main() {
    Fast;
    ll ar[33]{}, size, ar2[32]{};
    for (int i = 0; i < 32; i++) {
        ar[i] = pow(2, i);
    }
    cin >> size;
    vector<int>v(size);
    for (int i = 0; i < size; i++) {
        cin >> v[i];
        if (log2(v[i]) == (int)log2(v[i]))ar2[(int)log2(v[i])]++;
    }
    int c = 0;
    sort(range(v));
    cout << '\n';
    for (int i = 0; i < size; i++) {
        int l = 0;
        if (log2(v[i]) == (int)log2(v[i]) && ar2[(int)log2(v[i])] >= 2)l = 1;
        else {
            for (int j = 0; j < 33 && !l; j++) {
                if (ar[j] < v[i])continue;
                auto it = lower_bound(range(v), ar[j] - v[i]);
                if (it - v.begin() != i && it != v.end() && ar[j] >= v[i] && v[it - v.begin()] + v[i] == ar[j])
                    l = 1;
            }
        }
        if (!l)
            c++;
    }
    cout << c;
}