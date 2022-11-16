#include "Bureaucrat.hpp"

int main(void)
{
	Form form;
	Bureaucrat michel("michel", 1);
	Bureaucrat patrick("Patrick", 150);
	try
	{
		michel.upgrade();
		michel.downgrade();
		patrick.downgrade();
		patrick.upgrade();
		std::cout << michel << std::endl;
		std::cout << patrick << std::endl;

		form.beSigned(patrick);
		std::cout << std::endl;
		patrick.signForm(form);
		std::cout << std::endl << form << std::endl << std::endl;
		form.beSigned(michel);
		michel.signForm(form);
		std::cout << std::endl << form << std::endl << std::endl;

		Bureaucrat unknown("unknown", 234);
	}
	catch(const std::exception& e)
	{
		std::cerr << "Could not instanciate bureaucrate: " <<  e.what() << std::endl;
		return (0);
	}
	return (0);
}