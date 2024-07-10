# gps_time_cpp11
Output gps date without using c++20 chrono library (chrono::gps_clock). Fully operational under c++11


# Disclaimer
Leap seconds is hard coded. (18s) 


# Output
The output contains:
TOW[s] : Time of weekends
Day : Day number (0: Sunday)
WN : Week Number 
RO : Roll Over (1 Roll Over = 1024 weeks)