/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acomet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 18:11:25 by acomet            #+#    #+#             */
/*   Updated: 2024/02/27 20:13:48 by acomet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"
#include "Bureaucrat.hpp"

PresidentialPardonForm::PresidentialPardonForm(void) : AForm("PresidentialPardonForm", 25, 5), _target("BOB")
{
	return;
}

PresidentialPardonForm::PresidentialPardonForm(std::string target) : AForm("PresidentialPardonForm", 25, 5), _target(target)
{
	return;
}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const &src) : AForm("PresidentialPardonForm", 25, 5)
{
	*this = src;
	return;
}

PresidentialPardonForm::~PresidentialPardonForm(void)
{
	return;
}

PresidentialPardonForm	&PresidentialPardonForm::operator=(const PresidentialPardonForm &src)
{
	if (src.get_signature())
		this->set_signature(1);
	this->_target = src.get_target();
	return (*this);
}

std::string const	PresidentialPardonForm::get_target() const
{
	return(this->_target);
}

void	PresidentialPardonForm::beSigned(Bureaucrat &src)
{
	if (this->get_signature())
		std::cout << src.getName() << " couldn’t sign " << this->get_name() << " because it is already signed." << std::endl;
	else if (src.getGrade() <= this->get_sign_grade())
	{
		this->set_signature(1);
		std::cout << src.getName() << " signed " << this->get_name() << "." << std::endl;
	}
	else
		throw GradeTooLowException();
}

bool	PresidentialPardonForm::execute(Bureaucrat const &executor) const
{
	if (!this->get_signature())
	{
		std::cout << executor.getName() << " couldn’t exec " << this->get_name() << " because it isn't signed and if not signed not work." << std::endl;
		return (0);
	}
	if (executor.getGrade() > this->get_exec_grade())
		throw GradeTooLowException();
	std::cout << executor.getName() << " executed " << this->get_name() << "." << std::endl;
	std::cout << this->_target << " has been pardoned by Zaphod Beeblebrox." << std::endl;
	return (1);
}

std::ostream	&operator<<(std::ostream &o, PresidentialPardonForm const &rhs) 
{
	if (rhs.get_signature())
		o << "PresidentialPardonForm signed";
	else
		o << "PresidentialPardonForm not signed";
	std::cout << ", Signature grade " << rhs.get_sign_grade() << ", Execution grade " << rhs.get_exec_grade() << "." << std::endl;
	return (o);
}