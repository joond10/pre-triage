/* Citation and Sources...
Final Project Milestone 5
Module: IOAble
Filename: IOAble.cpp
Version 1.0
Student Name: Joon Dong
Student ID:	036262152
Student Email: thdong1@myseneca.ca
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------
*/
#include "IOAble.h"
namespace seneca {
	std::ostream& operator<<(std::ostream& ostr, const IOAble& ioable) {
		ioable.write(ostr);
		return ostr;
	}
	std::istream& operator>>(std::istream& istr, IOAble& ioable) {
		ioable.read(istr);
		return istr;
	}
}