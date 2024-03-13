#include "TestPatient.h"
namespace seneca {

	int nextTestTicket = 1;

	TestPatient::TestPatient() :
	Patient(nextTestTicket){
		nextTestTicket++;
	}
	char TestPatient::type() const{
		return 'C';
	}
	std::ostream& TestPatient::csvWrite(std::ostream& ostr) const {
		Patient::write(ostr);
		return ostr;
	}
	std::istream& TestPatient::csvRead(std::istream& istr) {
		Patient::read(istr);
		nextTestTicket = number() + 1;
		return istr;
	}
	std::ostream& TestPatient::write(std::ostream& ostr) const {
		if (&ostr == &std::cout) {
			ostr << "Contagion TEST" << std::endl;
		}
		Patient::write(ostr);
		return ostr;
	}
	std::istream& TestPatient::read(std::istream& istr) {
		Patient::read(istr);
		if (&istr != &std::cin) {
			nextTestTicket = number() + 1;
		}
		return istr;
	}

}