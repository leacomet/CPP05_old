/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acomet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 18:11:25 by acomet            #+#    #+#             */
/*   Updated: 2024/02/27 20:13:48 by acomet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include "Bureaucrat.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(void) : AForm("ShrubberyCreationForm", 145, 137), _target("_shrubbery")
{
	return;
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm("ShrubberyCreationForm", 145, 137), _target(target + "/_shrubbery")
{
	return;
}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const &src) : AForm("ShrubberyCreationForm", 145, 137)
{
	*this = src;
	return;
}

ShrubberyCreationForm::~ShrubberyCreationForm(void)
{
	return;
}

ShrubberyCreationForm	&ShrubberyCreationForm::operator=(const ShrubberyCreationForm &src)
{
	if (src.get_signature())
		this->set_signature(1);
	this->_target = src.get_target();
	return (*this);
}

std::string const	ShrubberyCreationForm::get_target() const
{
	return(this->_target);
}

void	ShrubberyCreationForm::beSigned(Bureaucrat &src)
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

bool	ShrubberyCreationForm::execute(Bureaucrat const &executor) const
{
	std::ofstream	outfile;

	if (!this->get_signature())
	{
		std::cout << executor.getName() << " couldn’t exec " << this->get_name() << " because it isn't signed and if not signed not work." << std::endl;
		return(0);
	}
	if (executor.getGrade() > this->get_exec_grade())
		throw GradeTooLowException();
	outfile.open((this->get_target()).c_str());
	if (!outfile.good())
	{
		std::cout << "A problem occured while trying to forest \"" << this->_target << "\"" << std::endl;
		outfile.close();
		return(0);
	}
	outfile << "|" << std::endl
			<< "-" << std::endl
			<< "| |" << std::endl
			<< "_ _" << std::endl;
	std::cout << executor.getName() << " executed " << this->get_name() << "." << std::endl;
	outfile.close();
	return(1);
}

std::ostream	&operator<<(std::ostream &o, ShrubberyCreationForm const &rhs) 
{
	if (rhs.get_signature())
		o << "ShrubberyCreationForm signed";
	else
		o << "ShrubberyCreationForm not signed";
	std::cout << ", Signature grade " << rhs.get_sign_grade() << ", Execution grade " << rhs.get_exec_grade() << "." << std::endl;
	return (o);
}