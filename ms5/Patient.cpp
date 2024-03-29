/* Citation and Sources...
Final Project Milestone 5
Module: Patient
Filename: Patient.cpp
Version 1.0
Student Name: Joon Dong
Student ID:	036262152
Student Email: thdong1@myseneca.ca
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------
*/
#define _CRT_SECURE_NO_WARNINGS
#include "Patient.h"
namespace seneca {
	Patient::Patient(int ticketNum) :
		m_ticket(ticketNum), m_name(nullptr), m_ohip(0) {
	}

	//Localization technique for the rule of three
	void Patient::setMembers(const Patient& other) {
		if (other.m_name) {
			m_name = new char[50 + 1];
			strncpy(m_name, other.m_name, 50);
			m_ohip = other.m_ohip;
			m_ticket = other.m_ticket;
		}
		else {
			m_name = nullptr;
		}
	}
	Patient& Patient::operator=(const Patient& other) {
		if (this != &other) {
			delete[] m_name;
			setMembers(other);
		}
		return *this;
	}
	Patient::Patient(const Patient& other) : m_ticket(other.m_ticket) { 
		setMembers(other);
	}
	Patient::~Patient() {
		delete[] m_name;
	}

	//Compares the patient with a single character (type)
	bool Patient::operator==(char rhs) const {
		return (type() == rhs);
	}

	//Compares the current patient to another patient (type)
	bool Patient::operator==(const Patient& otherPatient) const {
		return (type() == otherPatient.type());
	}
	
	//Modifier that sets the patient's ticket to current time
	void Patient::setArrivalTime() {
		m_ticket.resetTime();
	}

	//Query that returns the time of the patient's ticket
	Time Patient::time() const {
		return m_ticket.time();
	}

	//Query that returns the number associated with patient's ticket
	int Patient::number() const {
		return m_ticket.number();
	}
	
	//Returns true if the patient is in a valid state
	Patient::operator bool() const {
		return (m_ticket.number() != 0);
	}

	//Returns the address of the patient's name
	Patient::operator const char* () const {
		return m_name;
	}
	//Overrides base class version to write to different ostreams
	std::ostream& Patient::write(std::ostream& ostr) const {
		//Multi-line format
		if (&ostr == &std::cout) {
			if (m_ticket.number() != 0) {
				ostr << "Ticket No: " << m_ticket.number() << ", Issued at: " << m_ticket.time() << std::endl;
				ostr << m_name << ", OHIP: " << m_ohip << std::endl;
			}
			else {
				ostr << "Invalid Patient Record" << std::endl;
			}

		}
		//List format
		else if (&ostr == &std::clog) {
			if (m_ticket.number() != 0) {
				ostr.width(53);
				ostr.setf(std::ios::left);
				ostr.fill('.');
				ostr << m_name << m_ohip;
				ostr.width(5);
				ostr.unsetf(std::ios::left);
				ostr.setf(std::ios::right);
				ostr.fill(' ');
				ostr << m_ticket.number();
				ostr << " " << m_ticket.time();
				ostr.unsetf(std::ios::right);

			}
			else {
				ostr << "Invalid Patient Record" << std::endl;
			}
		}
		//File format
		else {
			ostr << type() << "," << m_name << "," << m_ohip << ",";
			m_ticket.write(ostr);
		}
		return ostr;
	}
	//Overrides base class version to read from different istream
	std::istream& Patient::read(std::istream& istr) {
		char patientName[51];
		//Read into console
		if (&istr == &std::cin) {
			std::cout << "Name: ";
			istr.getline(patientName, 51, '\n');
			if (m_name) {
				delete[] m_name;
			}
			m_name = new char[strlen(patientName) + 1];
			strcpy(m_name, patientName);
			std::cout << "OHIP: ";
			m_ohip = U.getInt(100000000, 999999999);
		}
		//Read into file
		else {
			//If it's more than 50 characters, the comma is left in the buffer
			istr.getline(patientName, 51, ',');
			if (istr.fail()) {
				istr.clear();
			}
			if (m_name) {
				delete[] m_name;
			}
			m_name = new char[strlen(patientName) + 1];
			strcpy(m_name, patientName);
			//Meaning, if the name is 50 characters, we need to discard the comma
			if (strlen(m_name) == 50) {
				istr.ignore(1000, ',');
			}
			istr >> m_ohip;
			//Discard comma after reading ohip
			istr.ignore();
			m_ticket.read(istr);
		}
		return istr;
	}
}

