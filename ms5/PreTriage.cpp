#define _CRT_SECURE_NO_WARNINGS
#include "PreTriage.h"
namespace seneca {


	PreTriage::PreTriage(const char* fileName) :
		m_averageContagionWait(15), m_averageTriageWait(5) {
		m_fileName = new char[strlen(fileName) + 1];
		strcpy(m_fileName, fileName);
		load();
	}
	void PreTriage::load() {
		//File for file reading operations
		std::ifstream file;
		//Temporary local patient
		Patient* localPatient = nullptr;
		//Temporary type of local patient
		char localPatientType;

		//Read in the average wait time of the data file
		std::cout << "Loading data..." << std::endl;
		file.open(m_fileName);
		file >> m_averageContagionWait;
		file.ignore(1000, ',');
		file >> m_averageTriageWait;
		file.ignore(1000, '\n');

		//Read up until 100 patients or up until there's nothing left to read
		for (int i = 0; i < MAX_PATIENTS && !file.eof(); i++) {
			file >> localPatientType;
			//Ignore newline
			file.ignore();
			//Depending on the patient type, instantiate respective patient
			if (localPatientType == 'C') {
				localPatient = new TestPatient();
			}
			else if (localPatientType == 'T') {
				localPatient = new TriagePatient();
			}
			//If instnatiation successful, add to our lineup and increment number in lineup
			if (localPatient != nullptr && !file.eof()) {
				file >> *localPatient;
				m_lineup[i] = localPatient;
				m_noOfPatients++;
			}
		}
		if (!file.eof()) {
			std::cout << "Warning: number of records exceeded " << MAX_PATIENTS << std::endl;
			std::cout << m_noOfPatients << " Records imported..." << std::endl;
		}
		else if (m_noOfPatients) {
			std::cout << m_noOfPatients << " Records imported..." << std::endl;
		}
		else {
			std::cout << "No data or bad data file" << std::endl;
		}
	}
	PreTriage::~PreTriage() {

	}
	void PreTriage::run() {
		int selection;
		const char* title = "General Healthcare Facility Pre-Triage Application\n"
			"1- Register\n2- Admit\n3- View Lineup";
		Menu menu(title, 0);
		while (menu >> selection && !selection) {
			switch (selection) {
			case 1: {
				reg();
				break;
			}
			case 2:
				admit();
				break;
			case 3:
				lineup();
				break;
			case 0:
				save();
				selection = 0;
				break;
			}
		}

	}
	const Time PreTriage::getWaitTime(const Patient& patient) const {
		return 0;
	}
	void PreTriage::setAverageWaitTime(const Patient& patient) {

	}
	int PreTriage::indexOfFirstInLine(char type) const {
		return 0;
	}
	void PreTriage::save() {

	}
	void PreTriage::reg() {

	}
	void PreTriage::admit() {

	}
	void PreTriage::lineup() {

	}
}