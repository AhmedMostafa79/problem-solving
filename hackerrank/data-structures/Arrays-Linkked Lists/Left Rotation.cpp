#include <bits/stdc++.h>
using namespace std;
vector<vector<int>>v;
int main()
{
    int T = 1;
    //cin >> T;
    while (T--) {
        int size, k;
        cin >> size >> k;
        vector<int>v(size), res(size);
        for (auto& i : v)
            cin >> i;
        for (int i = 0; i < size; i++) {
            int x = i - k;
            if (x >= 0)res[x] = v[i];
            else res[size +x] = v[i];
        }
        for (auto i : res)cout << i << " ";
    }
}
