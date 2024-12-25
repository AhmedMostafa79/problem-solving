#include <bits/stdc++.h>
using namespace std;
#define  ll long long 
vector<vector<int>>v;
int main()
{
    int T = 1;
    //cin >> T;
    while (T--) {
        int size, q;
        cin >> size >> q;
        v = vector<vector<int>>(size+1, vector<int>());
        ll res = 0;
        while (q--) {
            int t, x, y;
            cin >> t >> x >> y;
            int id = (x ^ res) % size;
            if (t == 1) {
                v[id].push_back(y);
            }
            else {
                res=v[id][y % v[id].size()];
                cout << res << "\n";
            }
        }

    }
}
