#include "Time.h"

#include <ctime>
#include <iostream>
#include <iomanip>

Time::Time() {
    time_t now = time(0);
    tm *ltm = localtime(&now);
    this->hours = ltm->tm_hour;
    this->minutes = ltm->tm_min;
}

Time::Time(unsigned int hours, unsigned int minutes) {
    this->hours = hours;
    this->minutes = minutes;
}

Time::Time(const Time &time) {
    this->hours = time.getHours();
    this->minutes = time.getMinutes();
}

Time::Time(const std::string &time) {
    std::istringstream ss{time};
    unsigned horas, minutos;
    char separator;
    if(time.length() == 5){
        ss >> horas >> separator >> minutos;
        if (horas > 23 || minutos > 59) {
            throw InvalidTime(time);
        }
    }
    else{
        throw InvalidTime(time);
    }
    ss.ignore(100, '\n');
    ss.clear();
    this->hours = horas;
    this->minutes = minutos;
}

unsigned Time::getHours() const {
    return this->hours;
}

unsigned Time::getMinutes() const {
    return this->minutes;
}

void Time::setHours(unsigned int hours) {
    this->hours = hours;
}

void Time::setMinutes(unsigned int minutes) {
    this->minutes = minutes;
}

std::string Time::toString() const {
    std::stringstream ss;
    std::string horas = std::to_string(hours);
    std::string minutos = std::to_string(minutes);
    ss << std::setfill('0') << std::setw(2) << horas << ":" << std::setw(2) << minutos;
    return ss.str();
}

Time Time::operator+(const Time &t) {
    Time time;
    time.setMinutes((this->minutes + t.getMinutes()) % 60);
    time.setHours((((this->minutes + t.getMinutes()) / 60) +  this->hours + t.getHours()) % 24);
    return time;
}



