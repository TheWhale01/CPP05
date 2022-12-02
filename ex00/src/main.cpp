#include "Bureaucrat.hpp"

int main(void)
{
	Bureaucrat michel("michel", 1);
	Bureaucrat patrick("Patrick", 150);
	Bureaucrat *wrong;

	try
	{
		wrong = new Bureaucrat("Unknown", 2345);
		std::cout << *wrong << std::endl;
		delete wrong;
	}
	catch(const std::exception& e)
	{
		wrong = NULL;
		std::cerr << "Could not instanciate bureaucrate: " <<  e.what() << std::endl;
	}

	try {michel.upgrade();}
	catch (std::exception const &e) {std::cerr << "Could not upgrade: " << e.what() << std::endl;}
	try {michel.downgrade();}
	catch (std::exception const &e) {std::cerr << "Could not downgrade: " << e.what() << std::endl;}
	try {patrick.downgrade();}
	catch (std::exception const &e) {std::cerr << "Could not downgrade: " << e.what() << std::endl;}
	try {patrick.upgrade();}
	catch (std::exception const &e) {std::cerr << "Could not upgrade: " << e.what() << std::endl;}
	std::cout << michel << std::endl;
	std::cout << patrick << std::endl;
	return (0);
}