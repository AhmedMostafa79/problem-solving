#include <bits/stdc++.h>
using namespace std;
int nx[] = { -1,-1,-1,0,0,1,1,1 };
int ny[] = { -1,0,1,-1,1,-1,0,1 };
int ar[6][6]{};
int getsum(int i,int l) {
    int sum = 0;
    for (int j = 0; j < sizeof(nx)/4; j++) {
        if (!(!nx[j] and ny[j]))
            sum += ar[i + nx[j]][l + ny[j]];
    }
    return sum;
}
int main()
{
    int T = 1;
    //cin >> T;
    while (T--) {
        for (int i = 0; i < 6; i++) {
            for (int j = 0; j < 6; j++) {
                cin >> ar[i][j];
            }
        }
        int  sum = INT_MIN;
        for (int i = 1; i < 5; i++) {
            for (int j = 1; j < 5; j++) {
                sum = max(sum, getsum(i, j)+ar[i][j]);
            }
        }
        cout << sum << '\n';
    }
}
