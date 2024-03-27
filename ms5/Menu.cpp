/* Citation and Sources...
Final Project Milestone 5
Module: Time
Filename: Menu.cpp
Version 1.0
Student Name: Joon Dong
Student ID:	036262152
Student Email: thdong1@myseneca.ca
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------
*/
#include "Menu.h"
namespace seneca {

	//Parametized constructor
	Menu::Menu(const char* menuContent, int numberOfTabs) 
		: m_text(menuContent), m_tabs(numberOfTabs) {

		m_text = new char[strlen(menuContent) + 1]; 
		strcpy((char*)m_text, menuContent);

		m_options = 1; //There will be an option by default due to exit
		for (int i = 0; m_text[i] != '\0'; ++i) {
			if (m_text[i] == '\n') {
				m_options++;
			}
		}
	}
	Menu::~Menu() {
		delete[] m_text;
	}
	void Menu::display() const {
		//If m_tabs was passed in via constructor
		if (m_tabs > 0) {
			//An indent is 3 spaces
			int indentation = m_tabs * 3; 
			//Indent before the menu
			for (int i = 0; i < indentation; i++) {
				std::cout << " ";
			}
			for (int i = 0; m_text[i] != '\0'; i++) {
				std::cout << m_text[i];
				//Indent for every new option
				if (m_text[i] == '\n') {
					for (int j = 0; j < indentation; j++) {
						std::cout << " ";
					}
				}
			}
			//Newline after all optiosn displayed
			std::cout << std::endl;
			//Indent for the exit option
			for (int i = 0; i < indentation; i++) {
				std::cout << " ";
			}
			std::cout << "0- Exit" << std::endl;
			//Indent for the input prompt
			for (int i = 0; i < indentation; i++) {
				std::cout << " ";
			}
			std::cout << "> ";
		}
		//Otherwise just print normally
		else {
			std::cout << m_text << std::endl;
			std::cout << "0- Exit" << std::endl;
			std::cout << "> ";
		}
	}
	int& Menu::operator>>(int& Selection) {
		//Call display function
		display();
		//Use foolproof int functions
		Selection = getInt(0,3);
		return Selection;
	}
	int Menu::getInt() {
		int value{};
		bool done{};
		do {
			done = false;
			std::cin >> value;
			//If cin succeeds meaning an integer was entered
			if (std::cin) {
				//If the integer didn't end with newline, fail
				if (std::cin.get() != '\n') {
					std::cout << "Only enter an integer, try again: ";
				}
				//Otherwise if it did, success
				else {
					done = true;
				}
			}
			//If cin failed meaning an integer was not entered
			else {
				//Clear and prompt for bad integer
				std::cin.clear();
				std::cout << "Bad integer value, try again: ";
			}
			//Clear buffer and loop for iput again
			if (!done) {
				std::cin.ignore(10000, '\n');
			}
		} while (!done);
	
		return value;
	}
	int Menu::getInt(int min, int max) {
		int value{};
		do {
			value = getInt();
		} while ((value < min || value > max) &&
			//Error message only evaluated if value is out of range 
			std::cout << "Invalid value enterd, retry[" << min << " <= value <= " << max << "]: ");
		return value;
	}
}