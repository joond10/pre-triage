/* Citation and Sources...
Final Project Milestone 5
Module: PreTriage
Filename: PreTriage.cpp
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
#include "PreTriage.h"
namespace seneca {

	//Constructor that reads information upon starting program
	PreTriage::PreTriage(const char* fileName) :
		m_averageContagionWait(15), m_averageTriageWait(5) {
		m_fileName = new char[strlen(fileName) + 1];
		strcpy(m_fileName, fileName);
		load();
	}

	//Destructor that saves information upon exiting program
	PreTriage::~PreTriage() {
		save();
		for (int i = 0; i < m_noOfPatients; i++) {
			delete m_lineup[i];
		}
		delete[] m_fileName;
	}

	//Reads data from the files provided
	void PreTriage::load() {
		std::ifstream file;
		Patient* localPatient = nullptr;
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
			for (int i = 0; i < MAX_PATIENTS && file.peek() != EOF; i++) {
				file >> localPatientType;
				//Ignore comma
				file.ignore();
				//Depending on the patient type, instantiate respective type of patient
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
		//Depending on what we read, display appropriate information
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

	//Entry point into the UI of the main menu
	void PreTriage::run() {
		int selection;
		const char* title = "General Healthcare Facility Pre-Triage Application\n"
			"1- Register\n2- Admit\n3- View Lineup";
		Menu menu(title, 0);
		do {
			menu >> selection;
			switch (selection) {
			case 1: {
				if (m_noOfPatients >= MAX_PATIENTS) {
					std::cout << "Line up full!" << std::endl;
				} 
				else {
					reg();
				}
				break;
			}
			case 2:
				admit();
				break;
			case 3:
				lineup();
				break;
			case 0:
				break;
			}
		} while (selection);
	}

	//Query that gets the estimated wait time for a type of patient
	const Time PreTriage::getWaitTime(const Patient& patient) {		
		int matchedType{};
		Time totalEstimated;

		for (int i = 0; i < m_noOfPatients; i++) { 
			if (m_lineup[i]->type() == patient.type()) {
				matchedType++;
			}
		}
		if (patient.type() == 'C') {
			totalEstimated = m_averageContagionWait * matchedType;		
		}
		else {
			totalEstimated = m_averageTriageWait * matchedType; 
		}
		return totalEstimated;
	}

	//Modifier that sets the average wait time for a type of patient
	void PreTriage::setAverageWaitTime(const Patient& patient) { 
		Time time;

		if (patient.type() == 'C') { 
			m_averageContagionWait = ((time.reset() - patient.time()) + (m_averageContagionWait * (patient.number() - 1))) / patient.number();
			std::cout << m_averageContagionWait << "is the average wait time\n" << std::endl;
		}
		else {
			m_averageTriageWait = ((time.reset() - patient.time()) + (m_averageTriageWait * (patient.number() - 1))) / patient.number();
			std::cout << m_averageTriageWait << "is the average wait time\n" << std::endl;
		}
	}

	//Helper function that finds the first patient in line of a specified type
	int PreTriage::indexOfFirstInLine(char type) const {
		int index = -1;
		int flag = 0;

		for (int i = 0; i < m_noOfPatients && !flag; i++) {
			if (m_lineup[i]->type() == type) {
				index = i;
				flag = 1;
			}
		}
		return index;
	}
	//Writes data upon exiting the program
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

	//Creates a sub menu to register a new patient
	void PreTriage::reg() {
		int selection;
		const char* title = "Select Type of Registration:\n1- Contagion Test\n2- Triage";
		Menu menu(title, 1);
		Time time;
		menu >> selection;
		switch (selection) {
		case 1:
			if (m_noOfPatients >= MAX_PATIENTS) {
				std::cout << "Line up full!" << std::endl;
			}
			else {
				printReg('C');
			}
			std::cout << std::endl;
			break;
		case 2:
			if (m_noOfPatients >= MAX_PATIENTS) {
				std::cout << "Line up full!" << std::endl;
			}
			else {
				printReg('T');
			}
			std::cout << std::endl;
			break;
		case 0:
			break;
		default:
			break;
		}
	}

	//Prints the registration information (supports the reg function)
	void PreTriage::printReg(char type) {
		if (type == 'C') {
			m_lineup[m_noOfPatients] = new TestPatient();
		}
		else {
			m_lineup[m_noOfPatients] = new TriagePatient();
		}
		m_lineup[m_noOfPatients]->setArrivalTime();
		std::cout << "Please enter patient information: " << std::endl;
		std::cin >> *m_lineup[m_noOfPatients];
		std::cout << std::endl;
		std::cout << "******************************************" << std::endl;
		std::cout << *m_lineup[m_noOfPatients];
		std::cout << "Estimated Wait Time: " << getWaitTime(*m_lineup[m_noOfPatients]) << std::endl;
		std::cout << "******************************************" << std::endl;
		m_noOfPatients++;
	}

	//Creates a sub menu to admit a patient in line
	void PreTriage::admit() {
		int selection;
		const char* title = "Select Type of Admittance:\n1- Contagion Test\n2- Triage";
		Menu menu(title, 1);
		menu >> selection;
		switch (selection) {
		case 1: 
			if (indexOfFirstInLine('C') == -1) {
				std::cout << "Lineup is empty!\n";
			} 
			else {			
				printAdmit('C');
			}
			break;
		case 2:
			if (indexOfFirstInLine('T') == -1) {
				std::cout << "Lineup is empty!\n";
			}
			else {
				printAdmit('T');
			}
			break;
		case 0:
			break;
		default:
			break;
		}
	}

	//Prints admission information (supports the admit function)
	void PreTriage::printAdmit(char type) {
		Time time;

		std::cout << std::endl;
		std::cout << "******************************************" << std::endl;
		std::cout << "Call time [" << time.reset() << "]" << std::endl;
		std::cout << "Calling for " << *m_lineup[indexOfFirstInLine(type)];
		std::cout << "******************************************" << std::endl;
		std::cout << std::endl;
		setAverageWaitTime(*m_lineup[indexOfFirstInLine(type)]);
		U.removeDynamicElement(m_lineup, indexOfFirstInLine(type), m_noOfPatients);
	}

	//Creates a sub menu to display a report of patients in line
	void PreTriage::lineup() {
		int selection;
		const char* title = "Select The Lineup\n"
			"1- Contagion Test\n2- Triage";
		Menu menu(title, 1);
			menu >> selection;
			switch (selection) {
			case 1: {
				printLineup('C');
				break;
			}
			case 2:
				printLineup('T');
				break;
			case 0:
				break;
			default:
				break;
			}
	}	

	//Prints the report of patients currently in line (supports the lineup function)
	void PreTriage::printLineup(char type) {
		int counter = 1;

		std::cout << "Row - Patient name                                          OHIP     Tk #  Time\n"
			"-------------------------------------------------------------------------------" << std::endl;
		for (int i = 0; i < m_noOfPatients; i++) {
			if (m_lineup[i]->type() == type) {
				std::cout << counter;
				counter++;
				std::cout.width(5);
				std::cout.fill(' ');
				std::cout << "- ";
				std::clog << *m_lineup[i] << std::endl;
			}
		}
		if (counter == 1) {
			std::cout << "Line up is empty!\n";
		}
		std::cout << "-------------------------------------------------------------------------------" << std::endl;
	}
}