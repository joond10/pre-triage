/* Citation and Sources...
Final Project Milestone 5
Module: TriagePatient
Filename: TriagePatient.cpp
Version 1.0
Student Name: Joon Dong
Student ID:	036262152
Student Email: thdong1@myseneca.ca
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------
*/
#include "TriagePatient.h"
namespace seneca {
	int nextTriageTicket = 1;

	TriagePatient::TriagePatient() :
	Patient(nextTriageTicket){
		nextTriageTicket++;
		m_symptoms = nullptr;
	}
	char TriagePatient::type() const {
		return 'T';
	}
	//Localize where we dynamically allocate for symptoms
	void TriagePatient::initalizeSymptoms(const TriagePatient& other) {
		if (other.m_symptoms) {
			m_symptoms = new char[512];
			strncpy(m_symptoms, other.m_symptoms, 512);
		}
		else {
			m_symptoms = nullptr;
		}
	}
	TriagePatient::TriagePatient(const TriagePatient& other) :
	Patient(other){
		initalizeSymptoms(other);
	}
	TriagePatient& TriagePatient::operator=(const TriagePatient& other) {
		if (this != &other) {
			initalizeSymptoms(other);
		}
		return *this;
	}
	TriagePatient::~TriagePatient() {
		delete[] m_symptoms;
	}
	std::ostream& TriagePatient::write(std::ostream& ostr) const {
		//TRIAGE label
		if (&ostr == &std::cout) {
			ostr << "TRIAGE" << std::endl;
			Patient::write(ostr);
			ostr << "Symptoms: " << m_symptoms << std::endl;
		}
		//Linear format with no symptoms
		else if (&ostr == &std::clog) {
			Patient::write(ostr);
		}
		//Comma-seperated format
		else {
			Patient::write(ostr);
			ostr << "," << m_symptoms;
		}
		return ostr;
	}
	std::istream& TriagePatient::read(std::istream& istr) {
		//Local static array to hold symptoms
		char symptoms[511 + 1];
		//Delete existing symptoms
		delete[] m_symptoms;
		Patient::read(istr);
		//Reads comma seperated values entry via other istream objects
		if (&istr != &std::cin) {
			istr.ignore();
			istr.getline(symptoms, 511, '\n');
			m_symptoms = new char[strlen(symptoms) + 1];
			strcpy(m_symptoms, symptoms);
			nextTriageTicket = number() + 1;
		}
		//Console entry via cin
		else {
			std::cout << "Symptoms: ";
			istr.getline(symptoms, 511, '\n');
			m_symptoms = new char[strlen(symptoms) + 1];
			strcpy(m_symptoms, symptoms);
		}
		if (istr.fail()) {
			delete[] m_symptoms;
			m_symptoms = nullptr;
		}
		return istr;
	}
}