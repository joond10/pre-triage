/* Citation and Sources...
Final Project Milestone 4
Module: Utils
Filename: Utils.cpp
Version 1.0
Student Name: Joon Dong
Student ID:	036262152
Student Email: thdong1@myseneca.ca
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------
*/
/***********************************************************************
// OOP244 Project
//
// File  Utils.cpp
// Author  Fardad Soleimanloo
// Description
//
// Revision History
// -----------------------------------------------------------
// Name                 Date            Reason
***********************************************************************/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Utils.h"
#include "Time.h"
using namespace std;
namespace seneca {
	// start provided code
	bool debug = false;
	Utils U;
	int Utils::getTime() {
		int mins = -1;
		if (debug) {
			int duration[]{ 3,5,9,20,30 };
			mins = (m_testMins %= 1440);
			m_testMins += duration[m_testIndex++ % 5];
		}
		else {
			time_t t = time(NULL);
			tm lt = *localtime(&t);
			mins = lt.tm_hour * 60 + lt.tm_min;
		}
		return mins;
	}
	void Utils::setDebugTime(int hour, int min) {
		seneca::debug = true;
		m_testMins = hour * 60 + min;
	}

	int Utils::strcmp(const char* s1, const char* s2)const {
		int i;
		for (i = 0; s1[i] && s2[i] && s1[i] == s2[i]; i++);
		return s1[i] - s2[i];
	}
	// end provided code
	int Utils::getInt() {
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
	int Utils::getInt(int min, int max) {
		int value{};
		do {
			value = getInt();
		} while ((value < min || value > max) &&
			//Error message only evaluated if value is out of range 
			std::cout << "Invalid value enterd, retry[" << min << " <= value <= " << max << "]: ");
		return value;
	}
}