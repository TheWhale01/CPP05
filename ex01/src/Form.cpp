#include "Form.hpp"

Form::Form(void): _sign(0), _s_grade(30), _x_grade(30)
{
	return ;
}

Form::Form(Form const &rhs)
{
	*this = rhs;
	return ;
}

Form::Form(int x_grade, int s_grade): _x_grade(x_grade), _s_grade(s_grade), _sign(0)
{
	if (x_grade <= 0 || s_grade <= 0)
		throw (Form::GradeTooHighException());
	else if (x_grade > 150 || s_grade > 150)
		throw (Form::GradeTooLowException());
	return ;
}

Form::~Form(void)
{
	return ;
}

/* Operator overloads */

Form &Form::operator=(Form const &rhs)
{
	if (this == &rhs)
		return (*this);
	this->_sign = rhs._sign;
	return (*this);
}

std::ostream &operator<<(std::ostream &stream, Form const &form)
{
	stream << "Execution grade: " << form.getExecGrade() << std::endl
		<< "Sign grade: " << form.getSignGrade() << std::endl
		<< "Is signed: " << form.getSign() << std::endl
		<< "Form name: " << form.getName();
}

/* Member function */

int const &Form::getExecGrade(void) const
{
	return (this->_x_grade);
}

int const &Form::getSignGrade(void) const
{
	return (this->_s_grade);
}

bool const &Form::getSign(void) const
{
	return (this->_sign);
}

void Form::beSigned(Bureaucrat const &bureaucrat)
{
	
}