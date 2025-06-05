/*
    main idea..
    -geometry
    -use halfplanes to get intersection of all edges
    -if such intersection exists..so answer=1 else 0


*/

#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>
#include <cmath>
#include <iomanip>

using namespace std;

#define ll long long
#define ld long double

const ld inf = 1e17;
const ld eps = 1e-9;

// Basic point/vector struct.
struct Point {
    typedef ld T;
    T x, y;
    Point() : x(0), y(0) {};
    Point(T x, T y) : x(x), y(y) {};
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

// Basic half-plane struct.
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
    ld alpha = cross(t.p - s.p, t.pq) / cross(s.pq, t.pq);
    return s.p + (s.pq * alpha);
}

vector<Point> hp_intersect(vector<Halfplane>& H) {
    Point box[4];
    box[0] = Point(inf, inf);
    box[1] = Point(-inf, inf);
    box[2] = Point(-inf, -inf);
    box[3] = Point(inf, -inf);

    for (int i = 0; i < 4; i++) {
        Halfplane aux(box[i], box[(i + 1) % 4]);
        H.push_back(aux);
    }

    sort(H.begin(), H.end());
    deque<Halfplane> dq;
    int len = 0;
    for (size_t i = 0; i < H.size(); i++) {
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
    for (size_t i = 0; i < dq.size(); i++) {
        size_t j = (i + 1) % dq.size();
        pts.push_back(inter(dq[i], dq[j]));
    }
    return pts;
}

int n;

void solve() {
    vector<Point> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i].x >> v[i].y;
    }
    vector<Halfplane> halfs;
    for (int i = 0; i < n; i++) {
        halfs.push_back(Halfplane(v[i], v[(i + 1) % n]));
    }
    vector<Point> intersection = hp_intersect(halfs);
    cout << (intersection.size() >= 1) << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout << fixed << setprecision(15);

    for (int i = 1; cin >> n && n; i++) {
        solve();
    }
    return 0;
}