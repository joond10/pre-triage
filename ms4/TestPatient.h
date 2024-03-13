#ifndef SENECA_TEST_PATIENT_H
#define SENECA_TEST_PATIENT_H
#include "Patient.h"
namespace seneca {

	extern int nextTestTicket;

	class TestPatient : public Patient {
	public:
		TestPatient();
		char type() const;
		std::ostream& csvWrite(std::ostream& ostr) const;
		std::istream& csvRead(std::istream& istr);
		std::ostream& write(std::ostream& ostr) const;
		std::istream& read(std::istream& istr);

	};
}
#endif