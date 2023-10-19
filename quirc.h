/* quirc -- QR-code recognition library
 * Copyright (C) 2010-2012 Daniel Beer <dlbeer@gmail.com>
 *
 * Permission to use, copy, modify, and/or distribute this software for any
 * purpose with or without fee is hereby granted, provided that the above
 * copyright notice and this permission notice appear in all copies.
 *
 * THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES
 * WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF
 * MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR
 * ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES
 * WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN
 * ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF
 * OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.
 */

#ifndef QUIRC_H_
#define QUIRC_H_

#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

#ifdef QUIRC_FLOAT_TYPE
/* Quirc uses double precision floating point internally by default.
 * On platforms with a single precision FPU but no double precision FPU,
 * this can be changed to float by defining QUIRC_FLOAT_TYPE.
 *
 * When setting QUIRC_FLOAT_TYPE to 'float', consider also defining QUIRC_USE_TGMATH.
 * This will use the type-generic math functions (tgmath.h, C99 or later) instead of the normal ones,
 * which will allow the compiler to use the correct overloaded functions for the type.
 */
typedef float quirc_float_t;
#else
typedef double quirc_float_t;
#endif

struct quirc;

/* Construct a new QR-code recognizer. This function will return NULL
 * if sufficient memory could not be allocated.
 */
struct quirc *quirc_new(void);

/* Destroy a QR-code recognizer. */
void quirc_destroy(struct quirc *q);

/* Detect all capstones in the given image
 *
 * Memory will be reallocated if given image dimensions
 * are different from the last image dimensions
 *
 * return capstone_count
 */
int quirc_detect_capstones(struct quirc *q, const uint8_t * image, int w, int h);

/* This structure describes a location in the input image buffer. */
struct quirc_point {
	int	x;
	int	y;
};

#define QUIRC_PERSPECTIVE_PARAMS	8

struct quirc_capstone {
	int			ring;
	int			stone;

	struct quirc_point	corners[4];
	struct quirc_point	center;
	quirc_float_t		c[QUIRC_PERSPECTIVE_PARAMS];
};

/* Get the capstone info specified by the given index. */
const struct quirc_capstone * quirc_get_capstone(const struct quirc *q, int index);

#ifdef __cplusplus
}
#endif

#endif
