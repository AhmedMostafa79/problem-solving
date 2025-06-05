
#include <bits/stdc++.h>
#include <unordered_map>
/*
    Main Idea..
        1)build Convex hull
        2)brute force for each 3 consecutive points
        3)get the angle between ABC
            -cos(theta)= BA dot BC / |BA| * |BC|
            -ans =min(acos(cos(theta)),ans)
*/

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
    T norm() {//norm|magnitude
        return hypot(x, y);//sqrt(p.x*p.x+p.y*p.y)
    }
    T cross(const point& p1) {//p1.x*
        return x * p1.y - p1.x * y;
    }
};
#define point point<double>
double dist(point p, point p2) {//Euclidean distance
    return hypot(p.x - p2.x, p.y - p2.y);
}
double orientation(point p0, point p1, point p2) {
    return (p1 - p0).cross(p2 - p1);
}
void convexHull(vector<point>& v) {
    if (v.size() <= 2)
        return;
    point p0 = *min_element(all(v), [&](point p1, point p2) {
        if (p1.y != p2.y)
            return p1.y < p2.y;
        return  p1.x < p2.x;
        });
    //if not collinear sort in clockwise order, otherwise sort in distance from p0
    sort(all(v), [&p0](const point& p1, const point& p2) {
        double o = orientation(p0, p1, p2);
        if (o == 0)
            return dist(p0, p1) < dist(p0, p2);
        return o < 0;
        });
    //remove duplicates
    v.erase(unique(all(v),
        [&](point p1, point p2) {
            return p1.x == p2.x and p1.y == p2.y;
        }), v.end());

    int n = v.size();
    vector<point>hull;
    for (int i = 0; i < n; i++) {
        while (hull.size() >= 2) {
            point p[] = { hull[hull.size() - 2],hull.back(),v[i] };
            if ((p[1] - p[0]).cross(p[2] - p[1]) >= 0)//if p1,p2,p3 form counter-clockwise 
                hull.pop_back();
            else break;
        }
        hull.push_back(v[i]);
    }
    v = hull;
}
void solve() {
    int n;
    cin >> n;
    vector<point>v(n);
    for (auto& i : v)
        cin >> i;
    if (n <= 2)
        return void(cout << "0\n");
    convexHull(v);
    double ans = 1e18;
    n = v.size();
    double pi = acos(-1);
    for (int i = 0; i < n; i++) {
        point ba = v[i] - v[(i + 1) % n];
        point bc = v[(i + 2) % n] - v[(i + 1) % n];
        double angle = ba.dot(bc) / (ba.norm() * bc.norm());
        angle = max(-1.0, min(1.0, angle));
        ans = min(ans, acos(angle) * 180 / pi);
    }
    cout << ans << '\n';
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