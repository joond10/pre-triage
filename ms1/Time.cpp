/* Citation and Sources...
Final Project Milestone 1
Module: Time
Filename: Time.cpp
Version 1.0
Student Name: Joon Dong
Student ID:	036262152
Student Email: thdong1@myseneca.ca
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------
*/
#include "Time.h"
namespace seneca {
    //Parametized constructor
    Time::Time(unsigned int min) {
        m_minutes = min;
    }
    //Sets time to system time
    Time& Time::reset() {
        m_minutes = U.getTime();
        return *this;
    }
    //Write to console function
    void Time::write(std::ostream& os) const {

        int hour = m_minutes / 60;
        int min = m_minutes % 60;
        
        if (hour < 10 || min < 10) {
            os.width(2);
            os.fill('0');
            os << hour;
            os << ":";
            os.width(2);
            os.fill('0');
            os << min;
        }
        else {
            os << hour << ":" << min;
        }
    }
    //Read valid hh:mm time format
    void Time::read(std::istream& is) {
        int hours, minutes;

        //Read hours
        is >> hours;
        //If colon doesn't appear after hours
        if(is.peek() != ':'){
            //Set fail state
            is.setstate(std::ios::failbit);
            //Discard the colon
            is.ignore();
        }
        else {
            //Discard the colon
            is.ignore();
            //Read the minutes portion
            is >> minutes;
            m_minutes = hours * 60 + minutes;
        }
    }
    //Returns minutes upon being casted to unsigned int
    Time::operator unsigned int() const {
        return m_minutes;
    }
    //Multiplies and assigns minutes by val
    Time& Time::operator*=(int val) {

        m_minutes *= val;

        return *this;
    }
    //Modifies current object with other object time deduction
    Time& Time::operator-=(const Time& D) {
        int totalMin = m_minutes - D.m_minutes;
        if (totalMin < 0) {
            totalMin += 1440; 
        }
        m_minutes = totalMin;
        return *this;
    }
    //Returns a new seperate object instead
    Time Time::operator-(const Time& T) const {
        Time newTime;
        if (m_minutes >= T.m_minutes) {
            newTime.m_minutes = m_minutes - T.m_minutes;
        }
        else {
            newTime.m_minutes = m_minutes + 1440 - T.m_minutes;
        }
        return newTime;
    }
    //Utilizes our write function
    std::ostream& operator<<(std::ostream& os, const Time& t) {
        t.write(os);
        return os;
    }
    //Utilizes our read function
    std::istream& operator>>(std::istream& is, Time& t) {
        t.read(is);
        return is;
    }
}