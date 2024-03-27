/* Citation and Sources...
Final Project Milestone 5
Module: TestPatient
Filename: TestPatient.cpp
Version 1.0
Student Name: Joon Dong
Student ID:	036262152
Student Email: thdong1@myseneca.ca
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------
*/
#include "TestPatient.h"
namespace seneca {

	int nextTestTicket = 1;

	TestPatient::TestPatient() :
	Patient(nextTestTicket){
		nextTestTicket++;
	}
	char TestPatient::type() const{
		return 'C';
	}
	std::ostream& TestPatient::write(std::ostream& ostr) const {
		if (&ostr == &std::cout) {
			ostr << "Contagion TEST" << std::endl;
		}
		Patient::write(ostr);
		return ostr;
	}
	std::istream& TestPatient::read(std::istream& istr) {
		Patient::read(istr);
		if (&istr != &std::cin) {
			nextTestTicket = number() + 1;
		}
		return istr;
	}

}