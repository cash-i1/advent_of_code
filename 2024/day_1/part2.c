#include <assert.h>
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#define ARRLEN 4096 * 8

bool contains(int* array, int len, int query) {
    for (int i = 0; i < len; i++) {
        if (array[i] == query) return true;
    }
    return false;
}

int main() {
    int left[ARRLEN] = {0};
    int right[ARRLEN] = {0};

    // read input
    // FILE* f = fopen("input-example.txt", "r");
    FILE* f = fopen("input.txt", "r");
    assert(f != NULL);

    char line_buf[ARRLEN] = {0};
    int pairs_amt = 0;
    while (fgets(line_buf, sizeof(line_buf), f)) {
        assert(sscanf(line_buf, "%d   %d", &left[pairs_amt], &right[pairs_amt]) == 2);
        pairs_amt++;
    }


    // make array that is left without dups
    int left_nodups[ARRLEN] = {0};
    int left_nodups_len = 0;
    for (int i = 0; i < ARRLEN; i++) {
        if (!contains(left_nodups, pairs_amt, left[i])) {
            left_nodups[left_nodups_len++] = left[i];
        }
    }

    // works by o[<number>] = <occ. of number>
    int o[ARRLEN] = {0};
    for (int li = 0; li < left_nodups_len; li++) {
        int l = left_nodups[li];

        // comparing left_nodups[i] (l) to every elem. of right (r)
        // this means that if l = r then r occured in left_nodups
        for (int ri = 0; ri < pairs_amt; ri++) {
            int r = right[ri];

            //printf("l = %d, r = %d\n", l, r);
            if (l == r) o[l]++;
        }
    }

    int sim_score = 0;
    for (int li = 0; li < pairs_amt; li++) {
        int l = left[li];
        sim_score += l * o[l];
        //printf("%d occured %d times\n", l, o[l]);
        printf("%d + ", l * o[l]);
    }
    printf("\nsim_score: %d\n", sim_score);
}
