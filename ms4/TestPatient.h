/* Citation and Sources...
Final Project Milestone 4
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

	class TestPatient : public Patient {
	public:
		TestPatient();
		char type() const;
		std::ostream& write(std::ostream& ostr) const;
		std::istream& read(std::istream& istr);

	};
}
#endif