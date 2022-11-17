#pragma once

int minutesSinceMidnight(Time time);
int minutesUntil(Time earlier, Time later);

Time addMinutes(Time time0, int min);

std::string getMovie(Movie mv);
std::string getTimeSlot(TimeSlot ts);

TimeSlot scheduleAfter(TimeSlot ts, Movie nextMovie);