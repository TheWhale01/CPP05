#include "RobotmyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"

int main(void)
{
	srand(time(NULL));
	Bureaucrat michel("michel", 1);
	Bureaucrat patrick("Patrick", 150);
	ShrubberyCreationForm shrub_form("Garden");
	RobotomyRequestForm robot_form("Robot");
	PresidentialPardonForm president_form("President");

	try {patrick.executeForm(robot_form);}
	catch (std::exception const &e) {std::cerr << "Robot: " << e.what() << std::endl;}

	try {patrick.executeForm(shrub_form);}
	catch (std::exception const &e) {std::cerr << "Gardens: " << e.what() << std::endl;}

	try {patrick.executeForm(president_form);}
	catch (std::exception const &e) {std::cerr << "President: " << e.what() << std::endl;}

	std::cout << std::endl;

	try
	{
		shrub_form.beSigned(michel);
		robot_form.beSigned(michel);
		president_form.beSigned(michel);
	}
	catch (std::exception const &e)
	{
		std::cerr << "Michel could not sign form: " << e.what() << std::endl;
	}

	try
	{
		patrick.executeForm(shrub_form);
		patrick.executeForm(robot_form);
		patrick.executeForm(president_form);
	}
	catch (std::exception const &e)
	{
		std::cerr << "Patrick could not execute form: " << e.what() << std::endl;
	}

	std::cout << std::endl;

	michel.executeForm(shrub_form);
	michel.executeForm(robot_form);
	michel.executeForm(president_form);
	return (0);
}