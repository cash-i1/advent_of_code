#include <assert.h>
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#define ARRLEN 4096

int main() {
    int left[ARRLEN] = {0};
    int right[ARRLEN] = {0};

    // read input
    FILE* f = fopen("input.txt", "r");
    assert(f != NULL);

    char line_buf[ARRLEN] = {0};
    int pairs_amt = 0;
    while (fgets(line_buf, sizeof(line_buf), f)) {
        sscanf(line_buf, "%d   %d", &left[pairs_amt], &right[pairs_amt]);
        pairs_amt++;
    }

    // if there is a swap this iter
    bool swapped = true;

    // sort
    while (swapped) {
        swapped = false;
        for (int i = 0; i < pairs_amt; i++) {
            if (i+1 >= pairs_amt) break;

            // if next is less than current ...
            if (left[i+1] < left[i]) {
                // swap [i] and [i+1]
                int temp = left[i];  
                left[i] = left[i+1];
                left[i+1] = temp;
                swapped = true;
            }

            // same for right
            if (right[i+1] < right[i]) {
                int temp = right[i];  
                right[i] = right[i+1];
                right[i+1] = temp;
                swapped = true;
            }
        }
    }

    // distances
    int distances[ARRLEN] = {0};
    for (int i = 0; i < pairs_amt; i++) {
        // int distance = 0;
        // if (left[i] > right[i]) distance = left[i] - right[i];
        // if (right[i] > left[i]) distance = right[i] - left[i];
        // distances[i] = distance;
        distances[i] = abs(left[i] - right[i]);
    }

    // total distance
    int total_distance = 0;
    for (int i = 0; i < pairs_amt; i++) {
        total_distance += distances[i];
    }

    printf("total_distance: %d\n", total_distance);
}
