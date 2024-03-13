/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acomet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 18:11:25 by acomet            #+#    #+#             */
/*   Updated: 2024/02/27 20:13:48 by acomet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"
#include "Bureaucrat.hpp"

RobotomyRequestForm::RobotomyRequestForm(void) : AForm("RobotomyRequestForm", 72, 45), _target("BOB")
{
	return;
}

RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm("RobotomyRequestForm", 72, 45), _target(target)
{
	return;
}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const &src) : AForm("RobotomyRequestForm", 72, 45)
{
	*this = src;
	return;
}

RobotomyRequestForm::~RobotomyRequestForm(void)
{
	return;
}

RobotomyRequestForm	&RobotomyRequestForm::operator=(const RobotomyRequestForm &src)
{
	if (src.get_signature())
		this->set_signature(1);
	this->_target = src.get_target();
	return (*this);
}

std::string const	RobotomyRequestForm::get_target() const
{
	return(this->_target);
}

void	RobotomyRequestForm::beSigned(Bureaucrat &src)
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

bool	RobotomyRequestForm::execute(Bureaucrat const &executor) const
{
	if (!this->get_signature())
	{
		std::cout << executor.getName() << " couldn’t exec " << this->get_name() << " because it isn't signed and if not signed not work." << std::endl;
		return(0);
	}
	if (executor.getGrade() > this->get_exec_grade())
		throw GradeTooLowException();
	std::cout << executor.getName() << " executed " << this->get_name() << "." << std::endl;
	std::cout << "* POULOUPOULOUPOULOU     POULOUPOULOUPOULOU *" << std::endl;
	srand(time(NULL));
	if (rand() % 2 == 1)
		std::cout << this->_target << " has been robotomized." << std::endl;
	else
		std::cout << "robotomization failed !" << std::endl;
	return(1);
}

std::ostream	&operator<<(std::ostream &o, RobotomyRequestForm const &rhs) 
{
	if (rhs.get_signature())
		o << "RobotomyRequestForm signed";
	else
		o << "RobotomyRequestForm not signed";
	std::cout << ", Signature grade " << rhs.get_sign_grade() << ", Execution grade " << rhs.get_exec_grade() << "." << std::endl;
	return (o);
}