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

Time addMinutes(Time time0, int mins) {
    Time time1 = time0;
    time1.m += mins;

    while(time1.m >= 60) {
        time1.m -= 60;
        time1.h++;
    }

    return time1;
}