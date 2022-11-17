#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "time.h"
#include "funcs.h"

bool compareTimes(Time time1, Time time2) {
    if(time1.h == time2.h && time1.m == time2.m) {
        return true;
    }
    return false;
}
TEST_CASE("Minutes Since Midnight"){
    Time time = {10,30};
    CHECK(minutesSinceMidnight(time) == 630);
}
TEST_CASE("Minutes Until"){
    Time earlier = {10,30};
    Time later = {13,40};
    CHECK(minutesUntil(earlier, later) == 190);
    CHECK(minutesUntil(later, earlier) == -190);
}
TEST_CASE("Add Minutes"){
    CHECK(compareTimes(addMinutes({8, 10}, 75), {9,25} ));
}