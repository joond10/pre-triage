/* Citation and Sources...
Final Project Milestone 5
Module: Time
Filename: Time.h
Version 1.0
Student Name: Joon Dong
Student ID:	036262152
Student Email: thdong1@myseneca.ca
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------
*/
#ifndef SENECA_TIME_H
#define SENECA_TIME_H
#include <iostream>
#include "Utils.h"
namespace seneca {
    class Time {
        unsigned int m_minutes;
    public:
        Time(unsigned int min = 0u);
        Time& reset();
        void write(std::ostream& os) const;
        void read(std::istream& is);
        operator unsigned int() const;
        Time& operator*=(int val);
        Time& operator-=(const Time& D);
        Time operator-(const Time& T) const;
    };
    //Helper functions
    std::ostream& operator<<(std::ostream& os, const Time& t);
    std::istream& operator>>(std::istream& is, Time& t);

}
#endif 