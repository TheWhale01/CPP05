#include "Bureaucrat.hpp"

int main(void)
{
	Form form;
	Form *custom;
	Bureaucrat michel("michel", 1);
	Bureaucrat patrick("Patrick", 150);

	std::cout << "------------ CUSTOM FORM ------------" << std::endl;
	try
	{
		custom = new Form(15, 54, "custom");
		try {custom->beSigned(patrick);}
		catch (std::exception const &e) {std::cerr << "Could not sign form: " << e.what() << std::endl;}

		try {patrick.signForm(*custom);}
		catch (std::exception const &e) {std::cerr << "Could not sign form: " << e.what() << std::endl;}

		std::cout << std::endl << *custom << std::endl << std::endl;

		try {custom->beSigned(michel);}
		catch (std::exception const &e) {std::cerr << "Could not sign form: " << e.what() << std::endl;}

		try {michel.signForm(*custom);}
		catch (std::exception const &e) {std::cerr << "Could not sign form: " << e.what() << std::endl;}

		std::cout << std::endl << *custom << std::endl;
		delete custom;
	}
	catch (std::exception const &e)
	{
		std::cerr << "Could not instanciate form: " << e.what() << std::endl;
	}
	std::cout << std::endl;
	try
	{
		std::cout << "------------ DEFAULT FORM ------------" << std::endl;
		try {form.beSigned(patrick);}
		catch (std::exception const &e) {std::cerr << "Could not sign form: " << e.what() << std::endl;}

		try {patrick.signForm(form);}
		catch (std::exception const &e) {std::cerr << "Could not sign form: " << e.what() << std::endl;}

		std::cout << std::endl << form << std::endl << std::endl;

		try {form.beSigned(michel);}
		catch (std::exception const &e) {std::cerr << "Could not sign form: " << e.what() << std::endl;}

		try {michel.signForm(form);}
		catch (std::exception const &e) {std::cerr << "Could not sign form: " << e.what() << std::endl;}
	
		std::cout << std::endl << form << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << "Could not instanciate bureaucrat: " << e.what() << std::endl;
	}
	return (0);
}