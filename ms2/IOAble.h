/* Citation and Sources...
Final Project Milestone 2
Module: IOAble
Filename: IOAble.h
Version 1.0
Student Name: Joon Dong
Student ID:	036262152
Student Email: thdong1@myseneca.ca
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------
*/
#ifndef SENECA_IOABLE_H
#define SENECA_IOABLE_H
#include <iostream>
namespace seneca {
	//Interface
	class IOAble {
	public:
		virtual ~IOAble() = default;
		virtual std::ostream& write(std::ostream& ostr) const = 0;
		virtual std::istream& read(std::istream& istr) = 0;
	};
	std::ostream& operator<<(std::ostream& ostr, const IOAble& ioable);
	std::istream& operator>>(std::istream& istr, IOAble& ioable);
}
#endif // !SENECA_IOABLE_H