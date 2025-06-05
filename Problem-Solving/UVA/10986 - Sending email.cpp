#include<bits/stdc++.h>
using namespace std;
#define  ll long long
#define  all(v) ((v).begin()),((v).end())
#define  rall(v) ((v).rbegin()),((v).rend())
#define Fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define files  freopen("closing.in", "r", stdin); freopen("closing.out", "w", stdout);
const int N = 2e4 + 5, mod = 1e9 + 7;
vector<pair<ll, int>>v[N];

ll dist[N];
void D(int s) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>q;
    dist[s] = 0;
    q.push({ 0,s });
    while (q.size()) {
        int d = q.top().first;
        int x = q.top().second;
        q.pop();
        if (dist[x] < d)
            continue;
        for (auto& j : v[x]) {
            if (j.second + d < dist[j.first])
            {
                dist[j.first] = d + j.second;
                q.push({ dist[j.first],j.first });
            }
        }
    }
}
void solve() {
    int n, m, s, e;
    cin >> n >> m >> s >> e;
    for (int i = 0; i < n; i++)
        dist[i] = 2e9, v[i].clear();
    for (int i = 1; i <= m; i++) {
        int x, y, w;
        cin >> x >> y >> w;
        v[x].push_back({ y,w });
        v[y].push_back({ x,w });
    }
    D(s);
    if (dist[e] == 2e9)
        cout << "unreachable\n";
    else
        cout << dist[e] << '\n';
}
int main() {
    Fast;
    int t = 1;
    cin >> t;
    for (int i = 1; i <= t; i++) {
        cout << "Case #" << i << ": ";
        solve();
    }
}