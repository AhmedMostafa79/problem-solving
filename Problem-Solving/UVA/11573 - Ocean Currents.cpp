#include <bits/stdc++.h>
using namespace std;
#define  ll long long 
#define  all(v) ((v).begin()),((v).end())
#define  rall(v) ((v).rbegin()),((v).rend())
#define Fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define close(n) return cout<<n,0;
const int dy[] = { -1,0,1,0,1,-1,1,-1 };
const int dx[] = { 0,1,0,-1,1,-1,-1,1 };
const int di[] = { 'U','R','D','L' };
int countbit(ll n) { return (n > 1 ? (n & 1) + countbit(n >> 1) : n); }
ll gcd(ll x, ll y) { if (!y)return x; return gcd(y, x % y); }
ll lcm(ll x, ll y) { return x * y / gcd(x, y); }
const int N = 4e4 + 3, mod = 1e9 + 7;
int r, c;
vector<string>flow(1e3 + 3);
struct f {
    int w;
    int i, j;
};
bool valid(int x, int y) {
    return x >= 0 and y >= 0 and x < r and y < c;
}
int bfs0_1(int sr, int sc, int er, int ec) {
    int dx[] = { -1,-1,0,1,1,1,0,-1 };//clockwise
    int dy[] = { 0,1,1,1,0,-1,-1,-1 };
    vector<vector<int>>dist(r, vector<int>(c, 1e9));
    deque<f>d;
    dist[sr][sc] = 0;
    //priority_queue<f, vector<f>, greater<>>d;
    d.push_back({ 0,sr,sc });
    while (d.size()) {
        int w = d.front().w;
        int i = d.front().i, j = d.front().j;
        d.pop_front();
        if (w != dist[i][j])
            continue;
        for (int r = 0; r < 8; r++) {
            int ii = dx[r] + i, jj = dy[r] + j;
            if (!valid(ii, jj))
                continue;
            int ww = r != (flow[i][j] - '0');//if r==flow weight=0 else weight=1
            if (dist[ii][jj] > w + ww) {
                dist[ii][jj] = w + ww;
                if (ww)
                    d.push_back({ w + ww,ii,jj });// if(ww==1 )push back
                else d.push_front({ w + ww,ii,jj });//else push front
            }
        }
    }
    return dist[er][ec];
}
void solve() {
    // main idea 0/1 bfs 
    cin >> r >> c;
    for (int i = 0; i < r; i++)
        cin >> flow[i];
    int q;
    cin >> q;
    while (q--) {
        int sr, sc, er, ec;
        cin >> sr >> sc >> er >> ec;
        cout << bfs0_1(sr - 1, sc - 1, er - 1, ec - 1) << '\n';
    }
}
int main()
{
    Fast;
    int T = 1;
    //cin >> T;
    for (int i = 1; T--; i++) {
        //cout << "Case " << i << ":\n";
        solve();
    }
    return 0;
}