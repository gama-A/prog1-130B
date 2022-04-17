// Gama Aristondo, 8404071
// Programming Assignment 1

#include <iostream>
#include <string>
#include <sstream>
#include <unordered_set>
#include <vector>
#include <algorithm>
#include <cmath>

#include "Point.h"

using namespace std;

unordered_set<Point> hull;

float lineDst(Point p1, Point p2, Point q) {
    return abs( (q.y - p1.y) * (p2.x - p1.x) - (p2.y - p1.y) * (q.x - p1.x) );
}

int side(Point p1, Point p2, Point q) {
    float s = (q.y - p1.y) * (p2.x - p1.x) - (p2.y - p1.y) * (q.x - p1.x);

    if(s > 0)
        return 1;
    if(s < 0)
        return -1;
    return 0;
}

void QuickHull(vector<Point> p, Point min, Point max, float s, int n){
    float index = -1, maxDst = 0;

    for (int i = 0; i < n; i++) {
        float dist = lineDst(min, max, p[i]);
        int pointSide = side(min, max, p[i]);
        if( (pointSide == s) && (dist > maxDst) ) {
            index = i;
            maxDst = dist;
        }
    }

    if(index == -1) {
        hull.insert(min);
        hull.insert(max);
        return;
    }
    QuickHull(p, p[index], min, -side(p[index], min, max), n);
    QuickHull(p, p[index], max, -side(p[index], max, min), n);
    
    return;
}

int findIndex(Point p, vector<Point> vp) {
    vector<Point>::iterator it = find(vp.begin(), vp.end(), p);
    return distance(vp.begin(), it);
}

int main() {
    int n, i;
    float x, y;
    i = 0;
    cin >> n;
    string input, line;
    vector<Point> points, left, right;
    while(getline(cin, line)) {
        Point temp;

        stringstream ss(line);
        getline(ss, input, ',');
        istringstream(input) >> x;
        getline(ss, input);
        istringstream(input) >> y;

        temp.x = x;
        temp.y = y;

        points.push_back(temp);
        
        if(i == n) break;

        ++i;
    }
    points.erase(points.begin());

    int min_y = 0, max_y = 0;
    for(int i = 0; i < n; i++) {
        if(points[i].y < points[min_y].y)
            min_y = i;
        if (points[i].y > points[max_y].y)
            max_y = i;
    }

    QuickHull(points, points[min_y], points[max_y], -1, n);
    QuickHull(points, points[min_y], points[max_y], 1, n);

    vector<Point> h(hull.begin(), hull.end());


    std::cout << hull.size() << endl;
    for(auto i : hull) {
        std::cout << findIndex(i, points) << ", " << i.x << ", " << i.y << '\n';
    }

    return 0;
}