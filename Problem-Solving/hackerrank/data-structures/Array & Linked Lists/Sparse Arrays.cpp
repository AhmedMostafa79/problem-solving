#include <bits/stdc++.h>
using namespace std;
int main()
{
    int T = 1;
    //cin >> T;
    while (T--) {
        int size;
        cin >> size;
        map<string, int>m;
        string s;
        for (int i = 0; i < size; i++)cin >> s, m[s]++;
        int q;
        cin >> q;
        while (q--) {
            cin >> s;
            cout << m[s] << '\n';
        }
    }
}
