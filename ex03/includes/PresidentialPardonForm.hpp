#pragma once
#include "AForm.hpp"

class PresidentialPardonForm: public AForm
{
	public:
		PresidentialPardonForm(void);
		PresidentialPardonForm(std::string const &target);
		PresidentialPardonForm(PresidentialPardonForm const &rhs);
		~PresidentialPardonForm(void);

		PresidentialPardonForm &operator=(PresidentialPardonForm const &rhs);

		void execute(Bureaucrat const &executor) const;
};