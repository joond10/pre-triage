/* Citation and Sources...
Final Project Milestone 3
Module: Patient
Filename: Patient.h
Version 1.0
Student Name: Joon Dong
Student ID:	036262152
Student Email: thdong1@myseneca.ca
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------
*/
#ifndef SENECA_PATIENT_H
#define SENECA_PATIENT_H
#include "IOAble.h"
#include "Ticket.h"
namespace seneca {
	//Abstract base class that inherits an IOAble
	class Patient : public IOAble {
		char* m_name = nullptr;
		int m_ohip{};
		Ticket m_ticket;
	public:
		Patient(int ticketNum);
		void setMembers(const Patient& other);
		Patient& operator=(const Patient& other);
		Patient(const Patient& other);
		~Patient();
	//Methods:
		//Pure virtual to be implemented later
		virtual char type() const = 0;
		bool operator==(char rhs) const;
		bool operator==(const Patient& otherPatient) const;
		void setArrivalTime();
		Time time() const;
		int number() const;
	//Cast Overloads:
		operator bool() const;
		operator const char* () const;
	//Overrides:
		std::ostream& write(std::ostream& ostr) const;
		std::istream& read(std::istream& istr);
	};
}
#endif // !SENECA_PATIENT_H