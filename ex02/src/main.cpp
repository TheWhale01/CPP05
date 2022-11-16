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

	std::cerr << "Robot: ";
	patrick.executeForm(robot_form);
	std::cerr << "Garden: ";
	patrick.executeForm(shrub_form);
	std::cerr << "President: ";
	patrick.executeForm(president_form);
	shrub_form.beSigned(michel);
	robot_form.beSigned(michel);
	president_form.beSigned(michel);
	std::cerr << "Patrick: ";
	patrick.executeForm(shrub_form);
	std::cerr << "Patrick: ";
	patrick.executeForm(robot_form);
	std::cerr << "Patrick: ";
	patrick.executeForm(president_form);
	michel.executeForm(shrub_form);
	michel.executeForm(robot_form);
	michel.executeForm(president_form);
	return (0);
}