/* Citation and Sources...
Final Project Milestone 5
Module: PreTriage
Filename: PreTriage.h
Version 1.0
Student Name: Joon Dong
Student ID:	036262152
Student Email: thdong1@myseneca.ca
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------
*/
#ifndef PRE_TRIAGE_H
#define PRE_TRIAGE_H
//Maximum number of patients in the lineup (Contagion and Triage combined)
#define MAX_PATIENTS 100
#include <iostream>
#include <fstream>
#include <cstring>
#include "Time.h"
#include "Menu.h"
#include "Patient.h"
#include "TestPatient.h"
#include "TriagePatient.h"
#include "Utils.h"
namespace seneca {
	class PreTriage {
		Time m_averageContagionWait;
		Time m_averageTriageWait;
		Patient* m_lineup[MAX_PATIENTS]{};
		char* m_fileName = nullptr;
		int m_noOfPatients;
	//Private methods:
		//Query that gets the estimated wait time for a type of patient
		const Time getWaitTime(const Patient& patient);
		//Modifier that sets the average wait time for a type of patient
		void setAverageWaitTime(const Patient& patient);
		//Helper function that finds the first patient in line of a specified type
		int indexOfFirstInLine(char type) const;
	//Menu handling methods:
		//Reads data from the files provided
		void load();
		//Writes data 
		void save();
		//Creates a sub menu to register a new patient
		void reg();
		//Prints the registration information (supports the reg function)
		void printReg(char type);
		//Creates a sub menu to admit a patient in line
		void admit();
		//Prints admission information (supports the admit function)
		void printAdmit(char type);
		//Creates a sub menu to display a report of patients in line
		void lineup();
		//Prints the report of patients currently in line (supports the lineup function)
		void printLineup(char type);
	public:
		//Constructor that reads information upon starting program
		PreTriage(const char* fileName);
		//Destructor that saves information upon exiting program
		~PreTriage();
		//Entry point into the UI of the main menu
		void run();
	};
}

#endif 