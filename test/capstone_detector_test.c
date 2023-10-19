#include <stdio.h>
#include <assert.h>
#include <string.h>

#include "quirc.h"

#include "capstone_img.h"

int main(int argc, char **argv) {
    struct quirc *q = quirc_new();

    assert(quirc_resize(q, CAPSTONE_IMG_WIDTH, CAPSTONE_IMG_HEIGHT)==0);

    uint8_t *buffer = quirc_begin(q, NULL, NULL);
    memcpy(buffer, CAPSTONE_IMG, CAPSTONE_IMG_WIDTH * CAPSTONE_IMG_HEIGHT);
    quirc_end(q);

    int capstone_count = quirc_capstone_count(q);
    printf("capstone_count: %i\n", capstone_count);
    assert(capstone_count==1);

    for(int i=0;i<capstone_count;i++) {
        const struct quirc_capstone *capstone = quirc_get_capstone(q,i);
        printf("capstone->center: %i, %i\n", capstone->center.x, capstone->center.y);
        assert(capstone->center.x == 21);
        assert(capstone->center.y == 23);
    }

    quirc_destroy(q);

    return 0;
}
