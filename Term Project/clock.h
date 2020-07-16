
// ***** DO NOT CHANGE OR ADD ANY CODE IN THIS FILE *****
// Don't include time.h when using this module.

// Use this on Windows to get a better version of the clock() library function.
// Compile your code together with clock.c

#define CLOCKS_PER_SEC 1000000

typedef long long int clock_t;

clock_t clock(void);

