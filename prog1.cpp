// Gama Aristondo, 8404071
// Programming Assignment 1

#include <iostream>
#include <string>
#include <sstream>
#include <set>
#include <vector>

using namespace std;

#define Point pair<float,float>

set<Point> hull;

float lineDst(Point p1, Point p2, Point q) {
    return abs( (q.second - p1.second) * (p2.first - p1.first) - (p2.second - p1.second) * (q.first - p1.first) );
}

float side(Point p1, Point p2, Point q) {
    float s = (q.second - p1.second) * (p2.first - p1.first) - (p2.second - p1.second) * (q.first - p1.first);

    if(s > 0)
        return 1;
    if(s < 0)
        return -1;
    return 0;
}

void customSort(vector<Point>& v);

void QuickHull(vector<Point> p, Point min, Point max, int s, int n){
    float index = -1, maxDst = 0;

    for (int i = 0; i < n; i++) {
        float dist = lineDst(min, max, p[i]);
        float pointSide = side(min,max,p[i]);
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
    
    // return res;
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

        temp.first = x;
        temp.second = y;

        points.push_back(temp);
        
        if(i == n) break;

        ++i;
    }
    points.erase(points.begin());

    int min_y = 0, max_y = 0;
    for(int i = 0; i < n; i++) {
        if(points[i].second < points[min_y].second)
            min_y = i;
        if (points[i].second > points[max_y].second)
            max_y = i;
    }

    QuickHull(points, points[min_y], points[max_y], -1, n);
    QuickHull(points, points[min_y], points[max_y], -1, n);

    cout << hull.size() << endl;
    int j = 0;
    for(auto i : hull) {
        cout << j << ", " << i.first << ", " << i.second << '\n';
        ++j;
    }

    return 0;
}