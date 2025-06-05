/*
    main idea..
    -get intersection of all halfplanes(a point can be seen by all convex's points).
    -Geometry
    -halfplanes intersection
    -if there is at least an intersection point ...YES otherwise NO

*/


#include <iostream>
#include <vector>
#include <algorithm>
#include <deque>
#include <cmath>
using namespace std;

#define ll long long

const int dx[] = { -1, 0, 1, 0, 1, -1, 1, -1 };
const int dy[] = { 0, -1, 0, 1, 1, -1, -1, 1 };
const char di[] = { 'U', 'R', 'D', 'L' };

int countbit(ll n) { return (n > 1 ? (n & 1) + countbit(n >> 1) : n); }
ll gcd(ll x, ll y) { if (!y) return x; return gcd(y, x % y); }
ll lcm(ll x, ll y) { return x * y / gcd(x, y); }

typedef long double ld;
const ld inf = 1e17, eps = 1e-9L;

struct Point {
    typedef ld T;
    T x, y;
    Point() : x(0), y(0) {}
    Point(T x, T y) : x(x), y(y) {}
};

Point operator+(const Point& p, const Point& q) {
    return Point(p.x + q.x, p.y + q.y);
}

Point operator-(const Point& p, const Point& q) {
    return Point(p.x - q.x, p.y - q.y);
}

Point operator*(const Point& p, const ld k) {
    return Point(p.x * k, p.y * k);
}

ld dot(const Point& p, const Point& q) {
    return p.x * q.x + p.y * q.y;
}

ld cross(const Point& p, const Point& q) {
    return p.x * q.y - p.y * q.x;
}

struct Halfplane {
    Point p, pq;
    ld angle;

    Halfplane(const Point& a, const Point& b) : p(a), pq(b - a) {
        angle = atan2(pq.y, pq.x);
    }

    bool out(const Point& r) const {
        return cross(pq, r - p) < -eps;
    }

    bool operator<(const Halfplane& e) const {
        return angle < e.angle;
    }
};

Point inter(const Halfplane& s, const Halfplane& t) {
    ld alpha = cross((t.p - s.p), t.pq) / cross(s.pq, t.pq);
    return s.p + (s.pq * alpha);
}

vector<Point> hp_intersect(vector<Halfplane>& H) {
    Point box[4] = {
        Point(inf, inf),
        Point(-inf, inf),
        Point(-inf, -inf),
        Point(inf, -inf)
    };

    for (int i = 0; i < 4; ++i) {
        Halfplane aux(box[i], box[(i + 1) % 4]);
        H.push_back(aux);
    }

    sort(H.begin(), H.end());
    deque<Halfplane> dq;
    int len = 0;
    for (size_t i = 0; i < H.size(); ++i) {
        while (len > 1 && H[i].out(inter(dq[len - 1], dq[len - 2]))) {
            dq.pop_back();
            --len;
        }

        while (len > 1 && H[i].out(inter(dq[0], dq[1]))) {
            dq.pop_front();
            --len;
        }

        if (len > 0 && fabs(cross(H[i].pq, dq[len - 1].pq)) < eps) {
            if (dot(H[i].pq, dq[len - 1].pq) < 0.0)
                return vector<Point>();

            if (H[i].out(dq[len - 1].p)) {
                dq.pop_back();
                --len;
            }
            else continue;
        }

        dq.push_back(H[i]);
        ++len;
    }

    while (len > 2 && dq[0].out(inter(dq[len - 1], dq[len - 2]))) {
        dq.pop_back();
        --len;
    }

    while (len > 2 && dq[len - 1].out(inter(dq[0], dq[1]))) {
        dq.pop_front();
        --len;
    }

    if (len < 3) return vector<Point>();

    vector<Point> pts;
    for (size_t i = 0; i < dq.size(); ++i) {
        size_t j = (i + 1) % dq.size();
        pts.push_back(inter(dq[i], dq[j]));
    }
    return pts;
}

void solve() {
    int n;
    cin >> n;
    vector<Point> v(n);
    for (int i = 0; i < n; ++i) {
        cin >> v[i].x >> v[i].y;
    }
    vector<Halfplane> hps;
    reverse(v.begin(), v.end());
    for (int i = 0; i < n; ++i) {
        hps.push_back(Halfplane(v[i], v[(i + 1) % n]));
    }
    vector<Point> res = hp_intersect(hps);
    cout << (res.empty() ? "NO\n" : "YES\n");
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    for (int i = 1; i <= t; ++i) {
        solve();
    }
    return 0;
}