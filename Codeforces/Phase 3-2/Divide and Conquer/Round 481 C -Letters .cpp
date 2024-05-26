#include<bits/stdc++.h>
using namespace std;
#define  ll long long 
#define  range(v) ((v).begin()),((v).end())
#define Fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define frac(n) fixed<<setprecision(n)
//random_shuffle(range(v))

int main() {
    Fast;
    int n, m;
    cin >> n >> m;
    vector<ll>rooms(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> rooms[i];
        rooms[i] += rooms[i - 1];
    }
    for (int i = 0; i < m; i++) {
        ll x;
        cin >> x;
        int j = lower_bound(range(rooms), x) - rooms.begin();
        cout << j << ' ' << (x - rooms[j - 1]) << '\n';
    }

}
