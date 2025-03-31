#include <assert.h>
#include <stdio.h>

struct pair { int a, b; };

int main() {
    int left[128] = {0};
    int right[128] = {0};

    // read in input
    FILE* f = fopen("input.txt", "r");
    assert(f != NULL);

    char line_buf[128] = {0};
    int n_pairs = 0;
    while (fgets(line_buf, sizeof(line_buf), f)) {
        sscanf(line_buf, "%d   %d", &left[n_pairs], &right[n_pairs]);
        n_pairs++;
    }

    // sort
    int swap_count = 0;
    while (swap_count == 0) {
        for (int i = 0; i < n_pairs; i++) {
            printf("swapcount = %d\n", swap_count);
            if (i+1 > n_pairs) break;
            if (right[i+1] < right[i]) {
                swap_count++;
                int temp = right[i+1];
                right[i+1] = right[i];
                right[i] = temp;
            }
            if (left[i+1] < left[i]) {
                swap_count++;
                int temp = left[i+1];
                left[i+1] = left[i];
                left[i] = temp;
            }

        }
        swap_count = 0;
    }
    for (int j = 0; j < n_pairs; j++) {
        printf("    %d, %d\n", left[j], right[j]);
    }
}
