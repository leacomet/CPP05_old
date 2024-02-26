/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acomet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 19:30:59 by acomet            #+#    #+#             */
/*   Updated: 2024/02/27 00:09:36 by acomet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(void) : _name("BOB"), _grade(150)
{
	return;
}

Bureaucrat::Bureaucrat(std::string name, int grade) : _name(name), _grade(grade)
{
	if (grade < 1)
	{
		throw GradeTooHighException();
		_grade = 150;
	}
	else if (grade > 150)
	{
		throw GradeTooLowException();
		_grade = 150;
	}
	return;
}

Bureaucrat::Bureaucrat(Bureaucrat const &src) : _name(src.getName()), _grade(src.getGrade())
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
