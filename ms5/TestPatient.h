/* Citation and Sources...
Final Project Milestone 5
Module: TestPatient
Filename: TestPatient.h
Version 1.0
Student Name: Joon Dong
Student ID:	036262152
Student Email: thdong1@myseneca.ca
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------
*/
#ifndef SENECA_TEST_PATIENT_H
#define SENECA_TEST_PATIENT_H
#include "Patient.h"
namespace seneca {
	extern int nextTestTicket;
	//Contagion test patient that overrides with a concrete implementation
	class TestPatient : public Patient {
	public:
		TestPatient();
		//Returns the appropriate identifier for the type of patient (contagion)
		char type() const;
		//Overrides the write function and adds contagion label
		std::ostream& write(std::ostream& ostr) const;
		//Overrides the read function and increments the ticket number
		std::istream& read(std::istream& istr);

	};
}
#endif