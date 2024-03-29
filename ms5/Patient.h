/* Citation and Sources...
Final Project Milestone 5
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
		//Holds main attributes of a patient to be derived
		char* m_name;
		int m_ohip;
		Ticket m_ticket;
	public:
		//Parameterized constructor
		Patient(int ticketNum);
		//Localization technique for the rule of three
		void setMembers(const Patient& other);
		Patient& operator=(const Patient& other);
		Patient(const Patient& other);
		~Patient();
	//Methods:
		//Pure virtual to be implemented later, identifies the type of patient
		virtual char type() const = 0;
		//Compares the patient with a single character (type)
		bool operator==(char rhs) const;
		//Compares the current patient to another patient (type)
		bool operator==(const Patient& otherPatient) const;
		//Modifier that sets the patient's ticket to current time
		void setArrivalTime();
		//Query that returns the time of the patient's ticket
		Time time() const;
		//Query that returns the number associated with patient's ticket
		int number() const;
	//Cast Overloads:
		//Returns true if the patient is in a valid state
		operator bool() const;
		//Returns the address of the patient's name
		operator const char* () const;
	//Overrides:
		//Overrides base class version to write to different ostreams
		std::ostream& write(std::ostream& ostr) const;
		//Overrides base class version to read from different istream
		std::istream& read(std::istream& istr);
	};
}
#endif // !SENECA_PATIENT_H