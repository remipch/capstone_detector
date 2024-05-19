#include <stdio.h>
#include <assert.h>
#include <string.h>

#include "quirc.h"

#include "capstone_img.h"

int main(int argc, char **argv) {
    struct quirc *q = quirc_new();

    int capstone_count = quirc_detect_capstones(q,IMG,IMG_WIDTH,IMG_HEIGHT,100);
    assert(capstone_count==1);

    for(int i=0;i<capstone_count;i++) {
        const struct quirc_capstone *capstone = quirc_get_capstone(q,i);
        printf("capstone->center: %i, %i\n", capstone->center.x, capstone->center.y);
        assert(capstone->center.x == 21);
        assert(capstone->center.y == 22);
    }

    // Black level is between 30 and 45 in the test image
    // setting pixel_threshold to 40 prevent correct detection
    capstone_count = quirc_detect_capstones(q,IMG,IMG_WIDTH,IMG_HEIGHT,40);
    assert(capstone_count==0);

    // White level is between 210 and 245 in the test image
    // setting pixel_threshold to 220 prevent correct detection
    capstone_count = quirc_detect_capstones(q,IMG,IMG_WIDTH,IMG_HEIGHT,220);
    assert(capstone_count==0);

    quirc_destroy(q);

    return 0;
}
