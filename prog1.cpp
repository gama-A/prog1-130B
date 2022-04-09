#include <iostream>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

struct Point {
    int x,y;
};

int lineDst(Point p1, Point p2, Point q);

int side(Point p1, Point p2, Point q);

void customSort(vector<Point>& v);

vector<Point> FindHull(vector<Point>& p, Point min, Point max, int s, int n){
    vector<Point> left, right;

    int index = -1, maxDst = 0;

    for (int i = 0; i < n; i++) {
        int dist = lineDst(min, max, p[i]);
        if( (side(min,max,p[i]) == s) && (dist > maxDst) ) {
            index = i;
            maxDst = dist;
        }
    }

    if(index != -1) {
        left = FindHull(p, p[index], min, -side(p[index], min, max), n);
        right = FindHull(p, p[index], max, -side(p[index], max, min), n);
        left.insert( left.end(), right.begin(), right.end() );
        return left;
    }

    left.push_back(min);
    left.push_back(max);
    return left;
}

vector<Point> QuickHull(vector<Point>& p, int n) {
    vector<Point> left, right;

    int min_y = 0, max_y = 0;
    for(int i = 0; i < n; i++) {
        if(p[i].y < p[min_y].y)
            min_y = i;
        if (p[i].y > p[max_y].y)
            max_y = i;
    }

    left = FindHull(p, p[min_y], p[max_y], -1, n);
    right = FindHull(p, p[min_y], p[max_y], 1, n);

    left.insert( left.end(), right.begin(), right.end() );

    return left;
}

int main() {
    int n, i, x, y;
    cin >> n;
    string input, line;
    vector<Point> points;
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

    vector<Point> hull;
    hull = QuickHull(points, n);

    customSort(hull);

    return 0;
}