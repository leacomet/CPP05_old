/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acomet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 20:49:44 by acomet            #+#    #+#             */
/*   Updated: 2024/03/03 15:37:43 by acomet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <fstream>  

int main(void)
{
// {
// 	ShrubberyCreationForm	form1;
// 	ShrubberyCreationForm	form2("..");
// 	ShrubberyCreationForm	form3(form1);

// 	std::cout << form1;
// 	std::cout << form2;
// 	std::cout << form3;

// 	/*	test form ShrubberyCreationForm	*/
// 	Bureaucrat	moibigboss("acomet", 1);
	
// 	form2.beSigned(moibigboss);
// 	std::cout << form2;
// 	form2.execute(moibigboss);
// }

// 	/*	test errors ShrubberyCreationForm */
// {
// 	Bureaucrat				guy_146("number 146", 146);
// 	Bureaucrat				guy_145("number 145", 145);
// 	Bureaucrat				guy_137("number 137", 137);
// 	ShrubberyCreationForm	shrubbery;

// 	try
// 	{
// 		shrubbery.beSigned(guy_146);
// 	}
// 	catch (GradeTooLowException &e)
// 	{
// 		std::cout << e.what() << std::endl;
// 	}

// 	try
// 	{
// 		shrubbery.execute(guy_145);
// 	}
// 	catch (GradeTooLowException &e)
// 	{
// 		std::cout << e.what() << std::endl;
// 	}
// 	shrubbery.beSigned(guy_145);

// 	try
// 	{
// 		shrubbery.execute(guy_145);
// 	}
// 	catch (GradeTooLowException &e)
// 	{
// 		std::cout << e.what() << std::endl;
// 	}
	
// 	try
// 	{
// 		shrubbery.execute(guy_137);
// 	}
// 	catch (GradeTooLowException &e)
// 	{	
// 		std::cout << e.what() << std::endl;
// 	}
// }


// 	/*	test errors RobotomyRequestForm */
// {
// 	Bureaucrat				guy_73("number 73", 73);
// 	Bureaucrat				guy_72("number 72", 72);
// 	Bureaucrat				guy_45("number 45", 45);
// 	RobotomyRequestForm		robotomy;

// 	try
// 	{
// 		robotomy.beSigned(guy_73);
// 	}
// 	catch (GradeTooLowException &e)
// 	{
// 		std::cout << e.what() << std::endl;
// 	}

// 	try
// 	{
// 		robotomy.execute(guy_72);
// 	}
// 	catch (GradeTooLowException &e)
// 	{
// 		std::cout << e.what() << std::endl;
// 	}
// 	robotomy.beSigned(guy_72);

// 	try
// 	{
// 		robotomy.execute(guy_72);
// 	}
// 	catch (GradeTooLowException &e)
// 	{
// 		std::cout << e.what() << std::endl;
// 	}
	
// 	try
// 	{
// 		robotomy.execute(guy_45);
// 	}
// 	catch (GradeTooLowException &e)
// 	{	
// 		std::cout << e.what() << std::endl;
// 	}
// }


	/*	test errors PresidentialPardonForm */
{
	Bureaucrat				guy_26("number 26", 26);
	Bureaucrat				guy_25("number 25", 25);
	Bureaucrat				guy_5("number 5", 5);
	PresidentialPardonForm		presidential;

	try
	{
		presidential.beSigned(guy_26);
	}
	catch (GradeTooLowException &e)
	{
		std::cout << e.what() << std::endl;
	}

	try
	{
		presidential.execute(guy_25);
	}
	catch (GradeTooLowException &e)
	{
		std::cout << e.what() << std::endl;
	}
	presidential.beSigned(guy_25);

	try
	{
		presidential.execute(guy_25);
	}
	catch (GradeTooLowException &e)
	{
		std::cout << e.what() << std::endl;
	}
	
	try
	{
		presidential.execute(guy_5);
	}
	catch (GradeTooLowException &e)
	{	
		std::cout << e.what() << std::endl;
	}
}
}