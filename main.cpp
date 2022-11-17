#include <iostream>
#include "funcs.h"

int main() 
{
    Time time = {9,45};
    std::cout<< minutesSinceMidnight(time)<< " minutes since midnight at "<< time.h<< ":"<< time.m<< "\n";

    std::cout<< "\n-----------------------------------------\n";

    Time later = {16,50};
    std::cout<< minutesUntil(time,later)<< " minutes from "<< time.h<< ":"<< time.m<< " until "<< later.h<< ":"<< later.m<< "\n";

    std::cout<< "\n-----------------------------------------\n";

}