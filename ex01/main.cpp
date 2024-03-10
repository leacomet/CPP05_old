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
#include "Form.hpp"

int main(void)
{
	/*	Same block ass ex00	(till STOOOP)	*/
// {
// 	Bureaucrat	Jean;
// 	Bureaucrat	dopple(Jean);

// 	std::cout << "grade : " << Jean << std::endl;
// 	std::cout << "grade : " << dopple << std::endl;
// 	std::cout << std::endl;

// 	for (int i = 0; i < 149; i++)
// 		dopple.increment();
// 	std::cout << "Dopple new grade after 149 increments : " << dopple.getGrade() << std::endl;
// 	dopple.decrement();
// 	dopple.decrement();
// 	std::cout << "Dopple new grade after 2 decrements : " << dopple.getGrade() << std::endl;
// 	std::cout << std::endl << std::endl;
// }
// {
// /*	test throw error	*/
// 	try
// 	{
// 		Bureaucrat	Jean("Bob", 151);
// 		Bureaucrat	Bob("Jean", 0);
// 	}
// 	catch (GradeTooHighException &e)
// 	{
// 		std::cout << e.what() << std::endl;
// 	}
// 	catch (GradeTooLowException &e)
// 	{
// 		std::cout << e.what() << std::endl;
// 	}
// }
// {
// 	Bureaucrat	BOB("Jean", 1);
// 	Bureaucrat	Jean("BOB", 150);
// 	try
// 	{
// 		Jean.decrement();
// 		BOB.increment();
// 	}
// 	catch(GradeTooLowException &e)
// 	{
// 		std::cout << e.what() << std::endl;
// 	}
// 	catch(GradeTooHighException &e)
// 	{
// 		std::cout << e.what() << std::endl;
// 	}
// }
/*	STOOOOOOOOOOOOOOOOOOOOOOOOOOP !	*/



/*	New Tests	*/
{
	/*	Bureaucrat	*/
	Bureaucrat	Jean_Baptiste;
	Bureaucrat	Jean_Marc(Jean_Baptiste);
	Bureaucrat	Jean_Timeo = Jean_Marc;
	Bureaucrat	Jean_Mich("JEAN", 5);

	std::cout << Jean_Baptiste << std::endl;
	std::cout << Jean_Marc << std::endl;
	std::cout << Jean_Timeo << std::endl;
	std::cout << Jean_Mich << std::endl << std::endl;

	/*	Form	*/
	Form	Anne_Marie;
	Form	Anne_Sophie = Anne_Marie;
	Form	Anne_Lise(Anne_Marie);
	Form	Anne_Anne("ANNE", 3, 3);
	Form	Anne_Cheval("ANNE", 3, 3);


	std::cout << Anne_Marie << std::endl;
	std::cout << Anne_Sophie << std::endl;
	std::cout << Anne_Lise << std::endl << std::endl;

	/*	there is accessors	*/
	std::cout << "Anne_Lise accessors things" << std::endl;
	std::cout << Anne_Lise.get_name() << std::endl;
	std::cout << Anne_Lise.get_signature() << std::endl;
	std::cout << Anne_Lise.get_sign_grade() << std::endl;
	std::cout << Anne_Lise.get_exec_grade() << std::endl << std::endl;

	/*	besigned function	*/
	Anne_Lise.beSigned(Jean_Mich);
	std::cout << Anne_Lise;
	Anne_Lise.beSigned(Jean_Mich);
	try
	{
		Anne_Anne.beSigned(Jean_Mich);
	}
	catch(GradeTooLowException &e)
	{
		std::cout << e.what() << std::endl;
	}
	catch(GradeTooHighException &e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << std::endl;


	/*	signform function	*/
	Anne_Marie.beSigned(Jean_Mich);
	std::cout << Anne_Marie;
	Anne_Marie.beSigned(Jean_Mich);
	try
	{
		Jean_Mich.signForm(Anne_Cheval);
	}
	catch(GradeTooLowException &e)
	{
		std::cout << e.what() << std::endl;
	}
	catch(GradeTooHighException &e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << std::endl;
}
}
