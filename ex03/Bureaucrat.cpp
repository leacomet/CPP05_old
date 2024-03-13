/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acomet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 19:30:59 by acomet            #+#    #+#             */
/*   Updated: 2024/02/27 20:14:32 by acomet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"

Bureaucrat::Bureaucrat(void) : _name("BOB"), _grade(150)
{
	return;
}

Bureaucrat::Bureaucrat(std::string name, int grade) : _name(name), _grade(grade)
{
	if (grade < 1)
		throw GradeTooHighException();
	else if (grade > 150)
		throw GradeTooLowException();
	return;
}

Bureaucrat::Bureaucrat(Bureaucrat const &src) : _name(src.getName() + "copy"), _grade(src.getGrade())
{
	return;
}

Bureaucrat::~Bureaucrat(void)
{
	return;
}

Bureaucrat	&Bureaucrat::operator=(Bureaucrat const &src)
{
	 this->_grade = src.getGrade();
	 return (*this);
}

std::string const	&Bureaucrat::getName(void) const
{
	return(this->_name);
}

int	Bureaucrat::getGrade(void) const
{
	return(this->_grade);
}

void	Bureaucrat::increment(void)
{
	this->_grade--;
	if (this->_grade == 0)
		throw GradeTooHighException();
}

void	Bureaucrat::decrement(void)
{
	this->_grade++;
	if (this->_grade == 151)
		throw GradeTooHighException();
}

void	Bureaucrat::signForm(AForm &src)
{
	src.beSigned(*this);
}

void	Bureaucrat::executeForm(AForm const & form)
{
	Bureaucrat const	&temp(*this);

	form.execute(temp);
}


std::ostream	&operator<<(std::ostream &o, Bureaucrat const &rhs) {

	o << rhs.getName() << ", bureaucrat grade " << rhs.getGrade() << "." << std::endl;
	return (o);
}
