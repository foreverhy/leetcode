#include "leet.h"

struct Point {
    int x, y;
    Point(): x(0), y(0) {}
    Point(int a, int b): x(a), y(b) {}
};


#include <algorithm>
#include <cstring>
#include <map>

int gcd(int a, int b) {
    a = std::abs(a);
    b = std::abs(b);
    if (a > b){
        return gcd(b, a);
    }
    return b ? gcd(b, a % b) : a;
}

bool operator<(const std::pair<int,int> &lhs, const std::pair<int,int> &rhs) {
    return lhs.first != rhs.first ? lhs.first < rhs.first : lhs.second < rhs.second;
}

bool operator==(const std::pair<int,int> &lhs, const std::pair<int,int> &rhs) {
    if (lhs.first != rhs.first) {
        return false;
    }
    return lhs.second == rhs.second;
}

struct slop {
    std::pair<int, int> k;
    std::pair<int, int> b;
};

inline bool operator<(const slop &lhs, const slop &rhs) {
    return lhs.k != rhs.k ? lhs.k < rhs.k : lhs.b < rhs.b;
}

inline bool operator==(const slop &lhs, const slop &rhs) {
    return lhs.k != rhs.k ? false : lhs.b == rhs.b;
}

inline bool operator==(const Point &lhs, const Point &rhs) {
    return lhs.x != rhs.x ? false : lhs.y == rhs.y;
}

inline bool operator!=(const Point &lhs, const Point &rhs) {
    return !(lhs == rhs);
}


class Solution{
  public:
    slop kb(const Point &A, const Point &B) {
        slop ret;
        auto dy = A.y - B.y;
        auto dx = A.x - B.x;
        auto g = gcd(dy, dx);
        ret.k.first = dy / g;
        ret.k.second = dx / g;
        auto pd = A.x * B.y - B.x * A.y;
        g = gcd(pd, dx);
        ret.b.first = pd / g;
        ret.b.second = dx / g;
        return ret;
    }

    bool online(const Point &pt, const slop &s) {
        return pt.y * s.k.second * s.b.second == s.b.second * s.k.first * pt.x + s.b.first * s.k.second;
    }

    int maxPoints(vector<Point> &points) {
        std::map<slop, int> mp;
        std::map<Point, int> pts;
        points.push_back({-1000, -1000});
        int sz = points.size();
        auto ans = 0;
        for (int i = 0; i < sz; ++i) {
            for (int j = i + 1; j < sz; ++j) if (points[i] != points[j]) {
                auto tmp = kb(points[i], points[j]);
                mp[tmp] = 0;
            }
        }
        for (int i = 0; i < sz; ++i) {
            for (auto &m : mp) {
                if (online(points[i], m.first)) {
                    m.second++;
                    ans = std::max(ans, m.second);
                }
            }
        }

        points.pop_back();
        return ans;
    }

};



int main(){
    Solution slu;



    return 0;
}


