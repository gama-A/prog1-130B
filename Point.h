#include <iostream>

struct Point {
    float x,y;

    Point() : x(0.0), y(0.0) {};
    Point(const float& x, const float& y) : x(x), y(y) {};

    bool operator==(const Point& p) const { return x == p.x && y == p.y; };

    bool operator<(const Point& p) const { return x < p.x || (x == p.x && y == p.x); };
    
    size_t operator()(const Point& pointToHash) const noexcept {
        size_t hash = pointToHash.x + 12.5 * pointToHash.y;
        return hash;
    }
};


namespace std {
    template<> struct hash<Point> {
        std::size_t operator()(const Point& p) const noexcept {
            return std::hash<float>()(p.x) ^ std::hash<float>()(p.y);
        }
    };
}
