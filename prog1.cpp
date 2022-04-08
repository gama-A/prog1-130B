#include <iostream>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

struct Point {
    int x,y;
};

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
    return 0;
}