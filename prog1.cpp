#include <iostream>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

struct Point {
    int x,y;
};

vector<Point> FindHull(vector<Point>& p, Point min, Point max, int s, int n);

void QuickHull(vector<Point> p, int n) {
    vector<Point> hull, left, right;

    int min_y = 0, max_y = 0;
    for(int i = 0; i < p.size(); ++i) {
        if(p[i].y < p[min_y].y)
            min_y = i;
        if (p[i].y > p[max_y].y)
            max_y = i;
    }

    left = FindHull(p, p[min_y], p[max_y], -1, n);
    right = FindHull(p, p[min_y], p[max_y], 1, n);

    left.insert( left.end(), right.begin(), right.end() );
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

    QuickHull(points, n);

    return 0;
}