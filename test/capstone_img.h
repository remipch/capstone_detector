#include <stdint.h>

/* Define image 'capstone_img' of size 48x48x1x1 and type 'uint8' */
static const int IMG_WIDTH = 48;
static const int IMG_HEIGHT = 48;
static const uint8_t IMG[] = {
  226, 225, 224, 224, 225, 225, 224, 223, 229, 227, 224, 224, 225, 225, 223, 222,
  221, 222, 222, 222, 223, 225, 226, 224, 225, 224, 222, 220, 221, 222, 222, 220,
  217, 224, 221, 215, 217, 217, 216, 222, 232, 148, 53, 81, 85, 84, 75, 76,
  225, 224, 223, 223, 224, 225, 224, 223, 226, 224, 222, 221, 222, 222, 221, 219,
  223, 223, 223, 221, 222, 223, 222, 221, 223, 223, 222, 221, 221, 223, 222, 220,
  218, 223, 221, 217, 219, 218, 217, 223, 232, 153, 51, 83, 84, 83, 76, 75,
  224, 223, 222, 223, 224, 225, 224, 223, 226, 224, 223, 223, 224, 225, 223, 222,
  220, 221, 221, 220, 221, 223, 224, 222, 223, 223, 223, 221, 221, 222, 221, 219,
  218, 221, 220, 218, 219, 216, 216, 221, 235, 163, 49, 86, 83, 82, 78, 76,
  226, 224, 223, 224, 225, 225, 224, 223, 224, 222, 221, 221, 223, 224, 223, 222,
  221, 221, 221, 221, 222, 225, 226, 225, 223, 224, 223, 220, 219, 219, 218, 216,
  216, 217, 217, 217, 216, 214, 213, 216, 236, 171, 46, 86, 81, 80, 80, 77,
  226, 225, 223, 223, 224, 224, 222, 221, 225, 223, 222, 223, 224, 225, 223, 222,
  223, 223, 222, 220, 221, 222, 222, 221, 221, 221, 220, 216, 215, 215, 215, 214,
  215, 215, 217, 216, 214, 214, 215, 214, 233, 173, 44, 83, 81, 80, 83, 80,
  225, 223, 222, 221, 222, 221, 220, 218, 223, 222, 220, 221, 222, 222, 220, 218,
  219, 219, 218, 217, 218, 220, 221, 219, 219, 220, 219, 216, 215, 216, 216, 216,
  217, 218, 220, 218, 214, 218, 219, 214, 233, 175, 50, 84, 87, 85, 87, 85,
  224, 222, 221, 220, 221, 221, 219, 218, 219, 218, 217, 219, 221, 222, 220, 219,
  222, 223, 222, 221, 223, 226, 227, 227, 224, 226, 227, 225, 224, 223, 223, 222,
  223, 225, 227, 220, 214, 220, 222, 211, 236, 178, 60, 87, 94, 89, 87, 84,
  223, 222, 221, 221, 221, 221, 220, 219, 227, 227, 228, 231, 234, 236, 236, 235,
  236, 236, 234, 233, 233, 236, 236, 235, 232, 235, 237, 236, 233, 232, 230, 229,
  229, 231, 232, 222, 213, 220, 221, 207, 237, 178, 65, 87, 96, 87, 81, 78,
  223, 221, 224, 221, 218, 220, 231, 237, 246, 247, 244, 245, 234, 236, 226, 227,
  214, 207, 195, 183, 170, 159, 149, 144, 137, 131, 128, 132, 141, 147, 146, 143,
  132, 114, 105, 88, 104, 216, 219, 215, 228, 187, 68, 80, 76, 80, 79, 79,
  223, 226, 222, 214, 216, 233, 238, 158, 93, 104, 103, 97, 81, 73, 62, 69,
  68, 62, 58, 60, 65, 66, 60, 53, 50, 52, 56, 57, 57, 57, 56, 55,
  54, 41, 30, 25, 51, 204, 221, 211, 231, 188, 69, 81, 80, 83, 81, 82,
  216, 223, 222, 217, 217, 233, 224, 52, 18, 28, 25, 26, 27, 27, 22, 29,
  25, 28, 31, 28, 25, 25, 30, 35, 32, 32, 30, 28, 28, 29, 27, 24,
  30, 34, 36, 31, 36, 203, 230, 217, 232, 189, 70, 82, 85, 86, 83, 85,
  220, 218, 219, 218, 218, 229, 231, 44, 36, 42, 40, 41, 40, 42, 45, 44,
  40, 43, 45, 45, 44, 40, 35, 30, 23, 23, 21, 18, 18, 19, 17, 14,
  28, 26, 45, 41, 31, 188, 220, 207, 232, 190, 73, 82, 88, 86, 83, 85,
  224, 216, 222, 219, 220, 225, 234, 74, 33, 41, 43, 41, 37, 38, 46, 36,
  42, 37, 27, 17, 14, 18, 24, 27, 37, 53, 72, 83, 88, 96, 107, 116,
  77, 24, 41, 39, 52, 202, 229, 209, 231, 194, 78, 81, 88, 84, 80, 82,
  219, 217, 223, 218, 219, 219, 230, 92, 15, 43, 44, 24, 10, 7, 29, 34,
  48, 64, 81, 91, 100, 113, 128, 137, 144, 157, 176, 190, 197, 204, 220, 234,
  128, 26, 39, 35, 71, 214, 229, 205, 229, 200, 86, 82, 89, 82, 78, 79,
  220, 220, 216, 213, 212, 218, 247, 127, 16, 41, 33, 61, 155, 211, 234, 230,
  234, 234, 233, 233, 237, 244, 245, 242, 237, 236, 237, 236, 229, 222, 229, 241,
  133, 17, 40, 33, 71, 215, 220, 205, 224, 203, 93, 83, 90, 84, 82, 82,
  218, 222, 216, 223, 214, 210, 246, 130, 10, 45, 26, 57, 180, 237, 241, 232,
  223, 226, 225, 217, 212, 215, 219, 220, 214, 218, 227, 229, 217, 206, 218, 238,
  134, 17, 46, 33, 67, 216, 217, 209, 220, 204, 97, 85, 93, 87, 87, 88,
  220, 220, 219, 218, 216, 220, 242, 140, 20, 41, 27, 53, 167, 236, 212, 233,
  219, 226, 236, 231, 227, 225, 217, 215, 211, 211, 214, 193, 206, 205, 215, 244,
  136, 21, 40, 35, 64, 210, 222, 206, 219, 206, 112, 78, 87, 91, 89, 89,
  221, 220, 218, 217, 215, 219, 243, 141, 25, 36, 28, 51, 155, 228, 208, 230,
  148, 124, 126, 125, 99, 77, 71, 73, 75, 65, 60, 42, 107, 182, 231, 243,
  137, 21, 41, 36, 60, 207, 222, 208, 217, 206, 120, 82, 88, 90, 90, 91,
  221, 219, 218, 216, 214, 218, 243, 143, 28, 31, 30, 53, 145, 226, 218, 234,
  103, 46, 34, 38, 20, 16, 29, 37, 32, 28, 30, 8, 75, 185, 251, 242,
  139, 21, 41, 36, 55, 203, 222, 209, 216, 206, 130, 86, 90, 90, 90, 92,
  220, 218, 217, 216, 213, 217, 243, 145, 29, 31, 31, 57, 139, 227, 235, 231,
  56, 23, 28, 41, 37, 41, 42, 31, 41, 42, 46, 21, 48, 170, 244, 236,
  143, 20, 39, 37, 50, 202, 222, 207, 216, 204, 138, 88, 91, 91, 91, 92,
  217, 216, 217, 217, 213, 216, 243, 146, 32, 34, 29, 57, 130, 222, 243, 216,
  42, 37, 42, 37, 32, 39, 41, 39, 38, 38, 37, 23, 25, 170, 247, 236,
  150, 22, 39, 40, 47, 202, 223, 205, 217, 201, 144, 85, 91, 91, 92, 91,
  215, 214, 216, 217, 213, 216, 243, 149, 38, 32, 27, 53, 120, 220, 246, 211,
  33, 39, 44, 40, 41, 42, 36, 40, 32, 38, 34, 25, 9, 172, 246, 227,
  158, 24, 40, 43, 43, 201, 224, 205, 217, 196, 148, 83, 90, 92, 92, 90,
  214, 213, 214, 215, 212, 215, 244, 152, 50, 26, 29, 47, 112, 221, 245, 220,
  34, 34, 37, 36, 40, 40, 32, 35, 38, 41, 37, 25, 0, 162, 246, 234,
  162, 25, 40, 42, 36, 197, 224, 206, 214, 193, 153, 83, 90, 91, 92, 90,
  214, 213, 213, 214, 211, 215, 245, 154, 63, 23, 33, 44, 105, 221, 238, 228,
  30, 33, 42, 39, 35, 39, 38, 40, 36, 34, 37, 31, 2, 155, 240, 231,
  162, 25, 39, 40, 30, 191, 222, 206, 212, 191, 157, 84, 90, 90, 92, 90,
  213, 210, 213, 216, 212, 216, 238, 162, 71, 23, 31, 37, 92, 222, 239, 226,
  31, 37, 38, 37, 39, 39, 35, 39, 35, 37, 38, 24, 3, 146, 239, 233,
  171, 18, 34, 41, 24, 179, 229, 201, 211, 180, 172, 88, 88, 89, 90, 91,
  213, 211, 213, 215, 210, 213, 235, 168, 77, 22, 32, 35, 89, 221, 234, 228,
  41, 31, 38, 40, 41, 36, 33, 38, 40, 36, 42, 33, 4, 147, 240, 226,
  168, 22, 37, 38, 25, 181, 228, 203, 209, 188, 178, 88, 89, 90, 91, 92,
  211, 210, 213, 213, 208, 211, 232, 181, 88, 22, 36, 33, 82, 219, 226, 231,
  55, 31, 45, 38, 37, 39, 43, 46, 34, 30, 36, 28, 0, 149, 244, 227,
  167, 26, 39, 36, 24, 180, 225, 203, 205, 197, 184, 85, 88, 91, 91, 93,
  209, 209, 213, 212, 207, 210, 229, 199, 99, 23, 41, 34, 73, 215, 219, 234,
  77, 24, 36, 34, 38, 33, 25, 17, 20, 22, 22, 14, 0, 142, 235, 232,
  173, 25, 35, 38, 21, 172, 222, 202, 200, 204, 185, 82, 87, 92, 91, 91,
  206, 208, 211, 210, 205, 207, 223, 212, 108, 22, 45, 35, 62, 209, 214, 232,
  51, 6, 39, 58, 68, 65, 75, 91, 96, 105, 110, 111, 95, 175, 220, 225,
  182, 26, 29, 43, 20, 157, 220, 206, 197, 206, 185, 80, 89, 93, 93, 90,
  206, 207, 210, 208, 204, 204, 214, 221, 115, 20, 44, 36, 52, 204, 212, 225,
  187, 187, 231, 241, 238, 232, 234, 239, 237, 239, 241, 244, 221, 223, 217, 228,
  189, 39, 25, 43, 21, 139, 212, 213, 197, 207, 186, 84, 91, 92, 94, 91,
  206, 208, 211, 208, 205, 203, 209, 228, 122, 19, 42, 38, 47, 203, 215, 216,
  222, 221, 220, 203, 202, 212, 208, 199, 208, 203, 206, 212, 213, 209, 211, 233,
  191, 63, 25, 38, 20, 118, 195, 216, 197, 206, 187, 90, 92, 88, 94, 93,
  206, 208, 211, 209, 207, 205, 208, 234, 127, 20, 41, 41, 46, 205, 219, 210,
  209, 216, 219, 220, 219, 215, 213, 222, 216, 216, 225, 224, 228, 224, 221, 227,
  190, 81, 27, 31, 19, 103, 179, 215, 196, 204, 188, 93, 91, 84, 93, 94,
  205, 210, 208, 212, 209, 199, 211, 233, 137, 16, 37, 42, 47, 203, 248, 228,
  225, 211, 192, 178, 175, 177, 177, 173, 162, 143, 123, 111, 102, 96, 101, 111,
  91, 45, 35, 34, 21, 100, 171, 226, 194, 198, 200, 99, 91, 93, 93, 90,
  206, 206, 205, 207, 207, 203, 213, 239, 141, 18, 41, 45, 53, 118, 109, 101,
  87, 80, 71, 64, 64, 65, 63, 59, 59, 50, 43, 40, 35, 31, 32, 37,
  29, 31, 42, 40, 13, 67, 171, 231, 196, 199, 202, 101, 91, 93, 93, 90,
  206, 202, 206, 204, 205, 206, 212, 241, 140, 22, 52, 33, 23, 28, 15, 27,
  24, 25, 26, 27, 30, 33, 33, 31, 34, 33, 34, 34, 33, 32, 33, 35,
  40, 39, 34, 36, 14, 36, 168, 234, 195, 197, 204, 102, 90, 94, 93, 91,
  205, 201, 210, 205, 205, 207, 207, 237, 139, 9, 44, 42, 38, 39, 30, 21,
  21, 22, 21, 19, 17, 17, 17, 18, 12, 17, 21, 22, 22, 23, 23, 24,
  17, 18, 15, 22, 19, 26, 154, 209, 193, 193, 205, 102, 88, 93, 93, 92,
  205, 203, 212, 204, 202, 203, 203, 232, 137, 14, 26, 24, 11, 22, 38, 46,
  58, 63, 70, 79, 87, 97, 108, 115, 120, 128, 137, 140, 141, 141, 139, 136,
  141, 147, 156, 154, 163, 156, 212, 210, 193, 192, 208, 105, 87, 94, 93, 92,
  205, 204, 208, 202, 200, 200, 203, 229, 117, 63, 73, 87, 104, 132, 139, 142,
  145, 150, 160, 174, 186, 198, 209, 217, 227, 230, 234, 235, 235, 236, 235, 235,
  239, 229, 230, 223, 231, 214, 213, 186, 197, 193, 214, 109, 87, 94, 93, 92,
  203, 204, 202, 201, 202, 198, 203, 221, 216, 232, 241, 236, 232, 237, 236, 237,
  230, 227, 225, 224, 220, 214, 210, 208, 205, 203, 200, 199, 199, 199, 201, 204,
  200, 193, 197, 197, 199, 191, 196, 199, 198, 193, 217, 111, 86, 95, 92, 92,
  201, 204, 199, 202, 206, 199, 202, 213, 204, 214, 210, 212, 210, 205, 206, 203,
  203, 201, 200, 203, 204, 202, 199, 198, 199, 197, 197, 200, 200, 198, 198, 199,
  195, 198, 196, 195, 196, 199, 197, 193, 196, 191, 217, 111, 85, 95, 92, 92,
  203, 202, 202, 202, 202, 201, 202, 205, 201, 202, 204, 205, 203, 200, 199, 201,
  201, 200, 201, 203, 203, 201, 199, 198, 197, 196, 197, 199, 201, 200, 199, 200,
  200, 198, 197, 197, 197, 196, 195, 195, 198, 191, 212, 115, 82, 98, 91, 92,
  203, 203, 202, 203, 202, 201, 202, 205, 201, 201, 202, 203, 201, 198, 199, 201,
  201, 199, 199, 201, 201, 200, 199, 200, 200, 198, 198, 200, 201, 200, 199, 199,
  200, 198, 196, 197, 197, 195, 193, 194, 197, 189, 214, 114, 84, 94, 93, 92,
  204, 203, 202, 203, 202, 200, 201, 203, 203, 203, 203, 203, 201, 199, 200, 202,
  203, 201, 200, 200, 201, 201, 201, 203, 201, 199, 199, 200, 200, 198, 197, 197,
  200, 198, 197, 197, 196, 194, 193, 193, 196, 187, 216, 117, 85, 91, 93, 92,
  203, 202, 201, 202, 201, 200, 200, 201, 203, 202, 203, 203, 202, 200, 200, 201,
  203, 201, 199, 200, 200, 200, 201, 202, 200, 199, 198, 199, 199, 196, 195, 195,
  200, 198, 197, 198, 197, 195, 193, 193, 193, 188, 213, 124, 83, 91, 92, 92,
  202, 200, 199, 200, 200, 198, 198, 199, 199, 199, 200, 201, 200, 198, 197, 198,
  201, 199, 198, 199, 199, 198, 197, 198, 199, 197, 197, 198, 198, 196, 195, 195,
  200, 198, 198, 199, 199, 196, 195, 195, 191, 190, 209, 133, 79, 94, 90, 92,
  200, 198, 198, 199, 199, 198, 197, 198, 198, 198, 199, 201, 201, 199, 197, 198,
  202, 200, 199, 200, 200, 198, 197, 198, 199, 197, 197, 199, 199, 197, 196, 196,
  198, 197, 197, 198, 198, 196, 194, 194, 190, 191, 205, 140, 77, 96, 90, 92,
  199, 197, 197, 199, 200, 198, 198, 198, 200, 199, 199, 201, 202, 200, 199, 200,
  202, 200, 199, 200, 200, 199, 198, 199, 198, 196, 196, 198, 199, 197, 196, 196,
  197, 195, 195, 197, 196, 194, 192, 191, 191, 190, 206, 142, 80, 95, 92, 91,
  199, 197, 197, 199, 200, 199, 198, 198, 199, 197, 197, 199, 200, 199, 199, 200,
  200, 197, 195, 196, 196, 196, 196, 198, 197, 195, 195, 197, 197, 196, 195, 195,
  196, 194, 194, 195, 195, 192, 189, 189, 192, 189, 207, 141, 84, 93, 94, 90 };
