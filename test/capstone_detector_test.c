#include <stdio.h>
#include <assert.h>
#include <string.h>

#include "quirc.h"

#include "capstone_img.h"

int main(int argc, char **argv) {
    struct quirc *q = quirc_new();

    int capstone_count = quirc_detect_capstones(q,IMG,IMG_WIDTH,IMG_HEIGHT);
    assert(capstone_count==1);

    for(int i=0;i<capstone_count;i++) {
        const struct quirc_capstone *capstone = quirc_get_capstone(q,i);
        printf("capstone->center: %i, %i\n", capstone->center.x, capstone->center.y);
        assert(capstone->center.x == 21);
        assert(capstone->center.y == 22);
    }

    quirc_destroy(q);

    return 0;
}
