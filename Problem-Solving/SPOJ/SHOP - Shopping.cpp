#include<bits/stdc++.h>
using namespace std;
#define  ll long long
#define  all(v) ((v).begin()),((v).end())
#define  rall(v) ((v).rbegin()),((v).rend())
#define Fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define files  freopen("closing.in", "r", stdin); freopen("closing.out", "w", stdout);
const int dx[] = { 1,0,-1,0 };
const int dy[] = { 0,1,0,-1 };

const int N = 25 + 5, mod = 1e9 + 7;

vector<int>v[N];
string ar[N];
ll dist[N][N];
int n, m;
bool valid(int i, int j) {
    return 0 <= i and 0 <= j and i < n and j < m and ar[i][j] != 'X';
}
void D(int sx, int sy) {
    priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<>>q;
    dist[sx][sy] = 0;
    q.push({ 0,sx,sy });
    while (q.size()) {
        int i, j, d;
        tie(d, i, j) = q.top();
        q.pop();
        for (int r = 0; r < 4; r++) {
            int  nx = dx[r] + i;
            int ny = dy[r] + j;
            if (!valid(nx, ny))
                continue;
            int new_d = (ar[nx][ny] != 'D' ? ar[nx][ny] - '0' : 0);
            if (d + new_d < dist[nx][ny]) {
                dist[nx][ny] = d + new_d;
                q.push({ dist[nx][ny],nx,ny });
            }
        }
    }
}
void solve() {
    int sx, sy, ex, ey;
    for (int i = 0; i < n; i++) {
        cin >> ar[i];
        for (int j = 0; j < m; j++) {
            if (ar[i][j] == 'S')
                sx = i, sy = j;
            if (ar[i][j] == 'D')
                ex = i, ey = j;
            dist[i][j] = 1e9;
        }
    }
    D(sx, sy);
    cout << dist[ex][ey] << '\n';
}
int main() {
    Fast;
    int t = 1;
    //cin >> t;
    while (cin >> m >> n and n and m) {
        //cout << "Case #" << i << ": ";
        solve();
    }
}