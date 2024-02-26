/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acomet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 20:49:44 by acomet            #+#    #+#             */
/*   Updated: 2024/02/27 00:24:05 by acomet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main(void)
{
{
	Bureaucrat	Jean;
	Bureaucrat	dopple(Jean);

	std::cout << "Jean" << std::endl;
	std::cout << "name : " << Jean.getName() << std::endl;
	std::cout << "grade : " << Jean.getGrade() << std::endl;
	std::cout << std::endl << std::endl;

	std::cout << "dopple" << std::endl;
	std::cout << "name : " << dopple.getName() << std::endl;
	std::cout << "grade : " << dopple.getGrade() << std::endl;
	std::cout << std::endl;

	for (int i = 0; i < 149; i++)
		dopple.increment();
	std::cout << "Dopple new grade after 149 increments : " << dopple.getGrade() << std::endl;
	dopple.decrement();
	dopple.decrement();
	std::cout << "Dopple new grade after 2 decrements : " << dopple.getGrade() << std::endl;
	std::cout << std::endl << std::endl;
}

// {
// /*	test throw error	*/
	// try
	// {
		// Bureaucrat	Jean("Bob", 151);
		// Bureaucrat	Bob("Jean", 0);
	// }
	// catch (Bureaucrat::GradeTooHighException &e)
	// {
		// std::cout << e.what() << std::endl;
		// return (1);
	// }
	// catch (Bureaucrat::GradeTooLowException &e)
	// {
		// std::cout << e.what() << std::endl;
		// return (1);
	// }
// }
//
{
	Bureaucrat	BOB("Jean", 1);
	Bureaucrat	Jean("BOB", 150);

	try
	{
		BOB.decrement();
		Jean.increment();
	}
	catch(Bureaucrat::GradeTooLowException &e)
	{
		std::cout << e.what() << std::endl;
		return (1);
	}
	catch(Bureaucrat::GradeTooHighException &e)
	{
		std::cout << e.what() << std::endl;
		return (1);
	}
}
}
