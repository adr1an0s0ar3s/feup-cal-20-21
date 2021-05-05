#ifndef MARKET_ON_WHEELS_TIME_H
#define MARKET_ON_WHEELS_TIME_H

#include <string>

class Time {
    unsigned hours;
    unsigned minutes;
public:
    Time();

    Time(unsigned hours, unsigned minutes);

    Time(const Time &time);

    Time(const std::string &time);

    unsigned getHours() const;

    unsigned getMinutes() const;

    void setHours(unsigned hours);

    void setMinutes(unsigned minutes);

    std::string toString() const;

    Time operator+(const Time &t);
};

class InvalidTime : public std::exception {
    std::string time;
public:
    InvalidTime(const std::string &date) : time(time) {}
    std::string getTime() const { return time; };
};

#endif //MARKET_ON_WHEELS_TIME_H
