#include <assert.h>
#include <stdio.h>
#include <stdbool.h>

int main() {
    int left[128] = {0};
    int right[128] = {0};

    // read input
    FILE* f = fopen("input.txt", "r");
    assert(f != NULL);

    char line_buf[128] = {0};
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

    // print pairs
    for (int j = 0; j < pairs_amt; j++) {
        printf("%d, %d\n", left[j], right[j]);
    }
}
