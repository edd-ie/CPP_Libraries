//
// Created by _edd.ie_ on 25/05/2024.
//

#ifndef CURRENTTIME_H
#define CURRENTTIME_H
#include <ctime>
#include <iostream>

inline void currentTime()
{
    const long long epoch = time(nullptr);
    const int sec = epoch%60;
    const int min = (epoch/60)%60;
    const int hr = (epoch/3600)%24;

    std::cout << "Current time : " <<
        hr << ":" << min << ":" << sec << " GMT" << std::endl;
}

#endif //CURRENTTIME_H
