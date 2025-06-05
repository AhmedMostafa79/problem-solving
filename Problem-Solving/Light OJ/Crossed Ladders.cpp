
#include <bits/stdc++.h>
#include <unordered_map>
/*
    Main Idea..
    **Math
        -c=height of intersection
        -h1=height from ground to point where right-ladder intersects with left-building
        -h2=height from ground to point where left-ladder intersects with right-building
        -w=needed base
        -a=a part from w that is covered by right ladder
        -b=a part from w that is covered by left ladder
        ->c/h1=a/w,      c/h2=b/w 
        ->a=c*w/h1,      b=c*w/h2
        ->w=a+b
        ->w=(c*w/h1)+(c*w/h2)   /w
        ->1=(c/h1)+(c/h2)
        ->1=c*(1/h1)+(1/h2)-->1/c=(1/h1)+(1/h2)
        ->as h1 is a side of a right-angled triangle with hypot = x
                -->hence h1=sqrt(x*x-w*w)
        ->as h2 is a side of a right-angled triangle with hypot = y
                -->hence h1=sqrt(y*y-w*w)
        ->(1/h1)+(1/h2)-(1/c)=0
        ->1/(sqrt(x*x-w*w)) +(1/(sqrt(y*y-w*w))) -1/c =0
        
    **Binary Search: on W
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
double find_width(double x, double y, double c) {
    double l = 0.0, r = min(x, y);
    double eps = 1e-7, ans = 0.0;
    for (int i = 1; i <= 100; i++) {
        double mid = (l + r) / 2.0;
        double h1 = sqrt(x * x - mid * mid);
        double h2 = sqrt(y * y - mid * mid);
        double eq = 1.0 / h1 + 1.0 / h2;

        if (eq > 1.0 / c)
            r = mid;
        else {
            l = mid;
            ans = mid;
        }
    }

    return ans;
}

void solve() {
    double x, y, c;
    cin >> x >> y >> c;

    cout << find_width(x, y, c) << '\n';
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