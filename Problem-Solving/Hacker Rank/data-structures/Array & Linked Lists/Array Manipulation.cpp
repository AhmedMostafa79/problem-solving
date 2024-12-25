#include <bits/stdc++.h>
using namespace std;
#define  ll long long 
#define  range(v) ((v).begin()),((v).end())
int main()
{
    int T = 1;
    //cin >> T;
    while (T--) {
        int size, m;
        cin >> size >> m;
        vector<ll>v(size + 2);
        while (m--) {
            int a, b, k;
            cin >> a >> b >> k;
            v[a] += k, v[b + 1] -= k;
        }
        for (int i = 1; i <= size; i++)v[i] += v[i - 1];
        cout << *max_element(range(v));
    }
}
