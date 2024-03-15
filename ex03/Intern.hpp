/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acomet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 21:55:06 by acomet            #+#    #+#             */
/*   Updated: 2024/02/27 20:46:31 by acomet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	INTER_HPP
#define INTER_HPP

#include <iostream>
#include <string>
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

class	Intern
{

public:

	Intern(void);
	Intern(Intern const &src);
	~Intern(void);
	Intern	&operator=(Intern const &src);

	AForm	*makeForm(std::string name, std::string target);
	AForm	*form_shrubbery(std::string target);
	AForm	*form_robotomy(std::string target);
	AForm	*form_presidential(std::string target);

};

typedef AForm *(Intern::*noforest)(std::string target);

#endif
