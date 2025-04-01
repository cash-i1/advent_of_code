#include <cassert>
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <map>

using namespace std;

// check if v contains c
bool in(vector<int>& v, int c) {
    for (int e : v) if (e == c) return true;
    return false;
}

int main() {
    // vars
    vector<int> left;
    vector<int> left_nodups;
    vector<int> right;
    map<int, int> ap;
    int sim_score = 0;

    // load input
    ifstream f("input.txt");
    assert(f.is_open());

    string line;
    while (getline(f, line)) {
        int l, r;
        assert(sscanf(line.data(), "%d   %d", &l, &r) == 2);
        left.push_back(l);
        right.push_back(r);
    }

    // populate left_nodups
    for (int l : left)
        if (!in(left_nodups, l)) left_nodups.push_back(l);

    // populate ap (occurances of left num in right)
    for (int l : left)
        for (int r : right) if (l == r) ap[l]++;
        

    // calculate sim score
    for (int l : left_nodups)
        sim_score += l * ap[l];

    cout << sim_score << endl;
}
