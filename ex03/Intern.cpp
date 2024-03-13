/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acomet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 19:30:59 by acomet            #+#    #+#             */
/*   Updated: 2024/02/27 20:14:32 by acomet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include "AForm.hpp"

Intern::Intern(void) : _name("BOB"), _grade(150)
{
	return;
}

Intern::Intern(Intern const &src)
{
	return;
}

Intern::~Intern(void)
{
	return;
}

Intern	&Intern::operator=(Intern const &src)
{
	return (*this);
}

AForm	*Intern::makeForm(std::string name, std::string target)
{
	noforest	forms[3] = {&Intern::form_shrubbery, &Intern::form_robotomy, &Intern::form_presidential};
	std::string	all_forms[3] = {"shrubbery creation", "robotomy reauest", "presidential form"};
	int			i = 0;

	while (i < 3)
	{
		if (target == all_forms[i])
			return ((this->*forms[i])(target));
		i++;
	}
	std::cout << "the common intern inform you that the asked form doesn't exist !" << std::endl;
}

AForm	*form_shrubbery(std::string target)
{
	AForm	*temp = new PresidentialPardonForm(target);

	return (temp);
}

AForm	*form_robotomy(std::string target)
{
	AForm	*temp = new RobotomyRequestForm(target);

	return (temp);
}

AForm	*form_presidential(std::string target)
{
	AForm	*temp = new PresidentialPardonForm(target);

	return (temp);
}