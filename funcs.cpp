#include "time.h"
#include "movie.h"
#include "timeslot.h"
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

std::string getMovie(Movie mv) {
    std::string g;
    switch (mv.genre) {
        case ACTION   : g = "ACTION"; break;
        case COMEDY   : g = "COMEDY"; break;
        case DRAMA    : g = "DRAMA";  break;
        case ROMANCE  : g = "ROMANCE"; break;
        case THRILLER : g = "THRILLER"; break;
    }

    return mv.title + " " + g + " (" + std::to_string(mv.duration) + " min)";
}

std::string getTimeSlot(TimeSlot ts) {
    std::string result = getMovie(ts.movie);
    Time end_time = addMinutes(ts.startTime, ts.movie.duration);
    result += " [starts at " + std::to_string(ts.startTime.h) + ":" + std::to_string(ts.startTime.m);
    result += ", ends at " + std::to_string(end_time.h) + ":" + std::to_string(end_time.m) + "]";

    return result;
}