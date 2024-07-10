#include <chrono>
#include <ctime>
#include <iostream>

int main() {
    int leapseconds = 18;
    // In order to calculate day number & time of week, use std::gmtime() using UTC clock (origin is 1960-01-01)
    auto now = std::chrono::system_clock::now() + std::chrono::seconds(leapseconds); // because of leap seconds
    auto now_c = std::chrono::system_clock::to_time_t(now); 
    std::tm* utc_tm = std::gmtime(&now_c);    
    int day_number = utc_tm->tm_wday;
    double seconds = std::chrono::duration_cast<std::chrono::duration<double>>(now.time_since_epoch() % std::chrono::hours(24)).count();
    double tow = 86400.0 * day_number + seconds;

    // calculate Week Number, Roll Over
    const std::chrono::system_clock::time_point GPS_EPOCH = std::chrono::system_clock::from_time_t(315964800); // from 1980-01-06 00:00:00
    auto gps_duration = now - GPS_EPOCH; 
    auto elapsed_day = std::chrono::duration_cast<std::chrono::duration<float, std::ratio<86400>>>(gps_duration).count();
    int rollover = elapsed_day / 7 / 1024;
    int weeknum = elapsed_day / 7 - rollover * 1024;
    
    std::cout << std::fixed << "TOW[s]: " << tow << "\n"
              << "DAY: "    << day_number << "\n"
              << "WeekNum: " << weeknum << "\n"
              << "RollOver: " << rollover << std::endl;

    return 0;
}