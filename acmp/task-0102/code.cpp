#include <bits/stdc++.h>

// Time complexity: O(1)
// Space complexity: O(1)

struct Point {

    long long x;

    long long y;

    int type;

    Point()
    {}

    Point(long long x, long long y)
            : x(x)
            , y(y)
            , type(y > 0 || (y == 0 && x >= 0))
    {}

    static Point read() {
        long long x, y;
        scanf("%lld %lld", &x, &y);
        return {x, y};
    }

    long long getLen2() const {
        return x * x + y * y;
    }

    long double getLen() const {
        return (long double) sqrt(getLen2());
    }

    bool operator ==(const Point &a) const {
        return x == a.x && y == a.y;
    }

    Point operator +(const Point &a) const {
        return Point{x + a.x, y + a.y};
    }

    Point operator -(const Point &a) const {
        return Point{x - a.x, y - a.y};
    }

    Point operator *(long long a) const {
        return Point{x * a, y * a};
    }

    long long operator *(const Point &a) const {
        return x * a.x + y * a.y;
    }

    long long operator %(const Point &a) const {
        return x * a.y - a.x * y;
    }

    long double getAngle(const Point &a) const {
        return acos(*this * a * 1.0 / getLen() / a.getLen());
    }
};

int getSign(long long n) {
    if (n >= 0) {
        return 1;
    } else {
        return -1;
    }
}

int main() {
    const long double EPS = 10e-8;
    const int N = 3;
    std::vector<Point> p(N);
    for (int i = 0; i < N; i++) {
        p[i] = Point::read();
    }
    p.emplace_back(p[0]);
    Point a = Point::read();
    for (int i = 1; i <= N; i++) {
        long long dy = p[i].y - p[i - 1].y;
        long long dx = p[i].x - p[i - 1].x;
        if (dy * a.x - dx * a.y == dy * p[i].x - dx * p[i].y &&
            Point(p[i - 1] - a) * Point(p[i] - a) <= 0
        ) {
            printf("In");
            return 0;
        }
    }
    long double sum = 0.0;
    for (int i = 1; i <= N; i++) {
        sum += getSign((p[i - 1] - a) % (p[i] - a)) * Point(p[i - 1] - a).getAngle(Point(p[i] - a));
    }
    if (std::fabs(sum) <= EPS) {
        printf("Out");
    } else {
        printf("In");
    }
    return 0;
}