#include<bits/stdc++.h>
using namespace std;
#define  ll long long 
#define  range(v) ((v).begin()),((v).end())
#define Fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define frac(n) fixed<<setprecision(n)

int main() {
    Fast;
    int n, m;
    cin >> n >> m;
    char x;
    bool ar[100][100]{};
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++)
            cin >> x, ar[i][j] += (x == '#');
    }


    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            bool all = 1, non = 1;
            for (int k = 0; k < m; k++) {
                if (ar[i][k] != ar[j][k])all = 0;
                if (ar[i][k] && ar[j][k])non = 0;
            }
            if (!non && !all) { cout << "NO\n"; return 0; }
        }
    }
    cout << "YES\n";
}