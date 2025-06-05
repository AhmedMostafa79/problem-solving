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
vector<vector<int>>v, ans;
vector<int>v2, res;
bool in[N];
void f(int i) {
    if (res.size() == v2.size()) {
        ans.push_back(res);

        return;
    }
    for (auto j : v2) {
        if (in[j])//in v2
            continue;
        bool valid = 1;
        for (auto j2 : v[j]) {// to push j, all its children must be in 
            valid &= in[j2];
        }
        if (valid) {
            in[j] = 1;
            res.push_back(j);
            f(0);
            in[j] = 0;
            res.pop_back();
        }
    }
}
void solve() {
    string s;


    memset(in, 0, sizeof in);
    v2.clear();
    res.clear();
    ans.clear();
    v = vector<vector<int>>(26, vector<int>());
    while (getline(cin, s) and s.empty());
    char j;
    stringstream ss(s);
    while (ss >> j) {
        v2.push_back(j - 'A');
    }
    string s2;
    while (getline(cin, s) and s.empty());
    stringstream ss2(s);
    sort(all(v2));
    while (ss2 >> s2) {
        v[s2[2] - 'A'].push_back(s2[0] - 'A');
    }
    for (auto& i : v)
        sort(all(i));
    f(0);
    if (!ans.size())
        cout << "NO\n";
    else {
        sort(all(ans));
        for (auto i : ans) {
            for (int j = 0; j < i.size(); j++) {
                cout << (char)(i[j] + 'A');
                if (j + 1 < i.size())
                    cout << ' ';
            }
            cout << '\n';
        }
    }
}
int main() {
    Fast;
    int t = 1;
    cin >> t;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    while (t--) {
        //cout << "Case #" << i << ": ";
        solve();
        if (t)
            cout << '\n';
    }
}