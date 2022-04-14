// Gama Aristondo, 8404071
// Programming Assignment 1

#include <iostream>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

struct Point {
    int x,y;
};

int lineDst(Point p1, Point p2, Point q) {
    return abs( (q.y - p1.y) * (p2.x - p1.x) - (p2.y - p1.y) * (q.x - p1.x) );
}

int side(Point p1, Point p2, Point q) {
    int s = (q.y - p1.y) * (p2.x - p1.x) - (p2.y - p1.y) * (q.x - p1.x);

    if(s > 0)
        return 1;
    if(s < 0)
        return -1;
    return 0;
}

void customSort(vector<Point>& v);

vector<Point> FindHull(vector<Point> p, Point min, Point max, int s, int n){
    vector<Point> left, right, res;

    int index = -1, maxDst = 0;

    for (int i = 0; i < n; i++) {
        int dist = lineDst(min, max, p[i]);
        int pointSide = side(min,max,p[i]);
        if( (pointSide == s) && (dist > maxDst) ) {
            index = i;
            maxDst = dist;
        }
    }

    if(index == -1) {
        res.push_back(min);
        res.push_back(max);
        return res;
    }
    left = FindHull(p, p[index], min, -side(p[index], min, max), n);
    right = FindHull(p, p[index], max, -side(p[index], max, min), n);
    // res.reserve( left.size() + right.size() );
    res.insert( res.end(), left.begin(), left.end() );
    res.insert( res.end(), right.begin(), right.end() );
    return res;

    return res;
}

vector<Point> QuickHull(vector<Point> p, int n) {
    vector<Point> left, right, res;

    int min_y = 0, max_y = 0;
    for(int i = 0; i < n; i++) {
        if(p[i].y < p[min_y].y)
            min_y = i;
        if (p[i].y > p[max_y].y)
            max_y = i;
    }

    left = FindHull(p, p[min_y], p[max_y], -1, n);
    right = FindHull(p, p[min_y], p[max_y], 1, n);

    //res.reserve( left.size() + right.size() );
    res.insert( res.end(), left.begin(), left.end() );
    res.insert( res.end(), right.begin(), right.end() );

    return res;
}

int main() {
    int n, i, x, y;
    i = 0;
    cin >> n;
    string input, line;
    vector<Point> points, hull;
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
    for (int i = 0; i < points.size(); i++)
    {
        cout << points[i].x << " " << points[i].y << '\n';
    }
    

    hull = QuickHull(points, n);

    cout << hull.size() << endl;
    for(int i = 0; i < hull.size(); i++) {
        cout << i << "," << hull[i].x << "," << hull[i].y << endl;
    }

    return 0;
}