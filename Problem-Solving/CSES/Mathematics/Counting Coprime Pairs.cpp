/*
    main idea..
    -number theory
    -combinatorics

    number theory:
       -prime factorization and smallest prime factor(spf)
    Combinatorics:
        -inclusion exclusion principle  A U B= A+B-(A^B)
        -suppose.. 2 5 10 20
            -primes: (2:3),(5:3),(10:2),(20:1)
            -res+=ans[2]-1=2
            -res+=ans[5]-1=2
            -res+=ans[10]=ans[2]+ans[5]=6(it is larger than n)..
                ..res+=ans[10]=ans[2]+ans[5]-ans[10](as 10 is lcm(2,5))=(3-1)+(3-1)-(2-1)=3
            -res+=ans[20]=ans[2]+ans[5]-ans[10] =(3-1)+(3-1)-(2-1)=3;
            inclusion exclusion:
            -we + that for each odd number of primes
            -we - that for each even number of primes
            -e.g. 2 3 5 if we add 30...ans[30]=ans[2]+ans[3]+ans[5]-ans[2*3]-ans[2*5]-ans[3*5]+ans[2*3*5]..according to AUBUC= A+B+C-(ANB)-(ANC)-(BNC)+(ANBNC)
            //U =Union
            //N=intersect
            */
#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;
#define  ll long long
#define  all(v) ((v).begin()),((v).end())
#define  rall(v) ((v).rbegin()),((v).rend())
#define Fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define close(n) return cout<<n,0;

const int dx[] = { -1,0,1,0,1,-1,1,-1 };
const int dy[] = { 0,-1,0,1,1,-1,-1,1 };
const int di[] = { 'U','R','D','L' };
int countbit(ll n) { return (n > 1 ? (n & 1) + countbit(n >> 1) : n); }
ll gcd(ll x, ll y) { if (!y)return x; return gcd(y, x % y); }
ll lcm(ll x, ll y) { return x * y / gcd(x, y); }

#define int ll

ostream& operator<<(ostream& out, vector<int>& v) {
    for (auto& i : v)
        out << i << " ";
    return out;
}istream& operator>>(istream& in, vector<int>& v) {
    for (auto& i : v)
        in >> i;
    return in;
}
const int mod = 1e9 + 9, N = 1e6 + 5;
vector<int>spf(N), cnt(N);
vector<int>in(N);
void seive() {
    iota(all(spf), 0);
    for (int i = 2; i < N; i++) {
        for (int j = i; j < N; j += i) {
            cnt[i] += in[j];
            spf[j] = min(spf[j], i);
        }
    }
}
int n;
//complete search function
int search(const vector<int>& v) {
    int c = 0, sum = 1, ret = 0;
    if (v.empty())
        return n - 1;
    int sz = v.size();

    for (int i = 1; i < (1ll << sz); i++) {
        sum = 1;
        c = 0;
        for (int j = 0; j < sz; j++) {
            if ((1ll << j) & i) {
                c++;
                sum *= v[j];
            }
        }
        if (c & 1)
            ret += n - cnt[sum];
        else
            ret -= n - cnt[sum];
    }
    return ret;
}
void solve() {
    cin >> n;
    vector<int>v(n);
    for (auto& i : v)
        cin >> i, in[i]++;
    seive();
    int res = 0;
    for (auto i : v) {
        vector<int>divs;
        int x = i;
        while (x > 1) {
            if (divs.empty() or divs.back() != spf[x])
                divs.push_back(spf[x]);
            x /= spf[x];
        }
        //cout << search(divs) << '\n';
        res += search(divs);
    }
    cout << res / 2 << '\n';
}
signed main() {
    Fast;
    int t = 1;
    //cin >> t;
    for (int i = 1; i <= t; i++) {
        //cout << "Case " << i << ": ";
        solve();
    }
}