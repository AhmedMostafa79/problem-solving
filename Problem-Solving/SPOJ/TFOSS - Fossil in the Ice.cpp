/*
    **Main Idea**
        -Geometry
        -Convex Hull
        -Rotating Calipers for efficient all pair points distance

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
const int N = 2e5 + 5;
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
    friend T dot(const point& p1, const point& p2) {
        return p1.x * p2.x + p1.y * p2.y;
    }
    T norm() {
        return hypot(x, y);//sqrt(p.x*p.x+p.y*p.y)
    }
    friend T cross(const point& p1, const point& p2) {//p1.x*
        return p2.x * p1.y - p1.x * p2.y;
    }
};
#define point point<ll>
ll dist(point p, point p2) {//Euclidean distance
    return (p.x - p2.x) * (p.x - p2.x) + (p.y - p2.y) * (p.y - p2.y);
}
int sign(ll num) {
    if (num < 0) return -1;
    else if (num == 0) return 0;
    else return 1;
}
#define nx(i) (i+1)%n
#define pv(i) (i-1+n)%n
vector<pair<int, int>> all_anti_podal(int n, vector<point>& p) {
    int p1 = 0, p2 = 0; // two "pointers"
    vector<pair<int, int>> result;

    // parallel edges should't be visited twice
    vector<bool> vis(n, false);

    for (; p1 < n; p1++) {
        // the edge that we are going to consider in this iteration
        // the datatype is Point, but it acts as a vector
        point base = p[nx(p1)] - p[p1];

        // the last condition makes sure that the cross products don't have the same sign
        while (p2 == p1 || p2 == nx(p1) || sign(cross(base, p[nx(p2)] - p[p2])) == sign(cross(base, p[p2] - p[pv(p2)]))) {
            p2 = nx(p2);
        }

        if (vis[p1]) continue;
        vis[p1] = true;

        result.push_back({ p1, p2 });
        result.push_back({ nx(p1), p2 });

        // if both edges from p1 and p2 are parallel to each other
        if (cross(base, p[nx(p2)] - p[p2]) == 0) {
            result.push_back({ p1, nx(p2) });
            result.push_back({ nx(p1), nx(p2) });
            vis[p2] = true;
        }
    }

    return result;
}

double orientation(point p0, point p1, point p2) {
    return cross((p1 - p0), p2 - p1);
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
            if (cross((p[1] - p[0]), p[2] - p[1]) >= 0)//if p1,p2,p3 form counter-clockwise 
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
    for (auto& i : v)cin >> i;
    if (n <= 1)
        return void(cout << "0\n");
    else if (n == 2) {
        return void(cout << dist(v[0], v[1]) << '\n');
    }
    convexHull(v);
    vector<pair<int, int>>res = all_anti_podal(v.size(), v);
    ll ans = 0;
    for (auto i : res) {
        ans = max(ans, dist(v[i.first], v[i.second]));
    }
    cout << ans << '\n';
    //cout << v[i.first]<<' '<<v[i.second] << "\n";

}
int main() {
    Fast;
    int t = 1;
    cin >> t;
    for (int i = 1; i <= t; i++) {
        solve();
    }
}