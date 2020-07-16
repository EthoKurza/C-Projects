#include <windows.h>
#include "clock.h"

// ***** DO NOT CHANGE OR ADD ANY CODE IN THIS FILE *****
// Don't include time.h when using this module.

// Returns a time counter value that increases by CLOCKS_PER_SEC every second.
// The intent here is to have more timing resolution than the default Cygwin
// implementation of clock() which has 15 ms resolution. In practice this
// implementation gets microsecond resolution. Works only on Windows. On Mac
// and Linux you should use the existing system library version of clock().
// See the project instructions for an example of how to use this function.  
// Note: LARGE_INTEGER is equivalent to a 64-bit integer (long long int).
// Return value of 0 means an error occurred.
clock_t clock(void) {
    static LARGE_INTEGER freq;
    LARGE_INTEGER count;

    if (freq.QuadPart == 0) {                   // one time initialization
        if (!QueryPerformanceFrequency(&freq)) {
            return 0;
        }
    }

    if (!QueryPerformanceCounter(&count)) {
        return 0;
    }
    return (double)count.QuadPart / freq.QuadPart * CLOCKS_PER_SEC;
}
