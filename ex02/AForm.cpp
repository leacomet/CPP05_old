/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acomet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 18:11:25 by acomet            #+#    #+#             */
/*   Updated: 2024/02/27 20:13:48 by acomet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "Bureaucrat.hpp"

AForm::AForm(void) : _name("bobito"), _signature(0), _sign_grade(150), _exec_grade(150)
{
	return;
}

AForm::AForm(std::string name, int const sign_grade, int const exec_grade) : _name(name), _signature(0), _sign_grade(sign_grade), _exec_grade(exec_grade)
{
	if (this->_sign_grade < 1 || this->_exec_grade < 1)
		throw GradeTooHighException();
	if (this->_sign_grade > 150 || this->_exec_grade > 150)
		throw GradeTooLowException();
	return;
}

AForm::AForm(AForm const &src) : _name(src.get_name() + "copy"), _signature(src.get_signature()), _sign_grade(src.get_sign_grade()), _exec_grade(src.get_exec_grade())
{
	return;
}

AForm::~AForm(void)
{
	return;
}

AForm	&AForm::operator=(const AForm &src)
{
	this->_signature = src.get_signature();
	return (*this);
}

std::string const	&AForm::get_name() const
{
	return (this->_name);
}

bool	AForm::get_signature() const
{
	return (this->_signature);
}

int	AForm::get_sign_grade() const
{
	return (this->_sign_grade);
}

int	AForm::get_exec_grade() const
{
	return (this->_exec_grade);
}

void	AForm::set_signature(bool i)
{
	this->_signature = i;
	return;
}


void	AForm::beSigned(Bureaucrat &src)
{
	if (this->get_signature())
		std::cout << src.getName() << " couldn’t sign " << this->_name << " because it is already signed." << std::endl;
	else if (src.getGrade() <= this->_sign_grade)
	{
		this->_signature = 1;
		std::cout << src.getName() << " signed " << this->_name << "." << std::endl;
	}
	else
	{
		std::cout << src.getName() << " couldn’t sign " << this->_name << " because grade is too low.";
		throw GradeTooLowException();
	}
}

std::ostream	&operator<<(std::ostream &o, AForm const &rhs) {

	o << rhs.get_name();
	if (rhs.get_signature())
		o << ", AForm signed";
	else
		o << ", AForm not signed";
	std::cout << ", Signature grade " << rhs.get_sign_grade() << ", Execution grade " << rhs.get_exec_grade() << "." << std::endl;
	return (o);
}
