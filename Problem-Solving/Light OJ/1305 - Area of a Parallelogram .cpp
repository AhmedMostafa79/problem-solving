

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
template<class T = double>
struct point {
    T x, y;
    point() :x(0), y(0) {}
    point(T x, T y) :x(x), y(y) {}
    point operator +(point a) {
        return { x + a.x, y + a.y };
    }
    point operator +(T scaler) {
        return { x + scaler, y + scaler };
    }
    point operator -(point a) {
        return { x - a.x, y - a.y };
    }
    point operator -(T scaler) {
        return { x - scaler, y - scaler };
    }
    point operator *(T scaler) {
        return { x * scaler , y * scaler };
    }
    point operator /(T scaler) {
        return { x / scaler , y / scaler };
    }
    friend istream& operator>>(istream& in, point& p) {
        in >> p.x >> p.y;
        return in;
    }
    friend ostream& operator<<(ostream& out, point& p) {
        out << p.x << " " << p.y;
        return out;
    }
    T dot(const point& p1) {
        return x * p1.x + y * p1.y;
    }
    T norm() {
        return hypot(x, y);//sqrt(p.x*p.x+p.y*p.y)
    }
    T cross(const point& p1) {//p1.x*
        return x * p1.y - p1.x * y;
    }
};
#define point point<ll>
double dist(point p, point p2) {//Euclidean distance
    return hypotl(p.x - p2.x, p.y - p2.y);
}
long double point_ray_dist(point a, point b, point c) {
    point ab = b - a;
    point ac = c - a;
    double t = ab.dot(ac) / ab.dot(ab);
    if (t < 0)
        return dist(a, c);
    point proj = a + ab * t;
    return dist(proj, c);
}
double point_segment_dist(point a, point b, point c) {
    point ab = b - a;
    point ac = c - a;
    double t = ab.dot(ac) / ab.dot(ab);
    if (t < 0)
        return dist(a, c);
    if (t > 1)
        return dist(b, c);
    point proj = a + ab * t;
    return dist(proj, c);
}
double point_line_dist(point a, point b, point c) {
    point ab = b - a;
    point ac = c - a;
    double t = ab.dot(ac) / ab.dot(ab);
    point proj = a + ab * t;
    return dist(proj, c);
}
void solve() {
    point a, b, c;
    cin >> a >> b >> c;
    //ab=dc ...bx-ax=cx-dx...dx=ax+cx-bx;
    //ab=dc ...by-ay=cy-dy...dx=ay+cy-by;
    point d = { a.x + c.x - b.x,c.y + a.y - b.y };
    cout << d << ' ';
    cout << abs((b - a).cross(d - a)) << '\n';
}
#define files  freopen("raydist.in", "r", stdin);freopen("raydist.out", "w", stdout);
int main() {
    Fast;
    int t = 1;
    //files;
    cin >> t;
    cout << fixed << setprecision(15);

    for (int i = 1; i <= t; i++) {
        cout << "Case " << i << ": ";
        solve();
    }
}