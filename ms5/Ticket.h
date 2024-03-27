/* Citation and Sources...
Final Project Milestone 5
Module: Ticket
Filename: Ticket.h
Version 1.0
Student Name: Joon Dong
Student ID:	036262152
Student Email: thdong1@myseneca.ca
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------
*/
#ifndef SENECA_TICKET_H_
#define SENECA_TICKET_H_
#include <iostream>
#include "Time.h"
#include "IOAble.h"
namespace seneca {
    //Concrete class that inherits an IOAble
    class Ticket :public IOAble {
        //Time ticket is issues
        Time m_time;
        //Ticket number given to a patient, sequential
        int m_number;
    public:
        Ticket(int number);
        Time time()const;
        int number()const;
        void resetTime();
        std::ostream& write(std::ostream& ostr)const;
        std::istream& read(std::istream& istr);
    };
}
#endif // !SENECA_TICKET_H_
