#include <iostream>
#include "time.h"
#include "movie.h"
#include "timeslot.h"
#include "funcs.h"

int main() 
{
    Time time = {9,45};
    std::cout<< minutesSinceMidnight(time)<< " minutes since midnight at "<< time.h<< ":"<< time.m<< "\n";

    std::cout<< "\n-----------------------------------------\n";

    Time later = {16,50};
    std::cout<< minutesUntil(time,later)<< " minutes from "<< time.h<< ":"<< time.m<< " until "<< later.h<< ":"<< later.m<< "\n";

    std::cout<< "\n-----------------------------------------\n";

    Time time0 = {8, 30};
    int add_mins = 140;
    Time time1 = addMinutes(time0, add_mins);

    std::cout<< time1.h<< ":"<< time1.m<< " is "<< add_mins<< " minutes after "<< time0.h<< ":"<< time0.m<< "\n";

    std::cout<< "\n-----------------------------------------\n";

    Movie movie3 = {"Deadpool", ACTION, 108};
    Movie movie4 = {"Joker",THRILLER, 122};

    TimeSlot afternoon = {movie3, {13, 45}};
    TimeSlot night = {movie4, {1, 15}};

    std::cout<< getTimeSlot(afternoon)<< "\n";
    std::cout<< getTimeSlot(night)<< "\n";
    
    std::cout<< "\n-----------------------------------------\n";
    
    TimeSlot before = {{"Venom", ACTION, 112}, {14, 30}};
    Movie next = {"Split", THRILLER, 117};
    TimeSlot after = scheduleAfter(before, next);

    std::cout<< "First: "<< getTimeSlot(before) << "\n";
    std::cout<< "After: "<< getTimeSlot(after) << "\n";
    
    std::cout<< "\n-----------------------------------------\n";



}