/* Citation and Sources...
Final Project Milestone 5
Module: Menu
Filename: Menu.h
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
#ifndef SENECA_MENU_H
#define SENECA_MENU_H
#include <cstring>
#include <iostream>
#include "Utils.h"
namespace seneca {
	class Menu {
		//Holds the menu title to be displayed
		const char* m_text;
		//Holds the number of options in the menu
		int m_options;
		//Holds the number of indentation tabs
		int m_tabs;
	public:
		//Parameterized constructor that recieves a string and optional tab amount
		Menu(const char* menuContent, int numberOfTabs = 0);
		//Destructor
		~Menu();
		//Makes sure the menu can not be copied or assigned to another menu object
		Menu(const Menu& other) = delete;
		Menu& operator=(const Menu& other) = delete;
		//Displays the interface of the menu
		void display() const;
		//Utilizes the display and insertion operator to receives user's selection
		int& operator>>(int& selection);
	};
}
#endif