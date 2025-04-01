#include <cassert>
#include <cstdio>
#include <cstdbool>
#include <cstdlib>
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <map>

using namespace std;

// check if v contains c
inline bool contains(vector<int>& v, int c) {
    for (int e : v) if (e == c) return true;
    return false;
}

int main() {
    vector<int> left{};
    vector<int> right{};

    // read input
    ifstream f("input-example.txt");
    assert(f.is_open());

    string line;
    while (getline(f, line)) {
        int l, r;
        assert(sscanf(line.data(), "%d   %d", &l, &r) == 2);
        left.push_back(l);
        right.push_back(r);
    }

    // remove dups from left and add to new arr
    vector<int> left_dedup;
    for (int l : left) {
        if (!contains(left_dedup, l)) {
            left_dedup.push_back(l);
        }
    }

    for (int l : left_dedup) cout << l << endl;

    // works by o[<number>] = <occ. of number>
    map<int, int> o{};
    for (int l : left_dedup) {
        // comparing l to every elem. of right (r)
        // this means that if l = r then r occured in left_nodups
        for (int r : right) {
            //printf("l = %d, r = %d\n", l, r);
            if (l == r) o[l]++;
            // o.insert(l, o.at(l) + 1);
        }
    }

    int sim_score = 0;
    for (int li = 0; li < left.size(); li++) {
        int l = left[li];
        sim_score += l * o[l];
        if (o[l] != 0)
        // printf("%d occured %d times\n", l, o[l]);
            // printf("%d + ", l * o[l]);
        cout << l << " * " << o[l] << " = " << l * o[l] << endl;
    }
    printf("\nsim_score: %d\n", sim_score);
}
