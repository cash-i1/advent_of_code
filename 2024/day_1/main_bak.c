#include <assert.h>
#include <stdio.h>

struct pair { int a, b; };

int main() {
    struct pair pairs[128] = {0};
    int npairs = 0;

    // read in input
    FILE* f = fopen("input.txt", "r");
    assert(f != NULL);

    char line_buf[128] = {0};
    while (fgets(line_buf, sizeof(line_buf), f)) {
        sscanf(line_buf, "%d   %d", &pairs[npairs].a, &pairs[npairs].b);
        npairs++;
    }

    for (int i = 0; i < npairs; i++) {
        printf("%d, %d\n", pairs[i].a, pairs[i].b);
    }
}
