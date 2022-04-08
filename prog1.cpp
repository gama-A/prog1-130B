#include <iostream>
#include <string>
#include <utility>
#include <vector>

using namespace std;

int main(int argc, char *argv[]) {
    string in;
    cin >> in;
    int n = stoi(in);
    string input;
    vector<string> points;
    while(0 < n) {
        getline(cin, input);
        points.push_back(input);
    }
    return 0;
}