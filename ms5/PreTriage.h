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
		//Gets the estimated wait time for a patient
		const Time getWaitTime(const Patient& patient);
		//Adjusts the average wait time
		void setAverageWaitTime(const Patient& patient);
		//Finds the first patient in line of a specified type
		int indexOfFirstInLine(char type) const;
	//Menu handling methods:
		//Reads data
		void load();
		//Writes data
		void save();
		//Creates a sub menu to register a new patient
		void reg();
		//Calls up the next patient in line to be admitted
		void admit();
		//Prints a report of the patients currently in line
		void lineup();
	public:
		PreTriage(const char* fileName);
		~PreTriage();
		//Entry point into the UI of the menu
		void run();
	};
}

#endif 