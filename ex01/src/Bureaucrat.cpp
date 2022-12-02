#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(void):_grade(150), _name("default")
{
	return ;
}

Bureaucrat::Bureaucrat(Bureaucrat const &rhs): _name(rhs._name)
{
	*this = rhs;
	return ;
}

Bureaucrat::Bureaucrat(std::string const &name, int grade): _name(name)
{
	if (grade <= 0)
		throw (Bureaucrat::GradeTooHighException());
	else if (grade > 150)
		throw (Bureaucrat::GradeTooLowException());
	else
		this->_grade = grade;
	return ;
}

Bureaucrat::~Bureaucrat(void)
{
	return ;
}

/* Operator overloads */

Bureaucrat &Bureaucrat::operator=(Bureaucrat const &rhs)
{
	if (this == &rhs)
		return (*this);
	this->_grade = rhs._grade;
	return (*this);
}

std::ostream &operator<<(std::ostream &stream, Bureaucrat const &bureaucrat)
{
	stream << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade() << ".";
	return (stream); 
}

/* Member functions */

int const &Bureaucrat::getGrade(void) const
{
	return (this->_grade);
}

std::string const &Bureaucrat::getName(void) const
{
	return (this->_name);
}

void Bureaucrat::upgrade(void)
{
	if (this->_grade == 1)
		throw Bureaucrat::GradeTooHighException();
	this->_grade--;
}

void Bureaucrat::downgrade(void)
{
	if (this->_grade == 150)
		throw Bureaucrat::GradeTooLowException();
	this->_grade++;
}

void Bureaucrat::signForm(Form const &form) const
{
	if (form.getSign() == false && this->_grade > form.getSignGrade())
		throw (Form::GradeTooLowException());
	std::cout << this->_name << " signed " << form.getName() << std::endl;
}

/* Exceptions */

const char *Bureaucrat::GradeTooHighException::what(void) const throw()
{
	return ("Grade too high");
}

const char *Bureaucrat::GradeTooLowException::what(void) const throw()
{
	return ("Grade too low");
}