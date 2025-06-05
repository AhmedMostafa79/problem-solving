#include<bits/stdc++.h>
using namespace std;
#define  ll long long
#define  all(v) ((v).begin()),((v).end())
#define  rall(v) ((v).rbegin()),((v).rend())
#define Fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define files  freopen("closing.in", "r", stdin); freopen("closing.out", "w", stdout);
int countbit(ll n) { return (n > 1 ? (n & 1) + countbit(n >> 1) : n); }
ll gcd(ll x, ll y) { if (!y)return x; return gcd(y, x % y); }
ll lcm(ll x, ll y) { return x * y / gcd(x, y); }
const int dx[] = { 1,-1,0,0 };
const int dy[] = { 0,0,1,-1 };
const int N = 1 << 11, mod = 1e9 + 7, base = 31;
struct Node {
    int i, j, mask;
};

queue<Node>q;
vector<string>v;
int dis[N][22][22];
int n, m;
int total = 0;//gets total number of '*'
bool valid(int i, int j) {
    return 0 <= i and 0 <= j and i < n and j < m and
        v[i][j] != 'x';
}

int Bfs(int sx, int sy) {
    q.push({ sx,sy,0 });
    dis[0][sx][sy] = 0;
    while (q.size()) {
        int i = q.front().i;
        int j = q.front().j;
        int last_mask = q.front().mask;
        q.pop();

        for (int r = 0; r < 4; r++) {
            int x = dx[r] + i, y = dy[r] + j;

            if (!valid(x, y))
                continue;
            int mask = last_mask;

            if ('0' <= v[x][y] and v[x][y] <= '9')
                mask |= (1 << (v[x][y] - '0'));

            if (dis[mask][x][y] > dis[last_mask][i][j] + 1) {
                q.push({ x,y,mask });
                dis[mask][x][y] = dis[last_mask][i][j] + 1;
            }
        }
    }
    int res = 1e9;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            int t = (1 << total) - 1;
            if ('0' <= v[i][j] and v[i][j] <= '9')
                res = min(res, dis[t][i][j]);
        }
    }
    return res >= 1e9 ? -1 : res;
}
void solve() {
    swap(n, m);
    v.resize(n);
    while (q.size())
        q.pop();
    total = 0;
    memset(dis, 0, sizeof dis);
    int sx, sy;
    for (int i = 0; i < n; i++) {
        cin >> v[i];
        for (int j = 0; j < m; j++) {
            if (v[i][j] == 'o')
                sx = i, sy = j;
            if (v[i][j] == '*') {
                v[i][j] = '0' + total;
                total++;
            }
            for (int r = 0; r < 1 << 10; r++) {
                dis[r][i][j] = 1e9;
            }
        }
    }
    int res = Bfs(sx, sy);
    cout << res << '\n';
}
int main() {
    Fast;
    int t = 1;
    //cin >> t;
    for (int i = 1; cin >> n >> m and (n or m); i++) {
        solve();
        //if (i < t)
            //cout << '\n';
    }
    return 0;
}
