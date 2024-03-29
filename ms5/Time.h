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
        //Time represented in minutes to be converted to HH:MM
        unsigned int m_minutes;
    public:
        Time(unsigned int min = 0u);
        //Sets time to system time
        Time& reset();
        //Write time in HH:MM format
        void write(std::ostream& os) const;
        //Read time in HH:MM format
        void read(std::istream& is);
        //Returns minutes upon being casted to unsigned int
        operator unsigned int() const;
        //Multiplies and assigns current objects minutes by value passed in
        Time& operator*=(int val);
        //Subtracts and assigns current objects minutes by another time objects minutes
        Time& operator-=(const Time& D);
        //Returns a seperate object after subtracting minutes
        Time operator-(const Time& T) const;
    };
    //Helper functions
    std::ostream& operator<<(std::ostream& os, const Time& t);
    std::istream& operator>>(std::istream& is, Time& t);

}
#endif 