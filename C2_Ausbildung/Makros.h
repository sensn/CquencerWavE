#pragma once
#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable:4996)


#define _CRT_RAND_S   // for rand_s

#define ABS(x) (((x)<0)? ((x)*(-1)):(x))

#define SWAPVAR(a, b, typ) {typ temp; temp=b; b=a;a=temp; }

#define MAX(a, b) ((a) < (b) ? (b) : (a))
#define MIN(a, b) ((a) > (b) ? (b) : (a))
#define PI 3.141596
#define NUMBITS 16

// The function getrandom returns a random number between
// min and max, which must be in integer range.
#define getrandom( min, max ) (SHORT)((rand() % (int)(((max) + 1) - \(min))) + (min))
