#include<bits/stdc++.h>
using namespace std;
int64_t p, q, i, k, s, c, a[222000];
int main() {
    for (cin >> p >> q; i < p; i++)
        cin >> k, a[i] = k + a[i - 1] * !!i;
    for (; q--;) {
        cin >> k;
        s += k;
        auto j = upper_bound(a, a + p, s) - a;
        j == p ? c = s = 0 : c = j;
        cout << p - c << '\n';
    }
}
