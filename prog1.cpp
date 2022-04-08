#include <iostream>
#include <string>
#include <sstream>
#include <utility>
#include <vector>

using namespace std;

int main() {
    int n, i, x, y;
    cin >> n;
    string input, line;
    vector< pair<int,int> > points;
    cout << n << " " << i << endl;
    while(getline(cin, line)) {
        pair<int,int> p;

        stringstream ss(line);
        getline(ss, input, ',');
        // x = stoi(input);
        getline(ss, input);
        // y = stoi(input);

        points.push_back(p);
        
        ++i;
    }
    return 0;
}