#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "time.h"
#include "funcs.h"

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