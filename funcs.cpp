#include "time.h"
#include "funcs.h"

int minutesSinceMidnight(Time time) {
    int minsSinceMidnight = 0;
    minsSinceMidnight += (time.h *60);
    minsSinceMidnight += time.m;

    return minsSinceMidnight;
}

int minutesUntil(Time earlier, Time later) {
    return (minutesSinceMidnight(later) - minutesSinceMidnight(earlier));
}