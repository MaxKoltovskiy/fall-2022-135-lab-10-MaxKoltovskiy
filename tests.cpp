#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "time.h"
#include "movie.h"
#include "timeslot.h"
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
TEST_CASE("Get Movie"){
    Movie movie1 = {"Back to the Future", COMEDY, 116};
    CHECK(getMovie(movie1) == "Back to the Future COMEDY (116 min)");
}
TEST_CASE("Get TimeSlot"){
    Movie movie1 = {"Back to the Future", COMEDY, 116};
    Movie movie2 = {"Black Panther", ACTION, 134};
    TimeSlot morning = {movie1, {9, 15}};  
    TimeSlot daytime = {movie2, {12, 15}};  
    
    CHECK(getTimeSlot(morning).compare("Back to the Future COMEDY (116 min) [starts at 9:15, ends by 11:11]") == 0);
    CHECK(getTimeSlot(daytime).compare("Black Panther ACTION (134 min) [starts at 12:15, ends by 14:29]") == 0);
}
TEST_CASE("Schedule After"){
    Movie nextmovie = {"Something", THRILLER, 100};
    TimeSlot ts = {{"Other", COMEDY, 120}, {14, 10}};

    TimeSlot correct = {nextmovie, {16, 10}};
    TimeSlot result = scheduleAfter(ts, nextmovie);
    CHECK(getTimeSlot(correct).compare(getTimeSlot(result)) == 0);
}
TEST_CASE("Time Overlap"){
    TimeSlot ts = {{"X", COMEDY, 90}, {10, 0}};
    TimeSlot no_overlap = {{"Y", DRAMA, 100}, {11, 30}};
    TimeSlot overlap = {{"Z", ROMANCE, 80}, {11, 29}};

    CHECK(timeOverlap(ts, no_overlap) == false);
    CHECK(timeOverlap(ts, overlap) == true);
    CHECK(timeOverlap(overlap, ts) == true);
}