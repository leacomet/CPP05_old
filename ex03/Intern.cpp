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

Intern::Intern(void)
{
	return;
}

Intern::Intern(Intern const &src)
{
	(void)src;
	return;
}

Intern::~Intern(void)
{
	return;
}

Intern	&Intern::operator=(Intern const &src)
{
	(void)src;
	return (*this);
}

AForm	*Intern::makeForm(std::string name, std::string target)
{
	noforest	forms[3] = {&Intern::form_shrubbery, &Intern::form_robotomy, &Intern::form_presidential};
	std::string	all_forms[3] = {"shrubbery creation", "robotomy request", "presidential pardon"};
	int			i = 0;

	while (i < 3)
	{
		if (name == all_forms[i])
			return ((this->*forms[i])(target));
		i++;
	}
	std::cout << "the common intern inform you that " << name << " form doesn't exist !" << std::endl;
	return (NULL);
}

AForm	*Intern::form_shrubbery(std::string target)
{
	AForm	*temp = new ShrubberyCreationForm(target);

	return (temp);
}

AForm	*Intern::form_robotomy(std::string target)
{
	AForm	*temp = new RobotomyRequestForm(target);

	return (temp);
}

AForm	*Intern::form_presidential(std::string target)
{
	AForm	*temp = new PresidentialPardonForm(target);

	return (temp);
}