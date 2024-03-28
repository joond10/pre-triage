/* Citation and Sources...
Final Project Milestone 5
Module: TriagePatient
Filename: TriagePatient.h
Version 1.0
Student Name: Joon Dong
Student ID:	036262152
Student Email: thdong1@myseneca.ca
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------
*/
#ifndef SENECA_TRIAGE_PATIENT_H
#define SENECA_TRIAGE_PATIENT_H
#define _CRT_SECURE_NO_WARNINGS
#include "Patient.h"
namespace seneca {
	extern int nextTriageTicket;
	//Triage patient that overrides with a concrete implementation
	class TriagePatient : public Patient {
		char* m_symptoms;
	public:
		TriagePatient();
		char type() const;

		//Localization technique for the rule of three with symptom memory management
		void initalizeSymptoms(const TriagePatient&);
		TriagePatient(const TriagePatient&);
		TriagePatient& operator=(const TriagePatient&);
		~TriagePatient();

		std::ostream& write(std::ostream& ostr) const;
		std::istream& read(std::istream& istr);
	};
}
#endif