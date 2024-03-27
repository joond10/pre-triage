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
namespace seneca {
	class Menu {
		const char* m_text;
		int m_options;
		int m_tabs;
	public:
		Menu(const char* menuContent, int numberOfTabs = 0);
		~Menu();
		Menu(const Menu& other) = delete;
		Menu& operator=(const Menu& other) = delete;
		void display() const;
		int& operator>>(int& Selection);
		//Foolproof input functions
		int getInt();
		int getInt(int min, int max);
	};
}
#endif