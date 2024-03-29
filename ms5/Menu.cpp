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

		//Default amount of options is 1 due to exit
		m_options = 1; 
		for (int i = 0; m_text[i] != '\0'; ++i) {
			//A newline indicates another option in the menu
			if (m_text[i] == '\n') {
				m_options++;
			}
		}
	}
	Menu::~Menu() {
		delete[] m_text;
	}

	//Displays the interface of the menu
	void Menu::display() const {
		//If a number of tabs was passed in
		if (m_tabs > 0) {
			//An indent is 3 spaces
			int indentation = m_tabs * 3; 
			//Indent before the menu
			for (int i = 0; i < indentation; i++) {
				std::cout << " ";
			}
			//Display menu content
			for (int i = 0; m_text[i] != '\0'; i++) {
				std::cout << m_text[i];
				//Must indent for every new option
				if (m_text[i] == '\n') {
					for (int j = 0; j < indentation; j++) {
						std::cout << " ";
					}
				}
			}
			//Newline after all options displayed
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
		//Otherwise just print menu normally if number of tabs not specified
		else {
			std::cout << m_text << std::endl;
			std::cout << "0- Exit" << std::endl;
			std::cout << "> ";
		}
	}

	//Utilizes the display and insertion operator to get user's selection
	int& Menu::operator>>(int& selection) {
		//Display the menu and get input in one go
		display();
		//Use foolproof int functions
		selection = U.getInt(0,3);
		return selection;
	}
}