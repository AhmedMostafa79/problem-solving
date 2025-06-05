#include<bits/stdc++.h>
#include <unordered_set>
using namespace std;
#define  ll long long
#define  all(v) ((v).begin()),((v).end())
#define  rall(v) ((v).rbegin()),((v).rend())
#define Fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define files  freopen("closing.in", "r", stdin); freopen("closing.out", "w", stdout);

int countbit(ll n) { return (n > 1 ? (n & 1) + countbit(n >> 1) : n); }
ll gcd(ll x, ll y) { if (!y)return x; return gcd(y, x % y); }
ll lcm(ll x, ll y) { return x * y / gcd(x, y); }
const int dx[] = { 0, 1,-1,0,0,1,1,-1,-1 };
const int dy[] = { 0, 0,0,1,-1,1,-1,1,-1 };
const int N = 5, mod = 1e9 + 7, base = 31;
//to make new matrix of size (n-1)*(n-1)
void cancel_row_col(double M[N][N], double ar[N][N], int r, int c, int n) {
    int i = 0, j = 0;
    for (int a = 0; a < n; a++) {
        for (int b = 0; b < n; b++) {
            if (a == r or b == c)
                continue;
            ar[i][j] = M[a][b];
            j++;
            if (j == n - 1) {
                j = 0;
                i++;
            }
        }
    }
}
double Determinant(double M[N][N], int n) {
    if (n == 1)
        return M[0][0];
    double D = 0;
    int sign = 1;
    double  ar[N][N]{};
    for (int i = 0; i < n; i++) {
        cancel_row_col(M, ar, 0, i, n);//alway cancel row 0
        D += sign * M[0][i] * Determinant(ar, n - 1);
        sign = -sign;//flip it 
    }
    return D;
}
void solve() {
    double ar[6]{};
    for (int i = 0; i < 6; i++) {
        cin >> ar[i];
        ar[i] *= ar[i];
    }
    //vector<double>M[N];
   /* M[0] = { 0,1,1,1,1 };
    M[1] = { 1,0,ar[0],ar[1],ar[2] };
    M[2] = { 1,ar[0],0,ar[3],ar[4] };
    M[3] = { 1,ar[1],ar[3],0,ar[5] };
    M[4] = { 1,ar[2],ar[4],ar[5],0 };*/
    double M[N][N]{};
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (i != j)
                M[i][j] = 1;
        }
    }
    M[1][2] = M[2][1] = ar[0];
    M[1][3] = M[3][1] = ar[1];
    M[1][4] = M[4][1] = ar[2];
    M[2][3] = M[3][2] = ar[3];
    M[2][4] = M[4][2] = ar[4];
    M[3][4] = M[4][3] = ar[5];

    double D = fabs(Determinant(M, N));
    double res = sqrt(D / 288.0);
    cout << fixed << setprecision(4);
    cout << res << '\n';
}
int main() {
    Fast;
    int t = 1;
    cin >> t;
    for (int i = 1; i <= t; i++) {
        //cout << "Case #" << i << " : ";
        solve();
        //if (i < t)
            //cout << '\n';
    }
    return 0;
}