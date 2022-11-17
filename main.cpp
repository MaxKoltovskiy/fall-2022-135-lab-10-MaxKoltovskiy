#include <iostream>
#include "time.h"
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


    
}