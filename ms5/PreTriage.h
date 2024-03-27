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
	//Private methods
		const Time getWaitTime(const Patient& patient) const;
		void setAverageWaitTime(const Patient& patient);
		int indexOfFirstInLine(char type) const;
		void load();
		void save();
		void reg();
		void admit();
		void lineup();
	public:
		PreTriage(const char* fileName);
		~PreTriage();
		void run();
	};
}

#endif 
