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

		std::cout << "Loading data..." << std::endl;
		file.open(m_fileName);
		//If the file creation is successful and contains data, continue reading
		if (file) {
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
				//If instantiation successful, add to our lineup and increment number in lineup
				if (localPatient != nullptr && !file.eof()) {
					file >> *localPatient;
					m_lineup[i] = localPatient;
					m_noOfPatients++;
				}
			}
		}
		if (file.peek() != EOF) {
			std::cout << "Warning: number of records exceeded " << MAX_PATIENTS << std::endl;
			std::cout << m_noOfPatients << " Records imported..." << std::endl;
		}
		else if (m_noOfPatients) {
			std::cout << m_noOfPatients << " Records imported..." << std::endl;
		}
		else {
			std::cout << "No data or bad data file!" << std::endl;
		}
		std::cout << std::endl;
	}
	PreTriage::~PreTriage() {

	}
	void PreTriage::run() {
		int selection;
		const char* title = "General Healthcare Facility Pre-Triage Application\n"
			"1- Register\n2- Admit\n3- View Lineup";
		Menu menu(title, 0);
		do {
			menu >> selection;
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
				break;
			}
		} while (selection);
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
		int contagionType{};
		int triageType{};
		std::ofstream file;

		file.open(m_fileName);
		std::cout << "Saving lineup..." << std::endl;
		file << m_averageContagionWait << "," << m_averageTriageWait << std::endl;
		for (int i = 0; i < m_noOfPatients; i++) {
			file << *m_lineup[i] << std::endl;
			if (m_lineup[i]->type() == 'C') {
				contagionType++;
			}
			else {
				triageType++;
			}
		}
		std::cout << contagionType << " Contagion Tests and " << triageType << " Triage records were saved!" << std::endl;
	}
	void PreTriage::reg() {

	}
	void PreTriage::admit() {

	}
	void PreTriage::lineup() {
		int counter = 1;
		int selection;
		const char* title = "Select The Lineup\n"
			"1- Contagion Test\n2- Triage";
		Menu menu(title, 1);
			menu >> selection;
			switch (selection) {
			case 1: {
				std::cout << "Row - Patient name                                          OHIP     Tk #  Time\n"
					"-------------------------------------------------------------------------------" << std::endl;
				for (int i = 0; i < m_noOfPatients; i++) {
					if (m_lineup[i]->type() == 'C') {
						std::cout << counter;
						counter++;
						std::cout.width(5);
						std::cout << "- ";
						std::clog << *m_lineup[i] << std::endl;
					}
				}
				if (counter == 1) {
					std::cout << "Line up is empty!\n";
				}
				std::cout << "-------------------------------------------------------------------------------" << std::endl;
				break;
			}
			case 2:
				std::cout << "Row - Patient name                                          OHIP     Tk #  Time\n"
					"-------------------------------------------------------------------------------" << std::endl;
				for (int i = 0; i < m_noOfPatients; i++) {
					if (m_lineup[i]->type() == 'T') {
						std::cout << counter;
						counter++;
						std::cout.width(5);
						std::cout << "- ";
						std::clog << *m_lineup[i] << std::endl;
					}
				}
				if (counter == 1) {
					std::cout << "Line up is empty!\n";
				}
				std::cout << "-------------------------------------------------------------------------------" << std::endl;
				break;
			default:
				std::cout << "Shouldn't happen but switch statements stylistically have a default :)";
				break;
			}
	}	
}